#include "header.h"

/**
 * sh_exit - this exits the shell
 * description: exit builtin
 * Return: 0
 */

int sh_exit(void)
{
	exit(0);
}

/**
 * sh_env - prints the environ
 * description: env builtin
 * Return: 0
 */
int sh_env(void)
{
	int i;
	int j;

	for (i = 0; environ[i] != NULL; i++)
	{
		for (j = 0; environ[i][j] != '\0'; j++)
		{
			write(STDOUT_FILENO, (&(environ[i][j])), 1);
			break;
		}
		_putchar('\n');
	}
	return (0);
}
