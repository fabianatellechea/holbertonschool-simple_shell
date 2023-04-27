#include <stdio.h>
#include <stdlib.h>

int main()
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;

	while (1)
	{
		printf ("$ ");

		read = getline(&line, &len, stdin);

		if (read == -1)
		{
			if (feof(stdin))
			{
				break;
			}
			else
			{
				perror("getline");
				exit(EXIT_FAILURE);
			}
		}
		printf("%s", line);
	}
	free(line);

	return (0);
}



