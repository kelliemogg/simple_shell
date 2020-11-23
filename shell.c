#include "header.h"


int main(int argc, char **argv)
{
        shell_loop();
	return (0);
}


void shell_loop(void)
{
        int userinput;
        char **argv;
        char *buffer;
        size_t bufsize = 1;
        char *prompt = "& ";
        int status;

        while (status == 1)
        {
                buffer = malloc(sizeof(char) * bufsize);
                if (buffer == NULL)
                        perror("Malloc failure\n");
                write(STDOUT_FILENO, prompt, stringlength(prompt));
                userinput = getline(&buffer, &bufsize, stdin);
                if (userinput == -1)
                        break;
                argv = tokenize(buffer);
                status = function_finder(argv);
                if (status == 0)
                        break;
        }
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
	argv = malloc(8 * (tokencount + 2));
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


int function_finder(char **argv)
{
        int i;

        if (argv[0] != NULL)
        {
                for (i = 0; i < 4; i++)
                {
                        if (_strcmp(argv[0], builtin_args[i]) == 0)
                                return ((*builtin_func[i])(argv));
                }
        }
        else
                return (executor(argv));
}
