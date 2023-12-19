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

	if (my_pid == 0)
	{
		/* child process, execute command */
		execve(full_path, array, NULL);
		perror("execve");
		return (1);
	}
	else if (my_pid == -1)
	{
		perror("fork");
		free(full_path);
		return (1);
	}
	else
	{
		/* parent process, wait for child to finish */
		wait(&status);
		return (0);
	}
}