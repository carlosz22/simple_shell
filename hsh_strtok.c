#include "shell.h"

/**
* hsh_strtok - converts a string into an array of tokens
* @str: string to tokenize
* @delim: delimeter between tokens
*
* Description: Set total to number of tokens in str
*
* Return: pointer to the array of strings on success, or NULL on failure
*/
char **hsh_strtok(char *str, char *delim)
{
	int i, j, k, m, numwords = 0;
	char **s;

	if (str == NULL || str[0] == 0)
		return (NULL);
	if (str[0] == ':')
		str = hsh_strconcat("./", str);
	if (!delim)
		delim = " ";
	for (i = 0; str[i] != '\0'; i++)
	{
		if (!is_delimiter(str[i], delim) && (is_delimiter(str[i + 1], delim) ||
!str[i + 1]))
			numwords++;
	}
	if (numwords == 0)
		return (NULL);
	s = malloc(sizeof(char *) * (numwords + 1));
	if (!s)
		return (NULL);
	for (i = 0, j = 0; j < numwords; j++)
	{
		while (is_delimiter(str[i], delim))
			i++;
		k = 0;
		while (!is_delimiter(str[i + k], delim) && str[i + k])
			k++;
		s[j] =  malloc(sizeof(char) * (k + 1));
		if (!s[j])
		{
			for (k = 0; k < j; k++)
				free(s[k]);
			free(s);
			return (NULL);
		}
		for (m = 0; m < k; m++)
			s[j][m] = str[i++];
		s[j][m] = 0;
	}
	s[j] = NULL, return (s);
}

