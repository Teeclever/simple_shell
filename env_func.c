#include "main.h"

/**
 * _locationevn - is a function the describe to the path variable
 * @args_command: takes in agument been type by the user
 *
 * Return: its returns the path location
 */

char *_locationevn(char *args_command)
{
	char *pathenv;
	char *copypath;
	char *token;
	char *pathfile;
	int length;
	int len2;
	struct stat ptr;

	pathenv = _getenv("PATH");
	if (pathenv)
	{
		copypath = _strdup(pathenv);
		length = lenstr(args_command);
		token = strtok(copypath, ":");
		while (token != NULL)
		{
			len2 = strlen(token);
			pathfile = malloc(length + len2 + 2);
			cpystr(pathfile, token);
			catstr(pathfile, "/");
			catstr(pathfile, args_command);
			catstr(pathfile, "\0");

			if (stat(pathfile, &ptr) == 0)
			{
				free(copypath);
				return (pathfile);
			}
			else
			{
				free(pathfile);
				token = strtok(NULL, ":");
			}
		}
		free(copypath);
		if (stat(args_command, &ptr) == 0)
			return (args_command);
		return (NULL);
	}
	return (NULL);
}
