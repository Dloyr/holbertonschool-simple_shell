#include "main.h"

/**
* handle_input - handle the input of the user
* @line: user input
* @array: store tokens
* @full_path: store full path of command
* Return: index
*/

int handle_input(char *line, char **array, char **full_path)
{
	int index;

	index = tokenize_input(line, array);
	if (index < 0)
	{
		perror("Failed to tokenize input");
		return (-1);
	}

	if (array[0][0] == '/' || array[0][0] == '.')
		*full_path = strdup(array[0]);
	else
		*full_path = getpath(array[0]);

	if (*full_path == NULL)
	{
		fprintf(stderr, "Command not found: %s\n", array[0]);
		return (-1);
	}

	if (execute_command(*full_path, array) != 0)
	{
		perror("can't execute");
	}
	free(*full_path);
	return (index);
	}

