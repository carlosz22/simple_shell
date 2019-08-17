#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define buffer_size 1024
#define delim_var " \t\r\n\a"

int hsh_env(char **env);

int hsh_help(char **args);

int hsh_cd(char **args);
/*
  List of builtin commands, followed by their corresponding functions.
 */
char *builtin_str[] = {
  "env",
  "help",
  "cd"
};

int (*builtin_func[]) (char **) = {
  &hsh_env,
  &hsh_help,
  &hsh_cd
};

int hsh_num_builtins()
{
return sizeof(builtin_str) / sizeof(char *);
}


int hsh_env(char **env)
{
	int index = 0;
	while(env[index] != NULL)
	{
		printf("%s\n", env[index]);
		index++;
	}
return (1);
}

int hsh_help(char **args)
{
	printf("This is the help");
	return (1);
}

int hsh_cd(char **args)
{
	if (args[1] == NULL)
		printf("Error: expected argument to \"cd\"\n");
	else
	{
		if (chdir(args[1]) != 0)
			perror("cd");
	}
	return (1);
}
/**
 * main - execve example
 *
 * Return: Always 0.
 */
int main(int argc, char **argv, char **env)
{
	int line, index = 0, i = 0, status;
	size_t size = buffer_size;
	char * buffer;
	pid_t pid;
	char *delim, *token;
	char **tokens = malloc(sizeof(char) * size);
	 if (!tokens) 
	{
		fprintf(stderr, "lsh: allocation error");
		exit(EXIT_FAILURE);
	}
	delim = delim_var;
	buffer =  malloc(sizeof(char) * size);
	if (buffer == NULL)
	{
		perror("Error in buffer allocation");
		return(-1);
	}
	while(1)
	{
		write(1, "$ ", 3);
		index = 0;
		line = getline(&buffer, &size, stdin);
		if (line == -1 /*||  line == EOF*/)
			break;

		token = strtok(buffer, delim);
		while (token != NULL) 
		{ 
			tokens[index] = token;
			token = strtok(NULL, delim);
			index++;
		}
		free(token); //revisar;
		if (index > 1)
			printf("no such file or directory\n");
		pid = fork();
		if (pid == 0)
		{
		for (i = 0; i < hsh_num_builtins(); i++)
		{
			if (strcmp(tokens[0], "env") == 0) 
			{
				return (*builtin_func[0])(env);
			}
			else if (strcmp(tokens[0], builtin_str[i]) == 0)
			{
				return (*builtin_func[i])(tokens);
			}
		}
			if (execve(tokens[0],tokens, NULL) == -1)
			{
				perror("Failed execve ejecution\n");
				return (-1);
			}
		}
		else 
			wait(&status);
	}
	free(buffer);
	free(tokens);
	printf("afuera\n");
	return (0);
}
