#include "main.h"

/**
 * tokenalize - a fuction the split string into two
 * @str: the string to be tokenalized
 * @delim: what to use when slipting
 * Return: returns the slipted string
 */

char **tokenalize(char *str, const char *delim)
{
	char *strtokcpy = _strdup(str);
	int countok = 0, i;
	char **argstr = NULL;
	char *strtoken;

	strtoken = strtok(str, delim);
	while (strtoken != NULL)
	{
		countok++;
		strtoken = strtok(NULL, delim);
	}
	argstr = (char **)malloc(sizeof(char *) * (countok + 1));
	if (argstr == NULL)
	{
		perror("allocated memory failled");
		exit(98);
	}
	strtoken = strtok(strtokcpy, delim);
	for (i = 0; strtoken != NULL; i++)
	{
		argstr[i] = _strdup(strtoken);
		strtoken = strtok(NULL, delim);
	}
	argstr[countok] = NULL;
	free(strtokcpy);
	return (argstr);
}
