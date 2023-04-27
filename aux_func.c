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
		/* Child process */
		execve(args[0], args, environ);
		/* If we reach this line, there was an error */
		fprintf(stderr, "%s: 1: %s: not found\n", args[0], args[0]);
		exit(1);
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
 * path_ver - check the current path exist or no
 * @buff: Buffer
 * @arr: pointer to a pointer to a string
 * Return: Direction path exist or no
 */

char *path_ver(char *buff, char **arr)
{
	struct stat sta;
	char *path = NULL;
	int i;

	for (i = 0; arr[i] != NULL; i++)
	{
		path = malloc(strlen(arr[i]) + strlen(buff) + 2);
		if (path == NULL)
			return (NULL);

		sprintf(path, "%s/%s", arr[i], buff);
		if (stat(path, &sta) == 0)
			return (path);
		free(path);
	}
	return (NULL);
}

/**
 * frees_arr - Free the array direction
 * @direc: Direction of array
 * Return: Always 0
 */

void frees_arr(char **direc)
{
	int i = 0;

	if (direc)
	{
		for (i = 0; direc[i]; i++)
			free(direc[i]);
	}
}
