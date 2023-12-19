#include "main.h"

/**
 * _loop - function to loop
 */

void _loop(void)
{
	char *line;
	char **args;
	int status;

	do {
		_printstr("$ ");
		line = _read_line();
		args = _split_line(line);
		status = _execmd(args);

		free(line);
		free(args);
	} while (status);
}

/**
 * _read_line - receives input from the std input
 * Return: line on success
 */
char *_read_line(void)
{
	char *line = NULL;
	size_t buffer = 0;

	if (getline(&line, &buffer, stdin) == -1)
	{
		if (feof(stdin))
			exit(EXIT_SUCCESS);
		else
		{
			perror("Error: readline");
			exit(EXIT_FAILURE);
		}
	}
	return (line);
}
