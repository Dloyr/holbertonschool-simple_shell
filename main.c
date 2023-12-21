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

		getline(&line, &len, stdin); /* get user input */

		array = malloc(sizeof(char *) * 1024);
		if (array == NULL)
		{
			perror("malloc");
			free(line);
			return (1);
		}

		if (strcmp(line, "exit\n") == 0)
		{
			free(line);
			free_memory(array, 0);
			return (0);
		}
		index = handle_input(line, array, &full_path);
		free(full_path);
		free_memory(array, index);
	}
	free(line);
	return (0);
}
