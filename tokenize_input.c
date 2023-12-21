#include "main.h"

/**
* tokenize_input - Tokenize user input and store tokens in an array
* @line: User input string
* @array: Array to store tokens
* Return: Number of tokens
*/

int tokenize_input(char *line, char **array)
{
	char *token;
	int index = 0;

	token = strtok(line, " \n");
	/* store tokens in array */
	while (token != NULL)
	{

		array[index] = strdup(token);
		if (array[index] == NULL)
		{
			perror("strdup");
			free(line);
			free(token);
			exit(EXIT_FAILURE);
		}
		index++;
		token = strtok(NULL, " \n");
	}
	return (index);
}
