#include "header.h"

/* edited for unused variables */
int main()
{
        shell_loop();
	return (0);
}

/* added va_list to manage builtins */
/* to fix munmap_chunk error, I changed the while to just while (1) and took the
   if status == 1 out of the while loop */

void shell_loop()
{
        int userinput;
	char **argv;
        char *buffer;
        size_t bufsize = 1;
        char *prompt = "& ";
	int status;
	va_list args_list;

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
                status = function_finder(argv, args_list);
		status++;
	}
	/* if (status == 1)
	   break; */
	free(buffer);
	free(argv);
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
			printf("%s\n", argv[token_inc]);
			token_inc++;
		}
		argv[token_inc] = NULL;
	}
	return (argv);
}



int executor(char **argv)
{
        pid_t child_pid;

        child_pid = fork();
        if (child_pid == -1)
                perror("Fork failure\n");
        if (child_pid == 0)
        {
                execve(argv[0], argv, NULL);
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

int function_finder(char **argv, va_list args_list)
{
        int i;

	builtins arr[] = {
		{"cd", sh_cd},
		{"help", sh_help},
		{"env", sh_env},
		{"exit", sh_exit},
		{'\0', NULL}
	};

        if (argv[0] != NULL)
        {
                for (i = 0; arr[i].func; i++)
                {
                        if (arr[i].argv == argv[0])
			{
				return (arr[i].func(args_list));
			}/*(_strcmp(argv[0], builtin_args[i]) == 0)
			     return ((*builtin_func[i])(argv));*/
			else
			{
				return (executor(argv));
			}
		}
	}
	return (0);
}
