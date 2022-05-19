#include "osh.h"

/**
 * _getline - puts input from user into buffer line
 * @fp: buffer for user input
 * Return: buffer with user input
 */
char *_getline(FILE *fp)
{
	char *line;
	ssize_t read;
	size_t len;

	line = NULL;
	len = 0;
	read = getline(&line, &len, fp);
	if (read == -1)
	{
		free(line);
		exit(EXIT_SUCCESS);
	}

	return (line);
}


/**
 * tokenizer - tokenizes string
 * @str: user input
 * Return: pointer to array of tokens
 */
char **tokenizer(char *str)
{
	char **tokens;
	char *token;
	unsigned int i;

	tokens = malloc(sizeof(char) * BUFFER);
	if (tokens == NULL)
	{
		errors(3);
		exit(EXIT_FAILURE);
	}

	token = strtok(str, "\n\t\r ");

	i = 0;
	while (token != NULL)
	{
		tokens[i] = token;
		token = strtok(NULL, "\n\t\r ");
		i++;
	}

	tokens[i] = NULL;

	return (tokens);
}
