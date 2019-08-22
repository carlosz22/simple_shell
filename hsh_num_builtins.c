#include "shell.h"

/* Global structures/vairables - function related */
static char *builtin_str[] = {
	"env",
	"help",
	"cd"
};

/**
 * hsh_num_builtins - Parse a line into tokens
 *
 * Return: Pointer or NULL if error
 */


int hsh_num_builtins(void)
{
	return (sizeof(builtin_str) / sizeof(char *));
}
