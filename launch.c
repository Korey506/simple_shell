#include "main.h"

/**
 * _launch - to execute command
 * @args: argument to run
 * Return: 1
 */

int _launch(char **args)
{
	pid_t chpid, wpid;
	int status;

	chpid = fork();
	if (chpid == 0)
	{
		if (execve(args[0], args, NULL) == -1)
			perror("Error: execution");
		exit(EXIT_FAILURE);
	}
	else if (chpid < 0)
		perror("Error: creating process");
	else
	{
		do {
			wpid = waitpid(chpid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	return (1);
}

/**
 * _execmd - launch of builtin
 * @args: pointree argment
 * Return: _launch func
 *
int _execmd(char **args)
{
	int i;

	if (args[0] == NULL)
		return (1);
	for (i = 0; i < _num_builtins; i++)
	{
		if (strcmp(args[0], builtin_str[i]) == 0)
			return ((*builtin_func[i])(args));
	}
	return (_launch(args));
}
*/
