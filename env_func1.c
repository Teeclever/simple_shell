#include "main.h"

/**
 * _getenv - Get the value of an environment variable.
 * @name: The name of the environment variable.
 * Return: A pointer to the value of the environment
 * or NULL.
 */

char *_getenv(const char *name)
{
	int i, len;
	char **env;
	char *value;

	if (!name)
		return (NULL); /* invalid input, name is NULL */

	env = environ;

	for (i = 0; env[i]; i++)
	{

		for (len = 0; env[i][len] != '='; len++)
			;

		if (strncmp_made(name, env[i], len) == 0)
		{

			value = &env[i][len + 1];
			return (value);
		}
	}

	return (NULL);
}
