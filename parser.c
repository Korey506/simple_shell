#include "main.h"
#define TOK_BUFZE 1024
#define TOK_DELIM " \r\a\t\n"

/**
 * _split_line - tokenization
 * @line: argu to break
 * Return: pointer on success
 */

char **_split_line(char *line)
{
	int buffer = TOK_BUFZE, i = 0;
	char **tokens = malloc(buffer * sizeof(char *));
	char *token;

	if (!token)
	{
		perror("Error: memory failed");
		exit(EXIT_FAILURE);
	}

	token = strtok(line, TOK_DELIM);
	while (token)
	{
		tokens[i] = token;
		i++;
		token = strtok(NULL, TOK_DELIM);
	}
	tokens[i] = NULL;
	free(tokens);
	return (tokens);
}
