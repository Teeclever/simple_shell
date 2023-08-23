#include "main.h"

/**
  * main - A project that display command line prompt and takes
  * args and execute the command been typed by the user
  *
  * Return: 0 on success
  */

int main(void)
{
	char *strline = NULL, *pathcommand = NULL, **argstr;
	size_t n = 0;
	ssize_t size;
	bool exinput = false;

	while (1 && !exinput)
	{
		if (isatty(STDIN_FILENO) == 0)
			exinput = true;
		write(STDIN_FILENO, "#cisfun$ ", 10);
		size = getline(&strline, &n, stdin);
		if (size == -1)
		{	perror("Eof: Exiting shell.....\n");
			break;
		}
		if (strline[size - 1] == '\n')
			strline[size - 1] = '\0';
		if (strline[0] != '\0')
		{
			if (cmpstr(strline, "exit") == 0)
				break;
			if (cmpstr(strline, "env") == 0)
			{
				env_execute();
				continue;
			}
			argstr = tokenalize(strline, " \n");
			pathcommand = _locationevn(argstr[0]);
			if (pathcommand == NULL)
			{
				perror("Command not found");
				free_str(argstr);
				continue;
			}
				fork_command(argstr);
				free_str(argstr);
		}
	}
	free(strline);
	return (0);
}

/**
  * fork_command - a function that duplicate process
  * @argstr: take in argument
  */


void fork_command(char **argstr)
{
	pid_t child = fork();

	if (child == -1)
	{
		perror("error the process fail");
		exit(1);
	}
	if (child == 0)
	{
		exece_fun(argstr);
	}
	else
	{
		wait(NULL);
	}

}

/**
  * free_str - A function that free allocated space
  * @argstr: argument
  */

void free_str(char **argstr)
{
	int i;

	for (i = 0; argstr[i] != NULL; i++)
	{
		free(argstr[i]);
	}
	free(argstr);
}
