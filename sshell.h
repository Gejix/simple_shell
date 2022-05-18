#ifndef SSHELL_H
#define SSHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

char *_getline(void);
char **parsing(char *line);
void gridfree(char **grid, int height);
void _fork(char **p, char *line, int a);
void *_calloc(unsigned int nume, unsigned int size);
void _ex(char *p);

#endif
