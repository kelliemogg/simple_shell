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

/* made struct for builtins*/

typedef struct builtins
{
	char *argv;
	int (*func)();
} builtins;

/* new prototypes associated with test.c */

char **tokenize(char *userinput);

int stringlength(char *s);

void shell_loop();

int executor(char **argv);

int function_finder(char **argv, va_list args_list);

int sh_exit();

int sh_help();

int sh_cd (char **argv);

int sh_env();

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

typedef struct commander
{
        char *commad;
        void (*cmd_func)();
} commander;

#endif /* HEADER_H */
