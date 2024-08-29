#include "shell.h"

/**
* _getenv - get an environment variable
* @name: name of env var
*
* Return: pointer to the value in the environment, or NULL if there is no match
*/

char *_getenv(const char *name)
{
	/* declare env to be an arrray of env variables (char *) */
	char **env = environ, *env_var, *value;

	/* Error handling: name has to be valid */
	if (name == NULL || name[0] == '\0')
		return (NULL);

	/* go through all environ vars */
	while (*env)
	{
		/* tokenize each one with the delim "=" */
		env_var = _strtok(_strdup(*env), "=");
		if (env_var == NULL)
			return (NULL);

		/* check if name matches the first token (variable name) */
		if (_strcmp(env_var, name) == 0)
		{
			value = _strtok(NULL, "=");
			free(env_var);
			return (value);
		}
		free(env_var);
		env++;
	}

	return (NULL);
}
