#include "main.h"

/**
 * strncmp_made - Function that takes three argument and compare
 * @st1: first args a string
 * @st2: second args a string
 * @i: third arg an int
 * Return: 0 on succes
 */

int strncmp_made(const char *st1, const char *st2, size_t i)
{
	for (; i > 0; i--)
	{
		if (*st1 != *st2)
		{
			return (*st1 - *st2);
		}
		if (*st1 == '\0')
		{
			return (0);
		}
		st1++;
		st2++;
	}
	return (0);
}

/**
 * catstr - A function that  concatenates two strings
 * @str: the string destination part
 * @src: the source
 *
 * Return: a pointer to destination part
 */

char *catstr(char *str, char *src)
{
	char *point = str;

	while  (*str)
		str++;
	while (*src)
		*str++ = *src++;
	*str = *src;
	return (point);
}
