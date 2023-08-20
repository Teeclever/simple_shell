#include "main.h"

/**
 * _getenv - A function that get envorn varables
 * @str: an argument of the path
 * Return: the path
 */

char *_getenv(const char *str)
{
	extern char **environ;
	int length = lenstr(str);
	char **envn = NULL;

	envn =  environ;
	while (*envn != NULL)
	{
		if (strncmp_made(str, *envn, length) == 0 && (*env)[length] == '=')
		{
			return &(*envn)[length + 1];
		}
		envn++;
	}
	return NULL;
}
