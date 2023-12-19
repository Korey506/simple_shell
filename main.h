#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
int _printstr(char *str);
void _loop(void);
char *_read_line(void);
char **_split_line(char *line);
int _launch(char **args);
int _execmd(char **args);
int _cd(char **args);
int _help(char **args);
int lsh_exit(char **args);


#endif
