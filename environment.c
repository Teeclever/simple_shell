#include "shell.h"

/**
 * print_environment - Print the environment variables.
 *
 * This function prints the environment variables to the standard output, with
 * each variable followed by a newline character.
 */
void print_environment(void)
{
	int i;
	char **env = environ;

	for (i = 0; env[i]; i++)
	{
		/* print each environment variables */
		write(STDOUT_FILENO, env[i], _strlen(env[i]));
		write(STDOUT_FILENO, "\n", 1);
	}
}
