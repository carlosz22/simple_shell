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
 * Return: Pointer or NULL if error
 */
int hsh_execute(char **args, char **ep, int line_num)
{
	long int m = 0;
	int i = 0, response;

	for (i = 0; i < hsh_num_builtins(); i++)
	{
		if (strcmp(args[0], "env") == 0)
		{
			return ((*builtin_func[0])(ep));
		}
		if (strcmp(args[0], "exit") == 0)
		{
			m = exit_handler(args);
			free_everything(args);
			if (m < 0)
			{
				dprintf(STDERR_FILENO,"hsh: 1: exit: Illegal number: %s\n", args[1]);
				return(-1);
			}
			else if (m == -1)
			{
				perror("Exit error");
			}
			else
			{
				exit(m);
			}
		}

		if (strcmp(args[0], builtin_str[i]) == 0)
		{
			return ((*builtin_func[i])(args));
		}
	}
	response = hsh_execvp(args[0], args, line_num);
	return (response);
}
