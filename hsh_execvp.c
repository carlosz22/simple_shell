#include "shell.h"
/**
 * hsh_execvp - Execute program handling the path
 * @filename: Name of the file
 * @argv: Arguments
 * @line_num: Line number
 *
 * Return: -1 if the child does not enter to execve.
 */

int hsh_execvp(char *filename, char *argv[],
__attribute__((unused)) int line_num)
{
	char **env_cpy = environ, **splitted_path;
	char *path, *slash_fname, *concat_fname;
	int i = 0;

	if (filename[0] == '\0')
	{
		free_everything(argv);
		exit(EXIT_FAILURE);
	}

	if (filename[0] == '/')
	{
		if (execve(filename, argv, env_cpy) == -1)
		{
			free_everything(argv);
			exit(EXIT_FAILURE);
		}
	}

	path = hsh_getenv("PATH");
	splitted_path = hsh_splitpath(path);

	for (; splitted_path[i] != NULL; i++)
	{
		slash_fname = hsh_strconcat(splitted_path[i], "/");
		concat_fname = hsh_strconcat(slash_fname, filename);
		if (access(concat_fname, F_OK | X_OK) == 0)
		{
			execve(concat_fname, argv, env_cpy);
		}
		free(slash_fname), free(concat_fname);
	}
	perror("Command doesn't exist");
	free_everything(splitted_path);
	free_everything(argv);
	return (-1);
}
