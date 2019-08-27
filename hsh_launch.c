#include "shell.h"
/**
 * hsh_launch -  a program and wait for it to terminate.
 * @filename: Name of file to execute
 * @argv: Arguments
 * @line_num: Number of line
 *
 * Return: Always returns 1, to continue execution.
*/
int hsh_launch(char *filename, char *argv[],
__attribute__((unused)) int line_num)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == 0)
	{
		/*Child process*/
		hsh_execvp(filename, argv, line_num);
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{
		free_everything(argv);
		perror("Failed fork");
		return (-1);
	}
	else
	{
		wait(&status);
	}
	return (1);
}
