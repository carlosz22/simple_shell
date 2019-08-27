#include "shell.h"
/**
 * hsh_execvp - Execute program handling the path
 * @char: Name of the variable to be searched
 * Return: Pointer to the value of the environment variable or NULL if error.
 */

int hsh_execvp(char *filename, char *argv[], __attribute__((unused)) int *line_num)
{
	char **env_cpy = environ;
	char **splitted_path;
	char *path;
	char *slash_fname;
	char *concat_fname;
	int i = 0, status;
	pid_t pid;

	pid = fork();
	if (pid == 0)
	{
		if (filename[0] == '\0')
		{
			free_everything(argv);
			exit(EXIT_FAILURE);
		}

		if (filename[0] == '/')
		{
			if (execve(filename, argv, env_cpy) == -1)
			{
				print_error(line_num, filename, argv);
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
				print_error(line_num, filename, argv);
			}
			free(slash_fname), free(concat_fname);
		}
		print_error(line_num, filename, argv);
		free_everything(splitted_path);
		free_everything(argv);
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{
		free_everything(argv);
		print_error(line_num, filename, argv);
		//perror("Failed fork");
		return (-1);
	}
	else
	{
		wait(&status);
	}
	return (1);
}
