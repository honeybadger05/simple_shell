#include "shell.h"

/**
* __exit - a function that exits from process
* @args: Array of command arguments
*
* Return: (1) if exit was entered
*/

int __exit(char **args)
{
	int status;
	char *error;

	if (_strcmp(args[0], "exit") == 0)
	{
		if (args[1] == NULL)
		{
			free(args[0]);
			free(args);
			exit(EXIT_SUCCESS);
		}

		if (args[2] != NULL)
		{
			error = "usage: exit status\n";
			write(2, error, _strlen(error));
			return (1);
		}
		status = atoi(args[1]);
		if (status == 0 && _strcmp(args[1], "0") != 0)
		{
			error = "invalid exit status\n";
			write(2, error, _strlen(error));
			return (1);
		}
		free(args[0]);
		free(args);
		exit(status);
	}
	return (0);
}


/**
* __env - a function that prints
* @args: Array of command arguments
*
* Return: 0 (success)
*/

int __env(char **args)
{
	char **env = environ;


	if ((_strcmp(args[0], "env") == 0) && (args[1] == NULL))
	{
		while (*env)
		{
			write(1, *env, _strlen(*env));
			write(1, "\n", 1);
			env++;
		}
		free(args[0]);
		free(args);
		return (0);
	}
	return (1);
}


/**
* _setenv - change or add an environment variable
* @name: name of the env var
* @value: value of the env var
* @overwrite: the ovewrite option
*
* Description: The setenv() function adds the variable name to the
* environment with the value value, if name does not already exist.
* If name does exist in the environment, then its value is changed to value
* if overwrite is nonzero;
* if overwrite is zero, then the value of name is  not
* changed  (and  setenv()  returns a success status).
* Return: 0 (success)
*/

int _setenv(const char *name, const char *value, int overwrite)
{
	char *env_name_value;
	int putenv_status;

	/* Error handling: name has to be in the correct format */
	if (name == NULL || name[0] == '\0' || _strchr(name, '=') != NULL)
		return (-1);

	/* if env var already exitst and overwrite is false */
	if (_getenv(name) != NULL && overwrite != 0)
		return (0);


	env_name_value = malloc(_strlen(name) + _strlen(value) + 2);
	if (env_name_value == NULL)
	{
		perror("malloc");
		return (-1);
	}

	/* write the name and value into env_name_value  */
	sprintf(env_name_value, "%s=%s", name, value);

	/* call putenv and save the return value in putenv_status  */
	putenv_status = _putenv(env_name_value);
	/* Error handling: */
	if (putenv_status != 0)
	{
		free(env_name_value);
		return  (-1);
	}
	free(env_name_value);
	return (0);
}


/**
* is_setenv - check if cmd is setenv and call setenv
* @args: Array of command arguments
*
* Return: 0 (success) otherwise -1.
*/

int is_setenv(char **args)
{
	char *error = "usage: setenv VARIABLE VALUE\n";

	if (_strcmp(args[0], "setenv") == 0)
	{
		if (args[1] == NULL || args[2] == NULL || args[3] != NULL)
		{
			write(2, error, _strlen(error));
			return (98);
		}

		if (_setenv(args[1], args[2], 1) == -1)
		{
			error = "setenv failed\n";
			write(2, error, _strlen(error));
			return (98);
		}
		free(args[0]);
		free(args);
		return (99);
	}
	if (_strcmp(args[0], "unsetenv") == 0)
	{
		if (args[1] == NULL || args[3] != NULL)
		{
			error = "usage: unsetenv VARIABLE\n";
			write(2, error, _strlen(error));
			return (98);
		}
		if (_unsetenv(args[1]) == -1)
		{
			error = "unsetenv failed\n";
			write(2, error, _strlen(error));
			return (98);
		}
		free(args[0]);
		free(args);
		return (99);
	}
	return (0);
}


/**
* _putenv - a function that replicates the putenv function
* @name_value: a string in the format NAME="VALUE" to be added to env
*
* Description: a function that prints the alphabet
* Return: 0 (success)
*/

int _putenv(char *name_value)
{
	int env_len = 0, i;
	char **new_environ;

	/* find length of environment array */
	while (environ[env_len])
		env_len++;

	/**
	 * allocate memory for new environ (+2 because of null pointer
	 * and new environ var
	 */
	new_environ = malloc((env_len + 2) * sizeof(char *));
	if (new_environ == NULL)
	{
		perror("malloc");
		return (-1);
	}

	/* Copy old environ to new_environ */
	for (i = 0; i < env_len; i++)
		new_environ[i] = _strdup(environ[i]);

	new_environ[env_len] = _strdup(name_value);
	new_environ[env_len + 1] = NULL;

	environ = new_environ;

	return (0);
}
