#include "main.h"

/**
 * main - main function to simple shell
 * Return: 0
 */

int main(void)
{
	char *line_buf = NULL, *path_com = NULL;
	char *array[1024], *array_dir[1024];

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
		if (strcmp(input, "exit") == 0)
		{
			/* Clear prompt */
			printf("\033[2K\r"); /* move cursor to beginning of line and clear line */
			fflush(stdout);
			return (0);
		}


		/* Execute command */
		execute_command(args);
	}

	if (spacechecker(line_buf))
	{
		gen_array(line_buf, array, "\t\n ");
		if (ver_dir(array[0]))
		{
			if (ver_stat(array[0]))
				execute_command(array);
		}
		else
		{
			path_com = path_ver(array[0], array_dir);
			if (path_com)
			{
			aux_excute_command(array, path_com);
				free(path_com);
				frees_arr(array_dir);
			}
			else
				printf("%s: Command not found\n", array[0]);
		}
	}

	return (0);
}


