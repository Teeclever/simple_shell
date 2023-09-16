#include "shell.h"

/**
 * prompt - Display the shell prompt.
 *
 * This function displays the shell prompt ('$ ') to the standard output if the
 * input is being read from a terminal. It flushes the output buffer to ensure
 * the prompt is immediately visible.
 */
void prompt(void)
{
	if (isatty(STDIN_FILENO) == 1) /* check if the input is from a terminal */
	{
		write(STDOUT_FILENO, "$ ", 2); /* display the shell prompt */
		fflush(stdout);                /* flush the output buffer */
	}
}
