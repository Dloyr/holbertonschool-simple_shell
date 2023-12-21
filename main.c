#include "main.h"

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

		if (getline(&line, &len, stdin) == - 1)
		{
			perror("getline");/* get user input */
		}
		array = malloc(sizeof(char *) * 1024);
		if (array == NULL)
		{
			perror("malloc");
			return (EXIT_FAILURE);
		}

		if (strcmp(line, "exit\n") == 0)
		{
			free_memory(array, 0);
			free(line);
			return (0);
		}
		index = handle_input(line, array, &full_path);
		free_memory(array, index);
	}
	return (0);
}
