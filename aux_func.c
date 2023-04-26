#include "main.h"

/**
 *read_input - function that reads the input passed by user
 *@input: pointer to the input
 *Return: void
 */

void read_input(char *input, int *prompt)
{
	ssize_t bytes_read;
	/* Read input from user */
	bytes_read = read(STDIN_FILENO, input, MAX_INPUT_LENGTH);

	if (bytes_read == 0)
	{
		/* End of file reached */
		exit(0);
	}

	/* Remove trailing newline from input */
	input[strcspn(input, "\n")] = 0;

	/* If user entered "exit", don't display prompt on next iteration */
	if (strcmp(input, "exit") == 0)
	{
		*prompt = 0;
	}
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
