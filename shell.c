#include "shell.h"

/**
* main - simple shell program
*
* Description: an implementation of a simple shell CLI
* Return: 0 (success)
*/

int main(void)
{

	if (isatty(STDIN_FILENO))
		interactive_sh();
	else
		non_interactive_sh();

	return (0);
}
