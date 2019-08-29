#include "shell.h"

/**
 * hsh_help - Implementation of change directories (cd) built-in
 * @args: Arguments
 *
 * Return: Always 1.
 */
int hsh_help(__attribute__((unused)) char **args)
{
	if (args[1] == 0)
		test_help_general();
	else if (hsh_strcmp(args[1], "setenv") == 0)
		test_help_setenv();
	else if (hsh_strcmp(args[1], "env") == 0)
		test_help_env();
	else if (hsh_strcmp(args[1], "unsetenv") == 0)
		test_help_unsetenv();
	else if (hsh_strcmp(args[1], "help") == 0)
		test_help();
	else if (hsh_strcmp(args[1], "exit") == 0)
		test_help_exit();
	else if (hsh_strcmp(args[1], "cd") == 0)
		test_help_cd();
	else if (hsh_strcmp(args[1], "alias") == 0)
		test_help_alias();
	else
		return (-1);
	return (1);
}
