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
#include <dirent.h>

/**
 * struct builtins - struct with builtin commands
 * @argv: arg passed as command
 * @func: correlations function
 * description: this is to handle the builtins
 */
typedef struct builtins
{
	char *argv;
	int (*func)();
} builtins;

/* new prototypes associated with test.c */

char **tokenize(char *userinput);

int stringlength(char *s);

int shell_loop(int argc, char **argv);

int executor(char *asdf, char **argv);

int function_finder(char *argv, va_list args_list);

int sh_exit(void);

int sh_help(void);

int sh_cd(char **argv);

int sh_env(void);

char *_strcat(char *dest, char *src);

char *dir_search(char **argv, char **path_tokens);

int _strcmp(char *s1, char *s2);

char *executable_maker(char *asdf, char **argv);

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
char **_env_parser(char *name);
char **_get_env(char *env);
extern char **environ;

#endif /* HEADER_H */
