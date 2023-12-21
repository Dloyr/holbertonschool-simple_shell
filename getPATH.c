#include "main.h"

/**
* getpath - get the path
* @line: input
* Return: 0 on success
*/

char *getpath(char *line)
{
	char *Path, *Path_copy, *token, full_path[1024], *result;

	Path = getenv("PATH");

	if (Path == NULL)
	{
		perror("getenv");
		free(line);
		return (NULL); /* Change return type to NULL */
	}
	Path_copy = strdup(Path);

	if (Path_copy == NULL)
	{
		perror("strdup");
		free(line);
		return (NULL); /* Change return type to NULL */
	}

	token = strtok(Path_copy, ":");

	while (token != NULL)
	{
		sprintf(full_path, "%s/%s", token, line);

		if (access(full_path, F_OK | X_OK) == 0)
		{
			result = strdup(full_path);
			free(Path_copy);
			return (result); /* Change return type to result */
		}
		token = strtok(NULL, ":");
	}
	free(Path_copy);
	return (NULL); /* Change return type to NULL */
}
