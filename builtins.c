#include "shell.h"
/**
 * cmdHandler - compares command with list of built-ins,
 * calls execute function if not found
 * @parsed: 2d array holding user input
 * Return: 1, -1 if user enters 'exit'
 */

int cmdHandler(char **parsed)
{
	int switchArg = 0, loops = 0, i;
	char **env = environ;
	char *cmdList[3];
	/* assigns command names to 'cmdList' array  */
	cmdList[0] = "exit";
	cmdList[1] = "cd";
	cmdList[2] = "env";
	/* iterates through array, comparing first token in 'parsed' */
	/* with commands in 'cmdList' */
	/* if match, assign 'cmdList' value to switchArg */
	for (i = 0; i < 3; i++)
	{
		if (strcmp(parsed[0], cmdList[i]) == 0)
			switchArg = i + 1;
	}
	switch (switchArg)
	{
		case 1:
			return (-1);
		case 2:
			if (parsed[i] == NULL)
				perror("too few arguments");
			else
			{
				if (chdir(parsed[1]) != 0)
					perror("hsh");
			}
			return (1);
		case 3:
			while (*env != NULL)
			{
				printf("%s\n", *env);
				env++;
			}
			return (1);
		default:
			loops = execution(parsed);
			return (loops);
	}
	return (0);
}
