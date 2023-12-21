#ifndef MAIN
#define MAIN

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>

char *getpath(char *line);
int tokenize_input(char *line, char **array);
int execute_command(char *full_path, char **array);
int handle_input(char *line, char **array, char **full_path);
void free_memory(char **array, int index);
int _strcmp(char *s1, char *s2);

#endif
