#include "header.h"

/**
 * main - main
 * description: main
 * @argc: argc
 * @argv: argv
 * Return: 0
 */

int main(int argc, char **argv)
{
	shell_loop(argc, argv);
	return (0);
}

/**
 * shell_loop - shell loop
 * description: shell loop
 * @argc: argc
 * @argv: argv
 * Return: 0
 */

int shell_loop(int argc, char **argv)
{
	int userinput;
	char *buffer;
	size_t bufsize;
	char *prompt = "$ ";
	char **path_tokens;
	char *executable;
	va_list args_list;

	(void) argc;

	buffer = NULL;
	while (1)
	{
		/* buffer = malloc(sizeof(char) * bufsize);*/
		   /* if (buffer == NULL) */
		   /* perror("Malloc failure\n"); */
		if (isatty(STDIN_FILENO))
		{
			write(STDOUT_FILENO, prompt, stringlength(prompt));
		}
		userinput = getline(&buffer, &bufsize, stdin);
		if (userinput == -1)
			break;
		argv = tokenize(buffer);
		if (argv[0] == NULL)
			continue;
		function_finder(argv[0], args_list);
		path_tokens = _get_env("PATH");
		executable = dir_search(argv, path_tokens);
		free(path_tokens);
		executor(executable, argv);
		/*free(argv);*/
		/*executor(executable, argv);*/
	}
	free(buffer);
return (0);
}

/**
 * tokenize - tokenize
 * description: tokenize
 * @userinput: userinput
 * Return: 0
 */

char **tokenize(char *userinput)
{
	int token_inc = 0;
	char *tokenize;
	char **argv;
	int tokencount = 0;
	int i;

	strtok(userinput, "\n");
	for (i = 0; userinput[i] != '\0'; i++)
	{
		if (userinput[i] == ' ')
		{
			tokencount++;
		}
	}
	argv = malloc(8 * (tokencount + 2));
	if (argv != NULL)
	{
		token_inc = 0;
		tokenize = strtok(userinput, " ");
		while (token_inc < (tokencount + 1))
		{
			argv[token_inc] = tokenize;
			tokenize = strtok(NULL, " ");
			token_inc++;
		}
		argv[token_inc] = NULL;
	}
	/*free(userinput);*/
	return (argv);
}

/**
 * executor - executor
 * description: exe
 * @asdf: asdf
 * @argv: argv
 * Return: 0
 */

int executor(char *asdf, char **argv)
{
	pid_t child_pid;

	child_pid = fork();
	if (child_pid == -1)
		perror("Fork failure\n");
	if (child_pid == 0)
	{
		execve(asdf, argv, environ);
	}
	else
	{
		wait(NULL);
	}
	free(argv);
	return (0);
}


/**
 * function_finder - for builtins
 * description: find da builtins
 * @argv: argv
 * @args_list: args_list
 * Return: 0
 */

int function_finder(char *argv, va_list args_list)
{
	int i;

	builtins arr[] = {
		/*{"cd", sh_cd},*/
		/*{"help", sh_help},*/
		{"env", sh_env},
		{"exit", sh_exit},
		{'\0', NULL}
	};

	(void) args_list;

	if (argv != NULL)
	{
		for (i = 0; arr[i].func; i++)
		{
			if (_strcmp(argv, arr[i].argv) == 0)
			{
				arr[i].func();
			}
		}
	}
	return (0);
}
