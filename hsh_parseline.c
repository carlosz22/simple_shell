#include "shell.h"

/**
 * hsh_parseline - Parse a line into tokens
 * @line: buffer
 * Return: Pointer or NULL if error.
 */

char **hsh_parseline(char *line)
{
	char **tokens = NULL;
	char *delim = delim_var;

	if (line[0] == '\n' && hsh_strlen(line) == 1)
		return (NULL);
	tokens =  hsh_strtok(line, delim);
	free(line);
	return (tokens);
}
