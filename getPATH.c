#include "main.h"
char *getpath (char *input)
{
	char *Path, *Path_copy, *token, full_path[1024], *result;
	Path = getenv("PATH");
	Path_copy = strdup(Path);
	if (Path_copy == NULL)
	{
		perror("strdup");
		return NULL; 
	}
	token = strtok(Path_copy, ":");
	while (token != NULL)
	{
		sprintf(full_path, "%s/%s", token, input);
		if (access(full_path, F_OK | X_OK) == 0)
		{
			result = strdup(full_path);
			free(Path_copy);
			return result;
		}
		token = strtok(NULL, ":");
	}
	free (Path_copy);
	return NULL; 
}
