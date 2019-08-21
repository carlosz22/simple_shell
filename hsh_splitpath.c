#include "shell.h"

/**
 * hsh_splitpath2 - Split the line wrote in the console.
 * @line: Line wrote in console.
 * Return: An array with all words splited.
 */
char **hsh_splitpath(char *value)
{
	size_t size = buffer_size;
	size_t new_size = buffer_size;
	size_t index = 0;
	char **tokens;
	char *token;
	char *delim = ":\r\n\a";

	tokens = malloc(sizeof(char *) * size);

	if (tokens == NULL)
	{
		perror("Error allocating the buffer\n");
		return (NULL);
	}

	token = strtok(value, delim);

	while (token != NULL)
	{
		tokens[index] = token;
		index++;

		if (index >= size)
		{
			new_size += size;
			tokens = hsh_realloc(tokens, sizeof(char *) * size, sizeof(char *) * new_size);
			if (tokens == NULL)
			{
				perror("Error allocating the buffer\n");
				return (NULL);
			}
		}
		token = strtok(NULL, delim);
	}
	tokens[index] = NULL;
	return (tokens);
}
