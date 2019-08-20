#include "shell.h"

/**
 * main - execve example
 * @argc: argument counter
 * @argv: argument vector
 *
 * Description:
 *
 * Return: Always 0.
 */

/* Global structures/vairables - function related */

int main(__attribute__((unused)) int argc,__attribute__((unused))  char **argv)
{
	int status;
	char *line;
	char **tokens;
	char **ep;

	ep = environ;
	
	while(1)
	{
		write(STDIN_FILENO, "$ ", 3);
		line = hsh_readline();
		if (line == NULL)
			break;
		tokens = hsh_parseline(line);
		free(line);
		status = hsh_execute(tokens, ep);
		free_everything(tokens);
		if (status != 1)
			continue;
		//free(tokens);
	}
	printf("afuera\n");
	return (0);
}
