#include "main.h"

/**
  * prompt - command that print out a promt
  */
void prompt(void)
{
	if (isatty(STDIN_FILENO) == 1)
	{
		write(STDOUT_FILENO, "$cisfun ", 8);
		fflush(stdout);
	}
}

/**
  * main - A project that display command line prompt and takes
  * args and execute the command been typed by the user
  *
  * Return: 0 on success
  */

int main(void)
{
	char strline[100];
	ssize_t size;

	while (1)
	{
	prompt();

	size = made_getline(strline, sizeof(strline));

	if (size == -1)
	{
		break;
	}

	if (strline[size - 1] == '\n')
		strline[size - 1] = '\0';

	handle_command(strline);
	}
	return (0);
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
