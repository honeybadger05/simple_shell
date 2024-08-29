#include "shell.h"

/**
 * run_shell - takes the tokenized command,
 * then execute it.
 * @command: the tokenized to be executed.
 * @prgrm: the name of the shell program.
 *
 */

void run_shell(const char *command, char *prgrm)
{
	char **args;
	int count = 0;
	int status;

	if (command == NULL)
	{
		return;
	}

	args = malloc(10 * sizeof(char *));
	if (args == NULL)
	{
		return;
	}
	count = _split(command, args);
	if (count == 0)
	{
		free(args);
		return;
	}
	else if (cmpnstr(args[0], "exit", 4) == 0)
	{
		free(*args);
		free(args);
		exit(0);
	}
	else if (cmpnstr(args[0], "env", 3) == 0)
	{
		print_env();
	}

	status = exe(args, prgrm);

	if (status == -1)
	{
		perror(args[0]);
		return;
	}

	free(args);
}
