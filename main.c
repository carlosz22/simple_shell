#include "shell.h"
/**
 * main - execve example
 *
 * Return: Always 0.
 */

/* Global structures/vairables - function related */

int main(int argc, char **argv)
{
	int index = 0, i = 0, status;
	pid_t pid;
	char *line;
	char **tokens;
	char **ep;
	ep = environ;

	while (1)
	{
		write(STDIN_FILENO, "$ ", 3);
		index = 0;
		line = hsh_readline();
		if (line == NULL)
			break;
		tokens = hsh_parseline(line);
		pid = fork();
		if (pid == 0)
		{
			for (i = 0; i < hsh_num_builtins(); i++)
			{
				if (strcmp(tokens[0], "env") == 0)
				{
					return ((*builtin_func[0])(ep));
				}
				else if (strcmp(tokens[0], builtin_str[i]) == 0)
				{
					return ((*builtin_func[i])(tokens));
				}
			}
			if (execve(tokens[0], tokens, ep) == -1)
			{
				perror("Failed execve ejecution\n");
				return (-1);
			}
		}
		else
			wait(&status);
		free(line);
		free(tokens);
	}
	printf("afuera\n");
	return (0);
}
