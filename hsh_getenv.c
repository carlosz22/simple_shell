#include "shell.h"
/**
 * hsh_getenv - get the value for an environment variable
 * @char: Name of the variable to be searched
 * Return: Pointer to the value of the environment variable or NULL if error.
 */

char *hsh_getenv(char *name)
{
	size_t len;
	char **env_cpy;

	env_cpy = environ;
	len = hsh_strlen(name);

	if (environ == NULL || name[0] == '\0')
		return (NULL);
	len--;

	for (; *env_cpy != NULL; env_cpy++)
	{
		if (!hsh_strncmp(*env_cpy, name, len) && (*env_cpy)[len + 1] == '=')
			return (&(*env_cpy)[len + 2]);
	}
	return (NULL);
}
