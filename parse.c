#include "shell.h"
/**
 * **parse - tokenizes user input to a 2d array
 *  @str: input to tokenize
 *  Return: 2d tokenized array
 */

char **parse(char *str)
{
	int i = 0;
	int buffsize = TOK_BUFSIZE;
	char **toks = malloc(buffsize * sizeof(char *));
	char *token;
	/* if toks is a null pointer, mem alloc failed */
	/* print error and exit */
	if (!toks)
	{
		perror("allocation error\n");
		exit(EXIT_FAILURE);
	}

	/* first token of str assigned to 'token' */
	token = strtok(str, TOK_DELIM);
	while (token != NULL)
	{
		/* assignes current token ith position in toks */
		toks[i] = token;
		i++;
		/* retrieves next token in string */
		token = strtok(NULL, TOK_DELIM);
	}
	/* sets last token to NULL */
	toks[i] = NULL;
	return (toks);
}
