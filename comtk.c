#include "shell.h"

/**
 * _split - Split the input into the command and its arguments.
 *
 * @command: The input to be split.
 * @args: The array to store the arguments.
 *
 * Return: The total count of commands and arguments.
 */
int _split(const char *command, char *args[])
{
	const char delimiter[] = " \t\n";
	char *token = strtok((char *)command, delimiter);
	int count = 0;

	while (token != NULL)
	{
		args[count] = token;
		token = strtok(NULL, delimiter);
		count++;
	}
	args[count] = NULL;

	return (count);
}
	return (count);
}
