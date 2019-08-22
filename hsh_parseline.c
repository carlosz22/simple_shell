#include "shell.h"

/**
 * hsh_parseline - Parse a line into tokens
 * @line: 
 * Return: Pointer or NULL if error.
 */

/*char **hsh_parseline(char *line)
{
    char **tokens = NULL;
    int index = 0;
	if (line[0] == '\n' && strlen(line) <= 1)
		return (NULL);

        if (line[index - 1] == '\n')
                line[index - 1] = '\0';
	
        tokens = strtok(line, ' ');

        return (tokens);
}*/

char **hsh_parseline(char *line)
{
    char **tokens;
    char *token, *delim;
    int index = 0;
	size_t size = buffer_size;

    delim = delim_var;

    tokens = malloc(sizeof(char) * size);
    if (tokens == NULL)
    {
        perror("Error in buffer allocation"); /* Correct that */
        return (NULL);
    }
	if (line[0] == '\n' && hsh_strlen(line) == 1)
		return(NULL);
		
    token = strtok(line, delim);

    while (token != NULL)
    {
        tokens[index] = token;
        token = strtok(NULL, delim);
        index++;
    }
    tokens[index] = '\0';

    free(token);
    return (tokens);
}
