#include "shell.h"

/**
* _execvpe - a function that the current process image
* with a new process image
* @cmd: the command to be executed
* @argv: the is an array of strings that represent the argument list,
* the first arg should point to the cmd and the last arg points to NULL
* @envp: The environment of the caller is specified via the argument envp.
*
* Description: this function works like execvpe, man execvpe for more...
* Return: The exec() functions return only if an error has occurred.
* The return value is -1, and errno is set to indicate the error.
*/

int _execvpe(const char *cmd, char *argv[], char *const envp[])
{
	char *path, *token, *executable;
	size_t cmd_len, token_len, e_len;

	/* pass the content of PATH to var path */
	path = getenv("PATH");
	if (path == NULL)
	{
		perror("getenv");
		exit(EXIT_FAILURE);
	}
	cmd_len = _strlen(cmd);
	/* path is a colon separated str, tokenize each str */
	token = _strtok(path, ":");

	while (token != NULL)
	{
		/* try executing cmd without path */
		execve(cmd, argv, envp);

		token_len = _strlen(token);
		/* merge path with cmd */
		e_len = (token_len + cmd_len + 2) * sizeof(char);
		executable = malloc((e_len) * sizeof(char));
		if (executable == NULL)
		{
			perror("malloc");
			exit(EXIT_FAILURE);
		}
		snprintf(executable, e_len, "%s/%s", token, cmd);

		/* try executing cmd with path */
		execve(executable, argv, envp);

		/* if the code reaches here, it means execve failed, try next path */
		token = _strtok(NULL, ":");
	}
	/* if the code reaches here, that means we have exhausted path */
	/*free(executable);*/
	perror("execve");
	exit(EXIT_FAILURE);
}
