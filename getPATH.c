#include "main.h"

/**
* getpath - get the path
* @input: input
* Return: 0 on success
*/

char *getpath(char *input)
{
	char *Path, *Path_copy, *token, full_path[1024], *result;
	Path = getenv("PATH");

	if (Path == NULL)
	{
		perror("getenv");
		return (NULL); /* Change return type to NULL */
	}
	Path_copy = strdup(Path);

	if (Path_copy == NULL)
	{
		perror("strdup");
		return (NULL); /* Change return type to NULL */
	}

	token = strtok(Path_copy, ":");

	while (token != NULL)
	{
		sprintf(full_path, "%s/%s", token, input);

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
