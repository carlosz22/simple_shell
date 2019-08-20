#include "shell.h"

/**
 * hsh_cd - Implementation of change directories (cd) built-in
 * @args: Arguments
 *
 * Return: Always 1.
 */

int hsh_cd(char **args)
{
    if (args[1] == NULL)
        printf("Error: expected argument to \"cd\"\n");
    else
    {
        if (chdir(args[1]) != 0)
            perror("cd");
    }
    return (1);
}
