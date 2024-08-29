#include "shell.h"

/**
 * main - Entry point of the shell program.
 * @ac: Number of arguments passed to the program.
 * @av: List storing arguments to the program.
 *
 * Return: 0 on success.
 **/
int main(int ac, char *av[])
{
	int is_interactive;
	char prompt[] = "$ ";
	char *command = NULL;

	(void)ac;
	(void)av;

	is_interactive = isatty(STDIN_FILENO);

	if (is_interactive)
	{
		while (1)
		{
			write(STDOUT_FILENO, prompt, sizeof(prompt));
			command = input();
			run_shell(command, av[0]);
			free(command);
		}
	}
	else
	{
		command = input();
		if (command != NULL)
		{
			run_shell(command, av[0]);
			free(command);
		}
	}

	return (0);
}
