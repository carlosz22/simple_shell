#include "shell.h"
/**
 * hsh_realloc - Function that reallocates a memory block.
 * @ptr: Pointer previously allocated.
 * @old_size: Old size.
 * @new_size: New size.
 *
 * Return: Pointer to the array or NULL.
 */
void *hsh_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *cpy;
	int i = 0;
	int size_replace;
	char *ptr_char = ptr;
	if (new_size == old_size)
		return (ptr);
	else if (new_size < old_size)
		size_replace = new_size;
	else
		size_replace = old_size;
	if (ptr == NULL)
	{
		cpy = malloc(new_size);
		return (cpy);
	}
	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}

	cpy = malloc(new_size);

	if (cpy == NULL)
		return (NULL);

	for (i = 0; i < size_replace; i++)
		*(cpy + i) = *(ptr_char + i);

	return ((void *)cpy);
}
