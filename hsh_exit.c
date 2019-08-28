#include "shell.h"
/**
 * exit_handler - handles the builtin exit with arguments
 * @tokens: array of strings from the command line
 *
 * Description: If there is no second token,
 *
 * Return: 0 if there are no arguments,
 * -1 on failure, or the value of the argument
 */
long int exit_handler(char **tokens)
{
	int flag = 0, i;
	long int num = 0;

	if (tokens[1] == NULL)
		return (num);

	for (i = 0; tokens[1][i]; i++)
	{
		if ((tokens[1][i] >= '0' && tokens[1][i] <= '9') || tokens[1][0] == '+')
		{
			flag = 1;
			if (tokens[1][i + 1] < '0' || tokens[1][i + 1] > '9')
				break;
		}
		else
			break;
		flag = 0;
	}
	if (flag == 1)
	{
		num = hsh_atoi(tokens[1]);
		return (num);
	}
	return (-1);
}
