#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

extern char **environ;
#define MAX_INPUT_LEN 1024

char *_strdup(const char *str);
char *_strcat(char *dest, char *src);
int _strcmp(char *s1, char *s2);
int _strlen(char *s);
char *_strtrim(char *str);
char *get_path(char *command);
char *_strcpy(char *dest, char *src);
int _strncmp(const char *s1, const char *s2, size_t n);
char *_getenv(const char *name);
int execute_command(char *command_with_args);
void execute_child_process(char *command, char *args[]);
void prompt(void);
void print_environment(void);
#endif /* SHELL_H */

