#include "shell.h"

/**
 * main - Entry point of the shell program.
 *
 * This function implements the main loop of the shell, where it continuously
 * prompts the user for input, reads input, processes commands, and executes
 * them. It also handles the "exit" and "env" commands to,
 * exit the shell gracefully or to print out the environments.
 *
 * Return: Always returns 0.
 */
int main(void)
{
	char *input = NULL;
	size_t input_size = 0;
	ssize_t read_size;
	int result;

	while (1)
	{
		prompt(); /* display the shell prompt */
		read_size = getline(&input, &input_size, stdin); /* read user input */
		if (read_size == -1)
		{
			free(input);
			return (0); /* exit loop and program on input failure */
		}
		if (input[read_size - 1] == '\n')
			input[read_size - 1] = '\0'; /* remove trailing newline */
		/* check if the user wants to exit the shell */
		if (_strncmp(input, "exit", 4) == 0)
		{
			free(input);
			input = NULL;
			input_size = 0;
			exit(EXIT_SUCCESS); /* exit the shell gracefully */
		}
		/* check if the user wants to print environment variables */
		if (_strcmp(_strtrim(input), "env") == 0)
		{
			print_environment(); /* print environment variables */
			continue;
		}
		/* Execute the command and handle errors */
		if (read_size > 1)
		{
			result = execute_command(_strtrim(input));
			if (result == -1)
				break;
		}
	}
	free(input);
	return (0);
}
