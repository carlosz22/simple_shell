#include "shell.h"

/**
 * hsh_env - environ handler
 * @args: Arguments
 * @env: environment
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
		_puts(env[index]);
		index++;
	}
		return (1);
	}
	return (-1);
}
