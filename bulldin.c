#include "main.h"
/**
 * env_execute - A function that execute the environment variable
 * Return: nothing
 *
 */

void env_execute(void)
{
	char **envn = environ;

	while (*envn)
	{
		write(STDOUT_FILENO, *envn, lenstr(*envn));
		write(STDOUT_FILENO, "\n", 1);
		envn++;
	}
}
