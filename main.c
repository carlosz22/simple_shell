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
	signal(SIGINT, sigint_handler);
	while(1)
	{
		write(STDIN_FILENO, "$ ", 3);
		line = hsh_readline();
		if (line == NULL)
			break;
		tokens = hsh_parseline(line);
		status = hsh_execute(tokens, ep);
		if (status != 1)
			continue;
		/*free(tokens);*/
		free(line);
		free(tokens);
	}
	printf("afuera\n");
	return (0);
}
