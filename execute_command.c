#include "main.h"

/**
 * execute_command - A function Execute arguments in a child process.
 * @command_with_args: The command with its arguments.
 *
 * Return: 0 on success, -1 on failure.
 */
int execute_command(char *command_with_args)
{
	pid_t child_pid;
	int status, arg_count = 0;
	char *token, *args[MAX_INPUT_LEN / 2 + 2];

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("fork");
		return (-1);
	}
	if (child_pid == 0)
	{
		token = strtok(command_with_args, " ");
		while (token != NULL)
		{
			args[arg_count++] = token;
			token = strtok(NULL, " ");
		}
		args[arg_count] = NULL;
		/* call execute child process command */
		execute_child_process(args[0], args);
	}
	else
	{
		wait(&status);
	}
	return (0);
}

/**
 * execute_child_process - A function execute a command in a child process
 * @command: The command
 * @args: The arguments
 */
void execute_child_process(char *command, char *args[])
{
	char *path = _locationevn(command);

	if (path != NULL)
	{
		if (execve(path, args, NULL) == -1)
		{
			perror("execve");
			_exit(EXIT_FAILURE);
		}
	}
	else if (access(command, X_OK) == 0)
	{
		if (execve(command, args, NULL) == -1)
		{
			perror("execve");
			_exit(EXIT_FAILURE);
		}
	}
	else
	{
		perror("./hsh");
		_exit(EXIT_FAILURE);
	}
}
