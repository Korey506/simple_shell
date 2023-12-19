#include "main.h"

char *builtin_str[] = {"cd", "help", "exit"};

/**
 * builtin_func - func array
 */
int (*builtin_func[]) (char **) = {
	&_cd,
	&_help,
	&lsh_exit
};

/**
 * _num_builtins - for builtinfunc
 * Return: builtin_str/char pointer
 */
int _num_builtins(void)
{
	return (sizeof(builtin_str) / sizeof(char *));
}


/**
 * _cd - func to change dir
 * @args: pointer argu
 * Return: 1
 */
int _cd(char **args)
{
	if (args[1] == NULL)
		perror("Error: expected argument to \"cd\"\n");
	else
	{
		if (chdir(args[1]) != 0)
			perror("Error:");
	}
	return (1);
}


/**
 * _help - to find guide
 * @args: pointer argu
 * Return: 1
 */

int _help(char **args)
{
	int i;

	_printstr("The following are built in:\n");

	for (i = 0; i < _num_builtins(); i++)
		_printstr(builtin_str[i]);
	_printstr("Use the man command for information on other programs.\n");
	return (1);
}


/**
 * lsh_exit - func to exit
 * @args: parameter
 * Return: 0
 */
int lsh_exit(char **args)
{
	return (0);
}


/**
 * _execmd - launch of builtin
 * @args: pointree argment
 * Return: _launch func
 */
int _execmd(char **args)
{
	int i;

	if (args[0] == NULL)
		return (1);
	for (i = 0; i < _num_builtins(); i++)
	{
		if (strcmp(args[0], builtin_str[i]) == 0)
			return ((*builtin_func[i])(args));
	}
	return (_launch(args));
}
