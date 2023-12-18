#include "main.h"

/**
 * main - Shell
 * @argc: Number of arguments
 * @argv: Arguments
 * Return: 0
*/

int main(int argc, char **argv)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;

	if (argc != 1)
	{
		fprintf(stderr, "Usage: %s\n", argv[0]);
		return (EXIT_FAILURE);
	}

	printf("$ ");
	while ((read = getline(&line, &len, stdin)) != -1)
	{
		if (isatty(STDIN_FILENO))
		{
			printf("%s\n", line);
			printf("$ ");
		}

		/* sors du programme si l'user ecrit "exit" */
		if (strcmp(line, "exit\n") == 0)
		{
			free(line);
			exit(0);
		}

	}

	if (read == EOF)
	{
		free(line);
	}

	return (0);
}
