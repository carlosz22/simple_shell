#include "shell.h"

int hsh_env(char **env)
{
    int index = 0;

    while (env[index] != NULL)
    {
        printf("%s\n", env[index]);
        index++;
    }
    return (1);
}
