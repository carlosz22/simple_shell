
#include "shell.h"

/**
 * hsh_env - Implementation of change directories (cd) built-in
 * @env: Arguments
 *
 * Return: Always 1.
 */
int hsh_env(char **args, char **env)
{
	int index = 0;
	if (args[1] == NULL)
	{
		while (env[index] != NULL)
		{
			printf("%s\n", env[index]);
			index++;
		}
		return (1);
	}
	return (-1);
}
