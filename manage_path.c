#include "shell.h"

/**
 * print_env - Print the current environment variables using write.
 */
void print_env(void)
{
	int i = 0, j;
	char *env_copy[4096];

	while (environ[i] != NULL)
	{
		env_copy[i] = environ[i];
		i++;
	}
	env_copy[i] = NULL;

	for (i = 0; env_copy[i] != NULL; i++)
	{
		for (j = i + 1; env_copy[j] != NULL; j++)
		{
			if (cmpnstr(env_copy[i], env_copy[j], lenofstr(env_copy[i])) > 0)
			{
				char *temp = env_copy[i];

				env_copy[i] = env_copy[j];
				env_copy[j] = temp;
			}
		}
	}
	i = 0;
	while (env_copy[i] != NULL)
	{
		size_t len = lenofstr(env_copy[i]);

		write(STDOUT_FILENO, env_copy[i], len);
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
}

/**
 * _getenv - Get an environment variable.
 * @name: Variable to look for
 *
 * Return: The environment variable, if not found NULL
 */

char *_getenv(const char *name)
{
	int env_index = 0, char_index, count = 0, length;
	char *copy = (char *)name;

	if (name == NULL || !name[0])
		return (NULL);

	length = lenofstr(copy);
	while (*(environ + env_index))
	{
		char_index = 0;
		while (*(*(environ + env_index) + char_index) != '=')
		{
			if (*(*(environ + env_index) + char_index) == name[char_index])
				count++;
			char_index++;
		}
		if (count == length)
		{
			char_index++;
			return (*(environ + env_index) + char_index);
		}
		env_index++;
		count = 0;
	}
	return (NULL);
}

/**
 * check_cur_dir - Check if the command
 * exists in the current directory.
 *
 * @command: The command to be checked.
 * @args: The command and its arguments.
 *
 * Return: 1 if the command was found, 0 if not.
 */
int check_cur_dir(const char *command, char *const args[])
{
	if (access(command, X_OK) == 0)
	{
		if (execve(command, args, environ) == -1)
		{
			perror("execve");
			_exit(EXIT_FAILURE);
		}
		return (1);
	}
	return (0);
}

/**
 * search_in_path - Search for the command
 * in the directories listed in PATH.
 *
 * @args: The command and its arguments.
 *
 * Return: 1 if the command was found, 0 if not.
 */
int search_in_path(char *const args[])
{
	char *path = _getenv("PATH");
	char *path_copy = dupstr(path);
	char *token = strtok(path_copy, ":");
	char cmp[1024];

	while (token != NULL)
	{
		size_t path_len = lenofstr(token);
		size_t command_len = lenofstr(args[0]);

		if (path_len + command_len + 2 > sizeof(cmp))
		{
			perror("Error: Command path is too long");
			free(path_copy);
			return (0);
		}

		cpynstr(cmp, token, sizeof(cmp));
		catnstr(cmp, "/", sizeof(cmp) - lenofstr(cmp) - 1);
		catnstr(cmp, args[0], sizeof(cmp) - lenofstr(cmp) - 1);

		if (check_cur_dir(cmp, args))
		{

			return (1);
		}

		token = strtok(NULL, ":");
	}


	free(path_copy);
	return (0);
}

/**
 * handle_path - Check if the command
 * exists in any directory in the PATH.
 *
 * @args: The command to be executed along with its arguments.
 *
 * Return: 1 if the command was found, 0 if not.
 */
int handle_path(char *const args[])
{
	if (chrstr(args[0], '/') != NULL)
	{
		return (check_cur_dir(args[0], args));
	}
	else
	{
		return (search_in_path(args));
	}
}
