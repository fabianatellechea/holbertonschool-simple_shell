#include "main.h"

/**
 * main - main function to simple shell
 * Return: 0
 */

int main(void)
{
	char input[MAX_INPUT_LENGTH];
	char *args[MAX_ARGS];


	while (1)
	{

		/* Display prompt */
		printf("$ ");
		fflush(stdout);

		/* Read input from user */
		read_input(input);

		/* Parse arguments from input*/
		parse_args(input, args);

		/* Check for exit command */
		if (strcmp(args[0], "exit") == 0)
		{
			break;
		}


		/* Execute command */
		execute_command(args);
	}

	/* Clear prompt */
	printf("\r\033[K"); /* move cursor to beginning of line and clear line */
	fflush(stdout);

	return (0);
}
