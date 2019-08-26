#include "shell.h"

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
