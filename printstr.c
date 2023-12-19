#include "main.h"

/**
 * _putchar - function to print xter
 * @c: argument to print
 * Return: return on sucess
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}


/**
 * _printstr - func to display string
 * @str: argument to display
 * Return: count on success
 */
int _printstr(char *str)
{
	int i, count = 0;

	for (i = 0; str[i]; i++)
	{
		count += _putchar(str[i]);
	}
	return (count);
}
