#include "shell.h"

/**
 * input - Receive user input.
 *
 * Return: The user's command if successful, otherwise NULL.
 */
char *input(void)
{
	char *command = NULL;
	size_t bufsize = 0;
	ssize_t n;

	while ((n = getline(&command, &bufsize, stdin)) != -1)
	{
		if (n == 1)
		{
			free(command);
			return (NULL);
		}

		if (command[n - 1] == '\n')
		{
			command[n - 1] = '\0';
			break;
		}
	}

	if (n == -1 && bufsize == 0)
	{
		free(command);
		return (NULL);
	}
	if (n == -1)
	{
		free(command);
		return (NULL);
	}

	return (command);
}
