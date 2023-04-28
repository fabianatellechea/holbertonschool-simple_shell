#include "main.h"

/**
 * execute_input - reduce function main
 * @input: usr
 * Return: 0
 */

void execute_input(char *input)
{
	char *line_buf = calloc(1024, sizeof(char));
	char *line_buf = NULL, *path_com = NULL;
	char *array[1024], *array_dir[1024];
	char *input[MAX_INPUT_LENGTH];
	char *args[MAX_ARGS];

	strcpy(line_buf = input);

	char *array[1024];

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
		char *path_com = path_ver(array[0], array_di);

		if (path_com)
		{
			aux_excute_command(array, path_com);
			free(path_com);
			frees_arr(array_di);
			fflush(stdout);
			return (0);
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
	char *line_buf = NULL, *path_com = NULL;
	char *array[1024], *array_di[1024], *args[MAX_ARGS], *input[MAX_INPUT_LENGTH];

	while (1)
	{
		printf("$ "); /* Display prompt */
		fflush(stdout);
		read_input(input); /* Read input from user */
		parse_args(input[0], args); /* Parse arguments from input */
		if (strcmp(args[0], "exit") == 0) /* Check for exit command */
		{
			fflush(stdout);
			return (0);
		}

		execute_command(args); /* Execute command */

		if (spacechecker(input[0]))
		{
			execute_input(input[0]);
		}
	}
	return (0);
}
