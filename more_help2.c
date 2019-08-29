#include "shell.h"

/**
 * test_help - Help information for the builtin help.
 * Return: no return
 */
void test_help(void)
{
	char *help = "help: help [-dms] [pattern ...]\n";

	write(STDOUT_FILENO, help, hsh_strlen(help));
	help = "\tDisplay information about builtin commands.\n ";
	write(STDOUT_FILENO, help, hsh_strlen(help));
	help = "Displays brief summaries of builtin commands.\n";
	write(STDOUT_FILENO, help, hsh_strlen(help));
}
/**
 * test_help_alias - Help information for the builtin alias.
 * Return: no return
 */
void test_help_alias(void)
{
	char *help = "alias: alias [-p] [name[=value]...]\n";

	write(STDOUT_FILENO, help, hsh_strlen(help));
	help = "\tDefine or display aliases.\n";
	write(STDOUT_FILENO, help, hsh_strlen(help));
}
/**
 * test_help_cd - Help information for the builtin alias.
 * Return: no return
 */
void test_help_cd(void)
{
	char *help = "cd: cd [-L|[-P [-e]] [-@]] [dir]\n";

	write(STDOUT_FILENO, help, hsh_strlen(help));
	help = "\tChange the shell working directory.\n";
	write(STDOUT_FILENO, help, hsh_strlen(help));
}
