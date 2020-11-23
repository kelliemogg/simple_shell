#include "header.h"

/* edited for unused variables */
int main(int argc, char **argv)
{
	shell_loop(argc, argv);
	return (0);
}

/* added va_list to manage builtins */
/* to fix munmap_chunk error, I changed the while to just while (1) and took the
   if status == 1 out of the while loop */

int shell_loop(int argc, char **argv)
{
	int userinput;
	char *buffer;
	size_t bufsize = 1;
	char *prompt = "$ ";
	char **path_tokens;
	char *executable;
	va_list args_list;

	if (argc > 1 && argv[1])
	{
		function_finder(argv[1], args_list);
		path_tokens = _get_env("PATH");
		executable = dir_search(argv, path_tokens);
		executor(executable, argv);
		return (0);
	}
	while (1)
	{
		buffer = malloc(sizeof(char) * bufsize);
		if (buffer == NULL)
			perror("Malloc failure\n");
		write(STDOUT_FILENO, prompt, stringlength(prompt));
		userinput = getline(&buffer, &bufsize, stdin);
		if (userinput == -1)
			break;
		argv = tokenize(buffer);
		function_finder(argv[0], args_list);
		path_tokens = _get_env("PATH");
		executable = dir_search(argv, path_tokens);
printf("%s\n", executable);
		/*executor(executable, argv);*/
	}
	/* if (status == 1)
	   break; */
	free(buffer);
	free(argv);
return (0);
}


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
	argv = malloc(8 *(tokencount + 2));
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
	return (argv);
}



int executor(char *asdf, char **argv)
{
	pid_t child_pid;

	child_pid = fork();
	if (child_pid == -1)
		perror("Fork failure\n");
	if (child_pid == 0)
	{
		execve(asdf, argv, NULL);
	}
	else
	{
		wait(NULL);
	}
	return (1);
}

/* move these to this file to manage one error,
then turned them into just one array found in the
function_finder to solve a different error */
/*
 char *builtin_args[] = {
        "cd",
        "help",
        "env",
        "exit"
};

int (*builtin_func[]) (char **) = {
        &sh_cd,
        &sh_help,
        &sh_env,
        &sh_exit
	}; */


/*made the builtins arrays a single array and moved it into the function
  to avoid errors */


/* I could not for the life of me get it to compile using strcmp,
   the arguments did not please gcc, which is why I tried the va_list */

int function_finder(char *argv, va_list args_list)
{
	int i;

	builtins arr[] = {
		{"cd", sh_cd},
		{"help", sh_help},
		{"env", sh_env},
		{"exit", sh_exit},
		{'\0', NULL}
	};

	if (argv != NULL)
	{
		for (i = 0; arr[i].func; i++)
		{
                        if (arr[i].argv == argv)
			{
				return (arr[i].func(args_list));
			}/*(_strcmp(argv[0], builtin_args[i]) == 0)
			     return ((*builtin_func[i])(argv));*/
			else
			{
				return(0);
			}
		}
	}
	return (0);
}
