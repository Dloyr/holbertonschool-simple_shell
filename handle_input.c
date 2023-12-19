#include "main.h"

/**
* handle_input - handle the input of the user
* @line: user input
* @array: store tokens
* @full_path: store full path of command
* Return: index
*/

int handle_input(char *line, char **array, char *full_path)
{
	int index;

	index = tokenize_input(line, array);

	if (array[0][0] == '/' || array[0][0] == '.')
		full_path = strdup(array[0]);
	else
		full_path = getpath(array[0]);

	if (full_path != NULL)
	{
		if (execute_command(full_path, array) != 0)
		{
			cleanup(line, array, full_path);
			exit(1);
		}
	}
	return (index);
}
