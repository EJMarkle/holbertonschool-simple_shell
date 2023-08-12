#include "shell.h"
/**
 * *readLine - stores user input to a variable
 * Return: returns the user's input as a string
 */

char *readLine(void)
{
	char *line = NULL;
	size_t buffer = 0;
	/* getline assigns the stdin to 'line', */
	/* frees and exits if getline returns error */
	if (getline(&line, &buffer, stdin) == -1)
	{
		free(line);
		exit(EXIT_SUCCESS);
	}
	return (line);
}
