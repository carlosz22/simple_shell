#include "shell.h"
/**
 * hsh_launch -  a program and wait for it to terminate.
 * @args: args Null terminated list of arguments (including program)
 *
 * Description: function to launch execve
 *
 * Return: Always returns 1, to continue execution.
*/
int hsh_launch(char **args)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == 0)
	{
		/*Child process*/
		if (hsh_execvp(args[0], args) == -1)
		{
			perror("hsh");
		}
	exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{
		/*Error forking*/
		perror("lsh");
	}
	else
	{
	/*Parent process*/
	do {
		waitpid(pid, &status, WUNTRACED);
		while
		(!WIFEXITED(status) && !WIFSIGNALED(status));
	}

return (1);
}
