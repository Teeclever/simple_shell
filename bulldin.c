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

/**
  * handle_command - A function that handle command pass form shell
  * @strline: the getline argument pass to execute
  */

void handle_command(char *strline)
	{
	char **argstr = NULL, *pathcommand = NULL;
	int exit_status;

	if (strline[0] != '\0')
	{
		argstr = tokenalize(strline, " \n");
		if (!argstr)
		{
			perror("Error tokenizing command");
			return;
		}

		if (cmpstr(strline, "exit") == 0)
		{
		if (argstr[1])
		{	exit_status = atoi(argstr[1]);
			free_str(argstr);
			exit(exit_status);
		}
		else
		{	free_str(argstr);
			exit(0);
		}
		}

		if (cmpstr(strline, "env") == 0)
		{	env_execute();
			free_str(argstr);
			return;
		}
		pathcommand = _locationevn(argstr[0]);
		if (pathcommand == NULL)
		{	perror("Command not found");
			free_str(argstr);
		}
		else
		{	fork_command(argstr);
			free_str(argstr);
		}
		}
}
