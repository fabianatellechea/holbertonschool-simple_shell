#include "main.h"

/**
 *read_input - function that reads the input passed by user
 *@input: pointer to the input
 *Return: void
 */

void read_input(char **input)
{
	size_t input_size = 0;

	if (getline(input, &input_size, stdin) == -1)
	{
		free(*input);
		exit(0);
	}

	(*input)[strcspn(*input, "\n")] = '\0';

}

/**
 *parse_args - function that parses in args the input
 *@input: pointer to input
 *@args: double pointer to args in input
 *Return: void
 */

void parse_args(char *input, char **args)
{
	char *token;
	int count = 0;

	/* Parse arguments from input*/
	token = strtok(input, " ");

	while (token && count < MAX_ARGS)
	{
		args[count++] = token;
		token = strtok(NULL, " ");
	}

	args[count] = NULL;

}

/**
 * execute_command - function that executes the command passed by user
 * @args: double pointer to args in input
 *Return: void
 */

void execute_command(char **args)
{
	pid_t pid;
	int status;

	/* Fork process to execute command */
	pid = fork();

	if (pid == 0)
	{
		if (args[0][0] == '.' && args[0][1] == '/')
		{
			if (access(args[0], X_OK) == 0)
			{
				execve(args[0], args, environ);
			}
		}

		/* Child process */
		execve(args[0], args, environ);
		if (execve(args[0], args, environ) == -1)
		{
			/* If we reach this line, there was an error */
			fprintf(stderr, "%s: 1: %s: not found\n", args[0], args[0]);
			free(args[0]);
			exit(1);
		}
	}

	else if (pid > 0)
	{
		/* Parent process Wait for child process to complete*/
		waitpid(pid, &status, 0);
	}

	else
	{
		/* Error forking process */
		printf("Error: Fork failed\n");
		exit(1);
	}
}

/**
 * spacechecker - checker if the code have or not a space in str
 * @input: input user
 * Return: 1 or 0
 *
 */

int spacechecker(char *input)
{
	int i = 0;
	int spacematch;
	int len = strlen(input) - 1;

	if (input == NULL)
	{
		return (0);
	}

	while (i < len && input[i] == ' ')
	{
		i++;
	}
	if (i == len)
	{
		return (0);
	}

	while (len >= 0 && input[len] == ' ')
	{
		len--;
	}
	for (spacematch = i; spacematch <= len; spacematch++)
	{
		if (input[spacematch] == ' ')
		{
			return (1); /** if found the space return 1*/
		}
	}

	return (0); /** if not found the space return 0*/
}
