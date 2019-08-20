#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

/* Constants */
#define buffer_size 1024
#define delim_var " \t\r\n\a"

/* Global variables */
extern char **environ;

/* Currently implemented */

char *hsh_readline(void);
char **hsh_parseline(char *line);
int hsh_execute(char **args, char **env);
int hsh_env(char **env);
int hsh_help(char **args);
int hsh_cd(char **args);
int hsh_num_builtins(void);

/* Not implemented yet */
void hsh_exit(int);
ssize_t hsh_getline(char **, size_t *, FILE *);
char *hsh_strtok(char *, const char *);
char *hsh_getenv(char *);
int setenv(const char *, const char *, int);
int unsetenv(const char *);

/* HelpFunction.h */
void free_everything(char **args);


#endif /* _SHELL_H */
