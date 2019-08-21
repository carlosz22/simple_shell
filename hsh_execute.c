#include "shell.h"

/* Global structures/vairables - function related */
static char *builtin_str[] = { 
        "env",
        "help",
        "cd"
};

static int (*builtin_func[]) (char **) = { 
        &hsh_env,
        &hsh_help,
        &hsh_cd
};

/**
 * hsh_execute - handles execution of commands
 * @args: input of the program
 * @ep: environment variable
 *
 * Description: This is a description
 *
 * Return: Pointer or NULL if error.
 */
int hsh_execute(char **args, char **ep)
{
	int i = 0, status;
	pid_t pid;

	pid = fork();
	if (pid == 0)
	{
		for (i = 0; i < hsh_num_builtins(); i++)
		{
			if (strcmp(args[0], "env") == 0)
			{
				return ((*builtin_func[0])(ep));
			}
			else if (strcmp(args[0], builtin_str[i]) == 0)
			{
				return ((*builtin_func[i])(args));
			}
		}
		if (hsh_execvp(args[0], args) == -1)
		{
			perror("Failed execve ejecution\n");
			return (-1);
		}
	}
	else if (pid == -1)
		return (-1);
	else
		wait(&status);

	return (1);
}


