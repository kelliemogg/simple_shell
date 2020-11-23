#include "header.h"

char **_get_env(char *env)
{
        int inner;
        int outer;
        char *name;

        for (outer = 0; environ[outer] != NULL; outer++)
        {
                for (inner = 0; environ[outer][inner] != '='; inner++)
                {
                        /* printf("%c", environ[outer][inner]); */
                        if (environ[outer][inner] != env[inner])
                                break;
                        if (environ[outer][inner] == env[inner])
                        {
                                if (env[inner + 1] == '\0' && environ[outer][inner + 1] == '=')
                                {
                                        name = _strdup(&(environ[outer][inner + 2]));
                                        return(_env_parser(name));
                                }
                        }
                }
        }
        return(NULL);
}

char **_env_parser(char *name)
{
        int token_inc;
        int tokencount;
        char *tokenize;
	int i;
        char **p;

        tokencount = 0;
        for(i = 0; name[i] != '\0'; i++)
        {
                if(name[i] == ':')
                {
                        tokencount++;
                }
        }
        p = malloc(8 * (tokencount + 2));
        if(p != NULL)
        {
                token_inc = 0;
                tokenize = strtok(name, ":");
                while(token_inc < (tokencount + 1))
                {
                        p[token_inc] = tokenize;
                        tokenize = strtok(NULL, ":");
                        printf("%s\n", p[token_inc]);
                        token_inc++;
                }
        }
        return (p);
}
