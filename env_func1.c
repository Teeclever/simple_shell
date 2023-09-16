#include "main.h"

/**
 * _getenv - A function that get environment varables
 * @str: an argument of the path
 * Return: the path
 */

char *_getenv(const char *str)
{
	int length = lenstr(str);
	char **envn = NULL;

	envn =  environ;
	while (*envn != NULL)
	{
		if (strncmp_made(str, *envn, length) == 0 && (*envn)[length] == '=')
		{
			return (&(*envn)[length + 1]);
		}
		envn++;
	}
	return (NULL);
}
