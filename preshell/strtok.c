#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **token(char *input, int *count)
{
	int i = 0, j = 0, k = 0, l = 0;
	char **words = NULL;
	int len = strlen(input);

	if (len == 0)
	{
		printf("Input string is empty\n");
		return (NULL);
	}

	for (; i < len; i++)
	{
		if (input[i] != ' ')
		{

			(*count)++;

			while (input[i] != ' ' && i < len)
			{
				i++;
			}
		}
	}
	words = (char**) malloc((*count) * sizeof(char*));

	if (words == NULL)
	{
		printf("Memory allocation error\n");
		return (NULL);
	}

	i = 0;
	while (i < len)
	{

		if (input[i] != ' ')
		{
			j = i;

			while (input[j] != ' ' && j < len)
			{
				j++;
			}

		words[k] = (char*) malloc((j - i + 1) * sizeof(char));

		if (words[k] == NULL)
		{
			printf("Memory allocation error\n");

		for (l = 0; l < k; l++)
		{
                    free(words[l]);
                }

                free(words);
                return (NULL);
		}

            	strncpy(words[k], input + i, j - i);
            	words[k][j - i] = '\0';
            	k++;
            	i = j;

        	}

        	i++;
    	}

	return (words);
}

int main()
{
    	int i;
   	char input[] = "Hello world! This is a test string.";
    	int count = 0;
    	char** words = token(input, &count);

    	if (words != NULL)
	{
        	for (i = 0; i < count; i++)
		{
            		printf("%s\n", words[i]);
        	}

        for (i = 0; i < count; i++)
	{
            free(words[i]);
        }

        free(words);
    	}

	return (0);
}
