#include "main.h"

/**
 * gen_array - funtion that generates arrays
 * @buff: buffer
 * @arr: pointer to a pointer to a string
 * @delimit: Delimiter argument
 * Return: Always 0
 */

void gen_array(char *buff, char **arr, char *delimit)
{
	int i = 0;

	arr[i] = strtok(buff, delimit);
	while (arr[i])
	{
		i++;
		arr[i] = strtok(NULL, delimit);
	}
}

int spacechecker(char *input)
{
	int i = 0;

	for (i = 0; input[i] != '\0'; i++)
	{
		if (input[i] == ' ')
		{
			return (1); /** if found the space return 1*/
		}
	}
	return (0); /** if not found the space return 0*/
}

/**
 * ver_dir - check if str contains a directory path
 * @str: string to check
 * Return: 1 or 0
 *
 */


int ver_dir(char *str)
{
	int i;

	for (i = 0; str[i]; i++)
	{
		if (str[i] == '/')
			return (1);
	}
	return (0);
}
/**
 * ver_stat - verify the file status
 * @filename: pointer to string
 * Return: 1 or 0
 *
*/


int ver_stat(char *filename)
{
	struct stat filestat;

	if(stat(filename, &filestat) == 0)
		return (1);
	else
		printf("No such file or directory\n");
	return (0);
}

/**
 * aux_execute_command - funtion that creates another process
 * @argv: line command content
 * @path: path
 * Retrun: 0 or -1
 *
 *
 */

int aux_excute_command(char **argv, char *path)
{
	pid_t id;
	int done = 0;

	id = fork();
	if (id == -1)
		return (-1);
	if (id == 0)
		execve(path, argv, NULL);
	else
		wait(&done);

	return (0);
}
