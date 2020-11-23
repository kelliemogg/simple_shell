#include "header.h"

int sh_exit(char **argv)
{
        return (0);
}

int sh_env(char **argv)
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
int sh_help(char **argv)
{

        printf("This is Tyler McClure and Kellie Mogg's Simmple Shell\n");
        printf("The following commands are available:\n");
        printf("cd\n");
        printf("exit\n");
	return (1);
}
