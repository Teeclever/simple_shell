#include "main.h"

/**
* made_getline - a function that excute getline function
* @source: the source is freching from
* Return: it return the char
*/

char *made_getline(FILE *source)
{
	char *strline = NULL;
	size_t size = 0;
	ssize_t strnum;

	strnum = getline(&strline, &size, source);

	if (strnum == -1)
	{
		free(strline);
		return (NULL);
	}

		if ((strnum > 0) && (strline[strnum - 1] == '\n'))
			strline[strnum - 1] = '\0';

	return (strline);

}

/**
  * exit_handle - a programm that handle the exit argument
  * @strlin: comman input
  */

void exit_handle(char *strlin)
{
	char *token = NULL;
	int status_exit;

	token = strtok(strlin, " ");

	token = strtok(NULL, " ");
	if (token != NULL)
	{
		status_exit = atoi(token);
		exit(status_exit);
	}
	else
	{
		exit(0);
	}
}
