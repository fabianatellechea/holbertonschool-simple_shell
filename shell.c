#include "main.h"

/**
 * main - main function for simple shell
 * Return: 0
 */

int main(void)
{
	char *args[MAX_ARGS], *input = NULL;

	while (1)
	{
		if (isatty(STDIN_FILENO))
		{
			printf("$ ");
			fflush(stdout);
		}

		read_input(&input); /* Read input from user */
		parse_args(input, args);

		if (spacechecker(input))
		{
			free(input);
			continue;
		}

		if (args[0] == NULL)
		{
			free(input);
			continue;
		}

		if (strcmp(args[0], "exit") == 0) /* Check for exit command */
		{

			free(input);
			fflush(stdout);
			exit(0);
		}

		execute_command(args); /* Execute command */
		free(input);

	}
	return (0);
}
