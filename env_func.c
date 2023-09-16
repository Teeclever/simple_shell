#include "main.h"

/**
 * _locationevn - is a function the describe to the path variable
 * @command: takes in agument been type by the user
 *
 * Return: its returns the path location
 */

char *_locationevn(char *command)
{
	char *path, *full_path, *path_env = _getenv("PATH");
	size_t path_len, full_path_len, command_len;

	if (path_env == NULL)
	{
		return (NULL);
	}

	path = strtok(path_env, ":");
	while (path != NULL)
	{
		path_len = lenstr(path);
		command_len = lenstr(command);
		full_path_len = path_len + command_len + 2;

		full_path = malloc(full_path_len);
		if (full_path == NULL)
		{
			perror("malloc");
			return (NULL);
		}

		cpystr(full_path, path);
		full_path[path_len] = '/';
	cpystr(full_path + path_len + 1, command);

		if (access(full_path, X_OK) == 0)
		{
			return (full_path);
		}

		free(full_path);
		path = strtok(NULL, ":");
	}
	return (NULL);
}
