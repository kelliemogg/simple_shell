#include "header.h"

/**
 * sh_exit - this exits the shell
 * description: exit builtin
 * Return: 0
 */

int sh_exit(void)
{
	exit(1);
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
	char *string;

	for (i = 0; environ[i] != NULL; i++)
	{
		for (j = 0; environ[i][j] != '\0'; j++)
		{
			string = _strdup(&(environ[i][j]));
			write(STDOUT_FILENO, string, stringlength(string));
			break;
		}
		_putchar('\n');
	}
	return (1);
}

/**
 * sh_cd - changes directory
 * description: this is change dir
 * @argv: arg passed
 * Return: 0
 */
int sh_cd(char **argv)
{
	if (argv[1] == NULL)
		perror("Argument expected\n");
	else
	{
		if (chdir(argv[1]) != 0)
			perror("Invalid path\n");
	}
	return (1);
}
/**
 * sh_help - prints the help page
 * description: see above
 * Return: void
 */

int sh_help(void)
{
	char *available = "The following commands are available:\n";
	char *cd = "cd\n";
	char *exit = "exit\n";

	/**
	 *write(STDOUT_FILENO, "This is Tyler McClure and Kellie Mogg's
	 *Simple Shell\n");
	 */
	write(STDOUT_FILENO, available, stringlength(available));
	write(STDOUT_FILENO, cd, stringlength(cd));
	write(STDOUT_FILENO, exit, stringlength(exit));
	return (1);
}
