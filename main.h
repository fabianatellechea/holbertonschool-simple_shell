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
#define MAX_INPUT_LENGTH 100
#define MAX_ARGS 10

void read_input(char *input);
void parse_args(char *input, char **args);
void execute_command(char **args);
extern char **environ;
char *path_ver(char *buff, char **arr);
void gen_array(char *buff, char **arr, char *delimit);
int spacechecker(char *input);
int ver_dir(char *str);
void frees_arr(char **direc);
int ver_stat(char *filename);
int aux_excute_command(char **argv, char *path);
#endif
