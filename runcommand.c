#include "shell.h"

/**
 * exe - Execute a command along with its arguments in a child process.
 *
 * @args: The command and its arguments.
 * @prgrm: The name of the program.
 *
 * Return: 0 if successful, otherwise 1.
 */
int exe(char *const args[], char *prgrm)
{
	pid_t child_pid = fork();
	int status;

	if (child_pid == -1)
	{
		perror("Fork: execution failed");
		return (1);
	}

	if (child_pid == 0)
	{
		if (handle_path(args) == 0)
		{
			int n = 0;

			n += write(2, prgrm, lenofstr(prgrm));
			n += write(2, ": ", 2);
			n += write(2, args[0], lenofstr(args[0]));
			n += write(2, ": not found\n", 12);

			if (n < 0)
			{
				_exit(EXIT_FAILURE);
			}
			_exit(EXIT_FAILURE);
		}
	}
	else
	{
		pid_t waitpid_result;

		waitpid_result = waitpid(child_pid, &status, 0);

		if (waitpid_result == -1)
		{
			perror("waitpid failed");
		}
	}

	return (0);
}
