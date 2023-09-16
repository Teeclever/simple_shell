#include "shell.h"

/**
 * _strlen - Calculates the length of a null-terminated string.
 * @s: Pointer to the input string.
 *
 * Return: Length of the string.
 */
int _strlen(char *s)
{
	int i = 0;

	while (*s)
	{
		s++;
		i++;
	}

	return (i);
}

/**
 * _strlen_const - Calculates the length of a null-terminated string.
 * @s: Pointer to the input string.
 *
 * Return: Length of the string.
 */
int _strlen_const(const char *s)
{
	int i = 0;

	while (s[i] != '\0')
	{
		i++;
	}

	return (i);
}

/**
 * _strdup - Creates a duplicate of the input string.
 *
 * This function allocates memory for a new string and copies the contents of
 * the source string into it.
 *
 * @src: Pointer to the source string.
 *
 * Return: Pointer to the newly allocated duplicate string.
 */
char *_strdup(const char *src)
{
	int len, i;
	char *dst;

	if (src == NULL)
		return (NULL);

	len = _strlen_const(src);
	if (len < 0)
		return (NULL);

	len++;
	dst = malloc((len) * sizeof(char));
	if (dst == NULL)
		return (NULL);

	for (i = 0; i < len; i++)
		dst[i] = src[i];

	dst[i - 1] = '\0';
	return (dst);
}

/**
 * _strcat - concatenate two strings
 * @dest: char string to be concatenated to.
 * @src: char string
 * Return: concatenated string dest
 */
char *_strcat(char *dest, char *src)
{
	int i = 0;
	int j = 0;

	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}
/**
 * _strcmp - compare two strings
 * @s1: string value 1
 * @s2: string value 2
 *
 * Return: interger value
 */

int _strcmp(char *s1, char *s2)
{
	int res;

	res = strcmp(s1, s2);

	if (res == 0)
		return (res);

	else if (res < 0)
		return (res);
	else
		return (res);
}
