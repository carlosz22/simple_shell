#include "shell.h"

/**
 * hsh_help - Function that reallocates a memory block.
 * @args: Pointer previously allocated.
 *
 * Return: Pointer to the array or NULL.
 */
int hsh_help(__attribute__((unused)) char **args)
{
	int i;
	char *builtin_str[] = {"cd", "help", "exit", "env"};

	for (i = 0; i < 4; i++)
	{
		printf("  %s\n", builtin_str[i]);
	}
	return (1);
}
