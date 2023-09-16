#include "shell.h"

/**
 * get_path - Get the full path of a command.
 * @command: The command for which to find the full path.
 *
 * This function searches for the full path of a given command within the
 * system PATH environment variable. It constructs the full path by
 * concatenating the directory paths from the PATH variable and the
 * command name, and checks if the constructed path is executable.
 *
 * Return: A dynamically allocated string containing the full path of the
 * command if found, otherwise NULL.
 */
char *get_path(char *command)
{
	char *path, *full_path, *path_env = _getenv("PATH");
	size_t path_len, full_path_len, command_len;

	if (path_env == NULL)
	{
		return (NULL); /* PATH environment variable not set */
	}

	path = strtok(path_env, ":"); /* tokenize the PATH environment variable */
	while (path != NULL)
	{
		path_len = _strlen(path); /* length of the current path */
		command_len = _strlen(command); /* length of the command */
		/* extra space for '/' and '\0' */
		full_path_len = path_len + command_len + 2;

		full_path = malloc(full_path_len); /* allocate memory for full path */
		if (full_path == NULL)
		{
			perror("malloc");
			return (NULL); /* memory allocation error */
		}

		_strcpy(full_path, path); /* copy the directory path */
		full_path[path_len] = '/'; /* add a '/' separator */
		_strcpy(full_path + path_len + 1, command); /* append the command name */

		if (access(full_path, X_OK) == 0)
		{
			return (full_path); /* return the full path if executable */
		}

		free(full_path); /* free memory if path not executable */
		path = strtok(NULL, ":"); /* move to next directory in PATH */
	}
	return (NULL); /* command not found in any directory */
}

