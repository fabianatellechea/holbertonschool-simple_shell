#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char *line = NULL;
	size_t bufsize = 0;
	ssize_t chars_read;

	while (1)
	{
		printf("$ ");
		chars_read = getline(&line, &bufsize, stdin);

		if (chars_read == -1)
		{
			printf("end-of-file\n");
			break;
		}

		printf("%s", line);
	}

	free(line);
	return (0);
}
