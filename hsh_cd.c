#include "shell.h"

/**
 * hsh_cd - Implementation of change directories (cd) built-in
 * @arguments: Arguments
 *
 * Return: Always 1.
 */

int hsh_cd(char **arguments)
{
	char cwd[1024];
	int cwd_size, index;

	if (!arguments[1])
		chdir(getenv("HOME"));


	if (hsh_strcmp(arguments[1], "-") == 0)
  {
		if (getenv("OLDPWD") == NULL)
		{
			chdir(".");
			return (1);
		}
		else
		{
			chdir(getenv("OLDPWD"));

			getcwd(cwd, sizeof(cwd));

			for (cwd_size = 0; cwd[index] != '\0'; index++)
			cwd_size++;

			cwd[index] = '\n';

			write(1, cwd, cwd_size + 1);
			return(1);
		}
	}

	if (chdir(arguments[1]) < 0)
	{
		return (-1);
	}
	else 
	{
		chdir(arguments[1]);
		return (1);
	}	
	return (0);
}
