#include "shell.h"
/**
 * hsh_strlen - Returns the length of the string
 * @s: Set of characters
 *
 * Return: The length of the string or 0 if there is no string
*/
int hsh_strlen(char *s)
{
	int i = 0;

	while (*(s + i) != '\0')
	{
		i++;
	}
	return (i);
}

/**
 * hsh_strncmp - Compare two strings with a specific length
 * @s1: String 1
 * @s2: String 2
 * @len: leng to compare
 *
 * Return: Difference of characters (0 - Equal)
 */
int hsh_strncmp(char *s1, char *s2, int len)
{
	int i = 1;

	while (i <= len)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
		i++;
	}
	return (0);
}

/**
 * hsh_strcmp - Compare two strings
 * @s1: String 1
 * @s2: String 2
 *
 * Return: Difference of characters (0 - Equal)
 */
int hsh_strcmp(char *s1, char *s2)
{
	while (*s1 == *s2)
	{
		if (*s1 == '\0')
			return (0);
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

/**
 * hsh_strconcat - Copies a string and returns a pointer to the array.
 * @s1: String 1.
 * @s2: String 2.
 *
 * Return: Pointer to the array or NULL.
 */
char *hsh_strconcat(char *s1, char *s2)
{
	int i = 0, j = 0, k = 0, n = 0;
	char *a;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";
	while (*(s1 + i))
		i++;

	while (*(s2 + j))
		j++;

	a = malloc(sizeof(char) * (i + j + 3));
	if (a == NULL)
		return (NULL);

	for (k = 0; k < i; k++)
	{
		*(a + k) = *(s1 + k);
	}
	for (n = 0; n <= j; n++)
	{
		*(a + n + k) = *(s2 + n);
	}
	return (a);
}
