#include "main.h"

/**
 * execute_input - reduce function main
 * @input: usr
 */

void execute_input(char *input)
{
	char *line_buf = calloc(1024, sizeof(char));
	char *path_com = NULL;
	char *array[1024], *array_di[1024];

	strcpy(line_buf, input);
	gen_array(line_buf, array, "\t\n ");

	if (ver_dir(array[0]))
	{
		if (ver_stat(array[0]))
		{
			execute_command(array);
		}
	}
	else
	{
		path_com = path_ver(array[0], array_di);

		if (path_com)
		{
			aux_excute_command(array, path_com);
			free(path_com);
			frees_arr(array_di);
			fflush(stdout);
		}
		else
		{
			printf("%s: Command not found\n", array[0]);
		}
	}
	free(line_buf);
}

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
