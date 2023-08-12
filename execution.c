#include "shell.h"
/**
 * execution - execute non built-in command
 * @parsed: 2d array holding parsed user input
 * Return: 1, -1 if error
 */

int execution(char **parsed)
{
	/* duplicates current process and sets child 'pid' to it's pid */
	pid_t pid = fork();

	/* pid == 0 indicated child process */
	if (pid == 0)
	{
		/* executes first token in 'parsed' */
		/* if execvp returns error, print error and return -1 */
		if (execvp(parsed[0], parsed) == -1)
			perror("Error\n");
		return (-1);
	}
	/* check if fork failed */
	else if (pid < 0)
		perror("Fork Error\n");
	/* waits for child process to complete */
	else
	{
		wait(NULL);
	}
	return (1);
}
