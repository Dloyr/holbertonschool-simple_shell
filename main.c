#include "main.h"
int main (int argc, char **argv)
{
	char *line = NULL; /*store user input*/
	char *token;
	char **array; /*store tokens*/
	size_t len = 0;
	pid_t my_pid;
	int status;
	int index = 0; /*index for array*/
	char *full_path = NULL; /*store full path of command*/
	if (argc != 1)
	{
		fprintf(stderr, "Usage: %s\n", argv[0]);
		return (EXIT_FAILURE);
	}
	/*allocate memory for array*/
	array = malloc(sizeof(char *) * 1024);
	if (array == NULL)
	{
		perror("malloc");
		return (1);
	}
	/* main loop*/
	while (1)
	{
		if (isatty(STDIN_FILENO))
			printf("($) ");
		getline(&line,&len, stdin); /*get user input*/
		/*exit if user types exit*/
		if (strcmp(line, "exit\n") == 0)
		{

			free(line);

			exit(0);
		}
		token = strtok(line," \n"); /*tokenize user input*/
		/*store tokens in array*/
		while (token != NULL)
		{
			array[index] = strdup(token);
			token = strtok(NULL, " \n");
			index++;
		}
		if (array == NULL)
		{
			perror("strdup");
			return EXIT_FAILURE;
		}
		/* store value of array in full_path if is get in input*/
		if (array[0][0] == '/' || array[0][0] == '.')
		{
			full_path = strdup(array[0]);
			if (full_path == NULL)
			{
				perror("strdup");
				return EXIT_FAILURE;
			}
		}
		/* get full path of command*/
		else
			full_path = getpath(array[0]);
		if (full_path != NULL)
		{
			/* create a child process*/
			my_pid = fork();
			if (my_pid == 0)
			{
				/*child process, execute command*/
				execve(full_path, array, NULL);
				return EXIT_FAILURE;
			}
			/*fork failed*/
			else if (my_pid == -1)
			{
				perror("fork");
				free (array);
				free (full_path);
				return EXIT_FAILURE;
			}
			/*parent process*/
			else
			{
				/*wait for child to finish*/
				wait(&status);
				/*reset index*/
				for (index = 0; array[index] != NULL; index++)
					free(array[index]);
				free(full_path);
				index = 0;
			}
		}
	}
	free (array);
	return (EXIT_SUCCESS);
}
