#include "shell.h"

/**
 * _strtrim - Trim leading and trailing whitespace from a string.
 * @str: The string to trim.
 *
 * This function trims leading and trailing whitespace characters (space, tab,
 * and newline) from the given string. It modifies the string in place by
 * moving the end pointer back to remove trailing whitespace and adding a null
 * terminator to the end.
 *
 * Return: A pointer to the trimmed string.
 */
char *_strtrim(char *str)
{
	char *end;

	/* skip leading whitespace */
	while (*str && (*str == ' ' || *str == '\t' || *str == '\n'))
	{
		str++;
	}

	if (*str == '\0')
	{
		return (str); /* return if the entire string is whitespace */
	}

	/* move end pointer back to remove trailing whitespace */
	end = str + _strlen(str) - 1;
	while (end > str && (*end == ' ' || *end == '\t' || *end == '\n'))
	{
		end--;
	}
	*(end + 1) = '\0'; /* null-terminate the trimmed string */

	return (str); /* return a pointer to the trimmed string */
}

