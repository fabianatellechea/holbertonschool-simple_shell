#include <stdio.h>
#include <unistd.h>

int main()
{
	printf("The PID of the parent process is: %d\n", getppid());
	return (0);
}
