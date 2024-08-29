#include "shell.h"

/**
* is_builtin - a function to check if the command entered is a builtin
* @args: Array of command arguments
*
* Return: 99 (a builtin was encounterd), otherwise 0
*/

int is_builtin(char **args)
{
	if (__exit(args) != 0)
		return (99);

	if (__env(args) == 0)
		return (99);

	if (is_setenv(args) != 0)
		return (99);

	return (0);
}


/**
* _unsetenv - a function that deletes the variable name from the environment
* @name: the name of the var to be deleted
*
* Return: 0 (success)
*/

int _unsetenv(char *name)
{
	int environ_len = 0, i, j;
	char **new_environ;

	/* calculate length of environ array */
	while (environ[environ_len])
		environ_len++;

	/* allocate memory for new environ with one less var(last element is null) */
	new_environ = malloc(environ_len * sizeof(char *));
	if (new_environ == NULL)
	{
		perror("malloc");
		return (-1);
	}

	/* copy old environ to new_environ excluding the unset var */
	for (i = 0, j = 0; i < environ_len; i++)
	{
		if (_strncmp(environ[i], name, _strlen(name)) != 0)
		{
			new_environ[j] = _strdup(environ[i]);
			if (new_environ[j] == NULL)
			{
				perror("malloc");
				return (-1);
			}
			j++;
		}
	}
	new_environ[j] = NULL;
	environ = new_environ;

	return (0);

}
