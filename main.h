#ifndef MAIN
#define MAIN

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <ctype.h>

char *getpath (char *input);
int tokenize_input(char *line, char **array);
int execute_command(char *full_path, char **array);
int handle_input(char *line, char **array, char *full_path);
void cleanup(char *line, char **array, char *full_path);

#endif
