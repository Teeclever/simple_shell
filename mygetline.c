#include "main.h"

/**
 * made_getline - A program that execute just like getline
 * @line: the first argument passed in.
 * @ptr: the second argument passed in
 * Return: line read
 */

ssize_t made_getline(char *line, size_t ptr)
{
	static char strline_buffer[BUFFER_RANGE];
	char *braking_point = NULL;
	static size_t size_buff;
	static size_t ptrbuff;
	ssize_t sizeline = 0;
	size_t length, copy_path;

	while (1)
	{
		if (ptrbuff >= size_buff)
		{
			size_buff = read(STDIN_FILENO, strline_buffer, BUFFER_RANGE);
			if (size_buff <= 0)
				return (-1);
			ptrbuff = 0;
		}
		braking_point = memchr(strline_buffer + ptrbuff, '\n', size_buff - ptrbuff);
		if (braking_point)
		{
			length = braking_point - (strline_buffer + ptrbuff);
			if (length < ptr - 1)
			{
				memcpy(line, strline_buffer + ptrbuff, length);
				line[length] = '\0';
				ptrbuff = braking_point - strline_buffer + 1;
				sizeline += length + 1;
				return (sizeline);
			}
		}
		copy_path = (size_buff - ptrbuff < ptr - 1) ? size_buff - ptrbuff : ptr - 1;
		memcpy(line, strline_buffer + ptrbuff, copy_path);
		ptrbuff += copy_path;
		line += copy_path;
		sizeline += copy_path;
		if (copy_path < ptr - 1)
		{
			*line = '\0';
			return (sizeline);
		}
	}
}
