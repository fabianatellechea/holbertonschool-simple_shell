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

	if (stat(filename, &filestat) == 0)
	{
		return (1);
	}
		else
		{
			printf("No such file or directory\n");
	return (0);
		}
}

/**
 * aux_excute_command - funtion that creates another process
 * @argv: line command content
 * @path: path
 * Return: 0 or -1
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
