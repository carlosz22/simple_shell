#include "shell.h"

/**
 * free_everything - frees arrays of strings
 * @args: array of strings to free
 */

void free_everything(char **args)
{
        int i;

        if (!args)
                return;

        for (i = 0; args[i]; i++)
                free(args[i]);

        free(args);
}

/**
 * sigint_handler - doesn't exit in case of Ctrl-C
 * @sig: required for signal function to run properly
 *
 * Description: ignore sig, print newline, print the prompt
 * Call to fflush discards the Ctrl-C
 */
void sigint_handler(int sig)
{
        (void)sig;
        putchar('\n');
        write(STDOUT_FILENO, "$ ", 3); 
        fflush(stdout);
}

int is_delimiter(char c, char *delim)
{
	while(*delim)
	{
		if(*delim++ == c)
		{
			return(1);
		}
	}
	return(0);
}

