#ifndef SHELL
#define SHELL

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void);
int main(int ac, char **av);

int main(int ac, char **av, char **env);

#endif
