#include "main.h"

/**
 * _strdup - a function that duplicatin string
 * @str: sring to be duplicated
 * Return: the duplicated string
 */


char *_strdup(const char *str)
{
	size_t len;
	char *new_str;

	len = lenstr(str) + 1;
	new_str = (char *)malloc(len);
	if (new_str == NULL)
	{
		perror("Error on allocation");
		exit(98);
	}
	cpystr(new_str, str);
	return (new_str);
}

/**
 * lenstr - A function that returns the lenght of a string
 * @str: argument passed
 * Return: the length
 */

int lenstr(const char *str)
{
	int len = 0;

	while (str[len] != '\0')
	{
		len++;
	}

	return (len);
}

/**
 * cpystr - a function that copies a string
 * @str: the the string destination
 * @src: the source
 *
 * Return: distination
 */

char *cpystr(char *str, const char *src)
{
	int i = 0;

	if (str == src || src == 0)
		return  (str);
	while (src[i])
	{
		str[i] = src[i];
		i++;
	}
	str[i] = 0;
	return (str);
}

/**
 * cmpstr - A function that performs comparison of two strings
 * @st1: first string
 * @st2: second string
 *
 * Return: its returns negative if s1 < s2, positive if s1 > s2
 */

int cmpstr(const char *st1, const char *st2)
{
	int i;

	for (i = 0; st1[i] || st2[i]; i++)
	{
		if (st1[i] != st2[i])
		{
			return (st1[i] - st2[i]);
		}
	}
	return (0);
}
