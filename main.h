#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <limits.h>
#include <fcntl.h>

#define MAX_ARGS 10

void read_input(char **input);
void parse_args(char *input, char **args);
void execute_command(char **args);
extern char **environ;
int spacechecker(char *input);

#endif
