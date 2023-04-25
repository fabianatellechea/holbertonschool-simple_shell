#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
	char *args[] = {"ls", "-l", "/tmp", NULL};
	pid_t pid;
	int status, i;

	for (i = 0; i < 5; i++)
	{
        	pid = fork();

        	if (pid == -1)
		{
            		perror("Error creating child process");
            		exit(EXIT_FAILURE);
		}
        
		else if (pid == 0)
		{
			execve("/bin/ls", args, NULL);
			perror("Error executing ls");
			exit(EXIT_FAILURE);
		}

		else
		{
			wait(&status);
			printf("Child %d exited with status %d\n", pid, status);
        	}
    }
	return (0);
}
