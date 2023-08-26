#include "main.h"
/**
 * env_execute - A function that execute the environment variable
 * Return: nothing void
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
			bultin_exit(argstr);
			return;
		}
		else
		{	free_str(argstr);
			exit(0);
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

/**
  * bultin_exit - a function that exit command
  * @argst: the argument
  */

void bultin_exit(char *argst[])
{
	char *line =argst[1];
	size_t i;
	int exit_status = 0;

	if (line != NULL)
	{
		for (i = 0; i < strlen(line); i++)
		{
			if (line[i] < '0' || line[i] > '9')
			{
			fprintf(stderr, "invalid exit sytatus: %s\n", line);
			exit(EXIT_FAILURE);
			}
	
		exit_status = exit_status *10 + (line[i] - '0');
		}
		exit_status = 0;
	}
	else
	{
		exit(EXIT_SUCCESS);
	}
}
