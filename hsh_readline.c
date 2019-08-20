#include "shell.h"

/**
 * hsh_redline - Read a line and save it in a buffer pointer 
 *
 * Return: Pointer or NULL if error.
 */

char *hsh_readline(void)
{
    int characters_read;
    char *line;
    size_t size = buffer_size;

    line = malloc(sizeof(char) * size);
    if (line == NULL)
    {
        perror("Error in buffer allocation");
        return (NULL);
    }

    characters_read = getline(&line, &size, stdin);
    if (characters_read == -1)
        return (NULL);
    
    return (line);
}
