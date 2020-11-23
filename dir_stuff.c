#include "header.h"

char *dir_search(char **argv, char **path_tokens)
{
        struct dirent *dir_store;
        DIR *deer;
        int i;
        char *asdf;

        for (i = 0; path_tokens[i] != '\0'; i++)
        {
                deer = opendir(path_tokens[i]);
                while ((dir_store = readdir(deer)) != NULL)
                {
			if (_strcmp(argv[0], dir_store->d_name) == 0)
			{
				asdf = path_tokens[i];
				return (executable_maker(asdf, argv));
			}
                }
        }
/*error for command not found*/
	return(0);
}
char *executable_maker(char *asdf, char **argv)
{
	_strcat(asdf, "/");
	_strcat(asdf, argv[0]);
	return (asdf);
	/* printf("%s\n", executable); */

	/*addslash = _strcat(slash, argv[0]);*/
}
/**
*_strcat- entry point
*description: concatenates two strings
*@dest: string to copy to
*@src: string to be copied
*Return: dest
**/
char *_strcat(char *dest, char *src)
{
	int i, j;

	for (i = 0; dest[i] != '\0'; i++)
	{
	}
	for (j = 0; src[j] != '\0'; i++, j++)
	{
		dest[i] = src[j];
	}
dest[i + 1] = '\0';
return (dest);
}
