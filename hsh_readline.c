#include "shell.h"

/**
 * _getchar - puts char by char from read
 *
 * Return: Integer of character read or EOF
 */

int _getchar(void)
{
	int ret = 0;
	/*static char buff[buffer_size];*/
	char buff[1];
	char *chr;

	ret = read(STDIN_FILENO, buff, 1);
	if (ret > 0)
	{
		chr = buff;
		return (*chr);
	}
	if (ret == -1)
		return (0);
	return (EOF);
}

/**
 * hsh_read - Checks if a character is a delimiter
 * @line: line
 * @n: size
 *
 * Description: ignore sig, print newline, print the prompt
 * Call to fflush discards the Ctrl-C
 * Return: characters read for the line
 */
int hsh_read(char **line, size_t *n)
{
	int position = 0, flag = 0, c;

	size_t new_size = buffer_size;
	char *buffer = malloc(sizeof(char) * (*n));

	if (alloc_error(buffer) == -1)
		return (-1);
	*line = buffer;
	while (1)
	{
		fflush(stdout);
		c = _getchar();
		if (c == EOF || c == '\n')
		{ buffer[position] = '\0';
			if (c == EOF)
				return (-1);
			else
				return (position + 1);
		}
		else if (c == ' ')
		{
			if (flag == 0)
			{ flag = 1;
				buffer[position] = c;
				position++;
			}
		}
		else
		{ flag = 0;
			buffer[position] = c;
			position++;
		}
		if (position >= buffer_size)
		{ new_size += 1024;
			buffer = hsh_realloc(buffer, buffer_size, new_size);
			if (alloc_error(buffer) == -1)
				return (-1);
		}
	}
	return (-1);
}
/**
 * hsh_readline - Read a line and save it in a buffer pointer
 *
 * Description: description function
 *
 * Return: Pointer or NULL if error
*/

char *hsh_readline(void)
{
	int c = 0;
	char *line = NULL;
	size_t size = buffer_size;

	c = hsh_read(&line, &size);

	if (c < 0)
	{
		if (isatty(STDIN_FILENO) != 0 && isatty(STDOUT_FILENO) != 0)
			putchar('\n');
		free(line);
		return (NULL);
	}
	return (line);
}

/**
 * alloc_error -  Allocation error
 * storing the address of the buffer containing the text into *b.
 *
 * @buffer: buffer to check
 * Return: -1 on eror.
 */
int alloc_error(char *buffer)
{
	if (!buffer)
	{
		perror("hsh: allocation error\n");
		return (-1);
	}
	else
		return (0);
}
