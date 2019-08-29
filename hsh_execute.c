#include "shell.h"

/**
 * hsh_execute - handles execution of commands
 * @args: input of the program
 * @ep: environment variable
 * @line_num: number of lines
 *
 * Description: This is a description
 *
 * Return: Pointer or NULL if error
 */
int hsh_execute(char **args, char **ep, int *line_num)
{
	long int m = 0;
	int response, n, l, j;

	if (hsh_strcmp(args[0], "env") == 0 || hsh_strcmp(args[0], "printenv") == 0)
	{ n = hsh_env(args, ep);
		if (n == -1)
			print_error_env(args), free_everything(args);
		return (n);
	}
	if (hsh_strcmp(args[0], "exit") == 0)
	{ m = exit_handler(args);
		if ((m < 0) && (isatty(STDIN_FILENO) == 0))
			print_error_exit(line_num, "./hsh", args), free_everything(args), exit(2);
		else if (m < 0)
		{ print_error_exit(line_num, "./hsh", args), free_everything(args);
			return (-1);
		}
		else
			free_everything(args), exit(m);
	}
	if (hsh_strcmp(args[0], "help") == 0)
	{ j = hsh_help(args);
		if (j == -1)
		{
			print_error_cd(line_num, "./hsh", args);
		}
		return (j);
	}
	if (hsh_strcmp(args[0], "cd") == 0)
	{ l = hsh_cd(args);
		if (l == -1)
		{
			print_error(line_num, "./hsh", args);
			write(2, "\n", 1);
			free_everything(args);
		}
			return (l);
	}
	response = hsh_launch(args[0], args, line_num);
	return (response);
}
