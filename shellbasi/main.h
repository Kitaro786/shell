#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/types.h>

/* Function Prototypes */
char *get_input(int ac, char **av);
char **get_cmd(char *input, char **av);
pid_t exec_cmd(char **args, char **av);
int _putchar(char c);

#endif
