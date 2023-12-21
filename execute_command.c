#include "main.h"

/**
* execute_command - Execute the given command in a child process
* @full_path: Full path of the command
* @array: Array of command and its arguments
* Return: 0 on success, 1 on failure
*/

int execute_command(char *full_path, char **array)
{
	pid_t my_pid;
	int status;

	my_pid = fork();

	if (my_pid == -1)
	{
		free(array);
		free(full_path);
		perror("fork");
		return (-1);
	}
	else if (my_pid == 0)/* child process, execute command */
	{
		if (execve(full_path, array, NULL) == -1)
		{
			free(array);
			free(full_path);
			perror("execve");
			return (-1);
		}
	}
	else /* parent process, wait for child to finish */
	{
		if (waitpid(my_pid, &status, 0) == -1)
		{
			free(array);
			free(full_path);
			perror("waitpid");
			return (-1);
		}
	}
	return (0);
}
