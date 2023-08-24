#include "main.h"

/**
 * exece_fun - a function the execute command
 * @argstr: takes in command
 * Return: void
 */

void exece_fun(char **argstr)
{
	char *pathcommand = NULL;
	char *first_args = NULL;

	first_args = argstr[0];
	pathcommand = _locationevn(first_args);

	if (execve(pathcommand, argstr, NULL) == -1)
	{
		perror("command not found");
		exit(1);
	}
}
