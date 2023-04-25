#include <stdio.h>

int main(int ac, char **av)
{
	(void)ac;

	int i = 1;

	while (av[i])
	{
		printf("%s ", av[i]);
		i++;
	}

	printf("\n");
	return (0);
}
