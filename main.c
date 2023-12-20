#include "main.h"

/**
* cleanup - free the memory
* @line: store user input
* @array: store tokens
* @full_path: store full path of command
*/

void cleanup(char *line, char **array, char *full_path)
{
	free(line);
	free(full_path);
	free(array);
}

/**
* main - Shell
* @argc: Number of arguments
* @argv: Arguments
* Return: 0
*/

int main(int argc, char **argv)
{

	int index;
	char *line = NULL; /* store user input */
	char **array = NULL; /* store tokens */
	size_t len = 0;
	char *full_path = NULL; /* store full path of command */

	if (argc != 1)
	{
		fprintf(stderr, "Usage: %s\n", argv[0]);
		return (EXIT_FAILURE);
	}

	while (1)
	{
		if (isatty(STDIN_FILENO))
			printf("$ ");

		getline(&line, &len, stdin); /* get user input */

		array = malloc(sizeof(char *) * 1024);
		if (array == NULL)
		{
			perror("malloc");
			exit(1);
		}

		if (strcmp(line, "exit\n") == 0)
		{
			cleanup(line, array, full_path);
			exit(0);
		}
		handle_input(line, array, full_path);
	}
	cleanup(line, array, full_path);
	return (index);
	}
