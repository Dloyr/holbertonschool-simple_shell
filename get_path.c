char getpath (char *input)
{
	char *Path, *Path_copy, *token;

	Path = getenv("PATH");

	Path_copy = strdup(Path);
	if (Path_copy == NULL)
	{
		perror("strdup");
		return (1);
	}

	token = strtok(Path_copy, ":");
	while (token != NULL)
	{
		printf("%s/%s\n", token, input);
		token = strtok(NULL, ":");
	}
	free (Path_copy);
	return (0);
}
