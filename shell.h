#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

/* Constants */
#define buffer_size 1024
#define delim_var " \t\r\n"

/* Global variables */
extern char **environ;

/* Currently implemented */
/* From Helper */
int _getchar(void);
int hsh_read(char **line, size_t *n);
char *hsh_readline(void);
char **hsh_parseline(char *line);
int hsh_execute(char **args, char **env, int line_num);
/* int hsh_launch(char **args); */
char **hsh_splitpath(char *value);
int hsh_execvp(char *file, char *argv[], int line_num);
void *hsh_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
char **hsh_strtok(char *str, char *delim);
int countwords(char *str, char delim);

/* built-in functions*/
int hsh_env(char **env);
int hsh_help(char **args);
int hsh_cd(char **args);
int hsh_num_builtins(void);
long int exit_handler(char **tokens);


/* String handling */
int hsh_strlen(char *s);
int hsh_strncmp(char *s1, char *s2, int len);
int hsh_strcmp(char *s1, char *s2);
char *hsh_strconcat(char *s1, char *s2);

/* Not implemented yet */
void hsh_exit(int);
ssize_t hsh_getline(char **, size_t *, FILE *);
char *hsh_getenv(char *);
int hsh_setenv(const char *, const char *, int);
int hsh_unsetenv(const char *);

/* HelpFunction.h */
void free_everything(char **args);
void sigint_handler(int sig);
int is_delimiter(char c, char *delim);
#endif /* _SHELL_H */
