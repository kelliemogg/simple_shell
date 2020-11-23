#ifndef HEADER_H
#define HEADER_H

#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <errno.h>
#include <strings.h>
#include <stddef.h>

/* new prototypes associated with test.c */

char **tokenize(char *userinput);

int stringlength(char *s);

void shell_loop(void);

int executor(char **argv);

int function_finder(char **argv);

int sh_exit(char **argv);

int sh_help(char **argv);

int sh_cd(char **argv);

int sh_env(char **argv);

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
};
/* new prototypes associated with test.c*/

int _putchar(char c);
char _strchr(char *s, char c);
int fork_process(void);
char *read_line(void);
char *read_command(void);
int execute_cmd(char **args);
void _status_on(void);
int command_i(void);

/* prototypes for env and parsing env */
char *_strdup(char *str);
char *_env_parser(char *name);
char *_get_env(char *env);
extern char **environ;
void create(node **head, node **tail, char **str);

typedef struct commander
{
        char *commad;
        void (*cmd_func)();
} commander;

#endif /* HEADER_H */
