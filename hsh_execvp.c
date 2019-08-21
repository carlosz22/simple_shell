#include "shell.h"
/**
 * hsh_execvp - Execute program handling the path
 * @char: Name of the variable to be searched
 * Return: Pointer to the value of the environment variable or NULL if error.
 */

int hsh_execvp(char *filename, char *argv[])
{
	char **env_cpy = environ;
	char *path;
	char **splitted_path;
	char *slash_filename;
	char *concat_filename;
	int i = 0;

	if (filename[0] == '\0')
		return (-1);

	if (filename[0] == '/')
	{
		if (execve(filename, argv, env_cpy) == -1)
			return (-1);
	}

	path = hsh_getenv("PATH");
	splitted_path = hsh_splitpath(path);

	for (; splitted_path[i] != NULL; i++)
	{
		slash_filename = hsh_strconcat(splitted_path[i], "/");
		concat_filename = hsh_strconcat(slash_filename, filename);
		if (access(concat_filename, F_OK | X_OK) == 0)
		{
			execve(concat_filename, argv, env_cpy);
		}
	}
	free(slash_filename);
	free(concat_filename);
	return (-1);
}
