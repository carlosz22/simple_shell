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

int main(__attribute__((unused)) int argc,
__attribute__((unused))  char **argv)
{
	int status;
	int line_num = 0;
	char *line;
	char **tokens;
	char **ep;

	ep = environ;
	signal(SIGINT, sigint_handler);
	while (1)
	{
		write(STDIN_FILENO, "$ ", 3);
		line = hsh_readline();
		if (line == NULL)
			break;
		tokens = hsh_parseline(line);
		if (tokens == NULL)
			continue;
		line_num++;
		status = hsh_execute(tokens, ep, line, line_num);
		if (status != 1)
			continue;
		/*free(tokens);*/
		free(line);
		free_everything(tokens);
	}
	return (0);
}
