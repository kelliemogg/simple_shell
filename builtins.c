#include "header.h"

/* Edited to be able to compile - problem: unused variables */

int sh_exit()
{
        return (0);
}

int sh_env()
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
int sh_help()
{

        printf("This is Tyler McClure and Kellie Mogg's Simmple Shell\n");
        printf("The following commands are available:\n");
        printf("cd\n");
        printf("exit\n");
	return (1);
}
