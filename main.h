#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdbool.h>
#include <sys/stat.h>

extern char **environ;

#define BUFFER_RANGE 1024
#define MAX_INPUT_LEN 1024

void prompt(void);
void exece_fun(char **args);
int lenstr(const char *str);
char *cpystr(char *str, const char *src);
char **tokenalize(char *str, const char *delim);
char *_strdup(const char *str);
char *my_getenv(const char *name);
char *_locationevn(char *command);
int cmpstr(const char *st1, const char *st2);
char *catstr(char *str, char *src);
char *_getenv(const char *str);
void free_str(char **argstr);
int strncmp_made(const char *st1, const char *st2, size_t i);
ssize_t made_getline(char *buf, size_t size);
void handle_command(char *strline);

int execute_command(char *command_with_args);
void execute_child_process(char *command, char *args[]);
#endif

