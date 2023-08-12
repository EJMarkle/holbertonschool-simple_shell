#include "shell.h"
/**
 * main - the main loop
 * Return: 0 if success
 */

int main(void)
{
	char **argv;
	char *line;
	int looper = 1;

	/* main shell loop */
	while (looper == 1)
	{
		/* checks if running in interactive terminal */
		if (isatty(fileno(stdin)))
			printf("Hello there. \n");

		/* assigns user's input to 'line' */
		line = readLine();
		/* assigns tokenized input to argv array */
		argv = parse(line);
		/* executes command and assigns result to 'looper' */
		looper = cmdHandler(argv);
		/* free memory (he did nothing wrong) */
		free(line);
		free(argv);
	}
	exit(EXIT_SUCCESS);
}
