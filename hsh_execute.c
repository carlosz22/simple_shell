#include "shell.h"

/* Global structures/vairables - function related */
/*static char *builtin_str[] = {
	"env",
	"help",
	"cd"
};

static int (*builtin_func[]) (char **) = {
	&hsh_env,
	&hsh_help,
	&hsh_cd
};*/

/**
 * hsh_execute - handles execution of commands
 * @args: input of the program
 * @ep: environment variable
 * @line_num: line number
 *
 * Description: This is a description
 *
 * Return: Pointer or NULL if error
 */
int hsh_execute(char *filename, char **args, char **ep, int *line_num)
{
	long int m = 0;
	int i = 0, response, n, l;
	
	

	for (i = 0; i < hsh_num_builtins(); i++)
	{

		if (hsh_strcmp(args[0], "env") == 0 || hsh_strcmp(args[0], "printenv") == 0 )

		if (hsh_strcmp(args[0], "env") == 0)
  {
			n = hsh_env(args, ep);
			if (n == -1)
				print_error_env(args);
			return (n);
			//return ((*builtin_func[0])(ep));
		}
		if (hsh_strcmp(args[0], "exit") == 0)
		{
			m = exit_handler(args);

			if (m < 0)
			{
				print_error_exit(line_num, args[0], args);
				return (-1);
			}
			else
			{
				free_everything(args);
				exit(m);
			}
		}


		if (hsh_strcmp(args[0], "cd") == 0)

	
		{
			l = hsh_cd(args);
			if (l == -1)
			{
				print_error_cd(line_num, filename, args);
				write(2, "\n", 1);
			}
			return (l);
			/*return ((*builtin_func[i])(args));*/
		}
	}
	response = hsh_execvp(args[0], args, line_num);
	return (response);
}
