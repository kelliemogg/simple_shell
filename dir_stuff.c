#include "header.h"
/**
 * dir_search - searches through the PATH for a matching command
 * @argv: array of strings containing our tokenized arguments
 * @path_tokens: array of strings containing our tokenized PATH
 * Return: modified argv[0]
**/
char *dir_search(char **argv, char **path_tokens)
{
	struct dirent *dir_store;
	DIR *deer;
	int i;
	char *asdf;
	char *store;

	for (i = 0; path_tokens[i] != '\0'; i++)
	{
		deer = opendir(path_tokens[i]);
		while ((dir_store = readdir(deer)) != NULL)
		{
			if (_strcmp(argv[0], dir_store->d_name) == 0)
			{
				asdf = path_tokens[i];
				store = executable_maker(asdf, argv);
				return (store);
			}
		}
	}
return ("widdly");
}
/**
 * executable_maker- modifies argv[0] into an executable
 * @asdf: stores the path of the correct directory
 * @argv: argv[0] is concatenated to asdf
 * Return: modified asdf
**/
char *executable_maker(char *asdf, char **argv)
{
	_strcat(asdf, "/");
	_strcat(asdf, argv[0]);
return (asdf);
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
	for (j = 0; src[j] != '\0'; j++)
	{
		dest[i + j] = src[j];
	}
dest[i + j] = '\0';
return (dest);
}
