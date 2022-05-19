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
#include <limits.h>
#include <signal.h>

/*global variables*/
extern char **environ;

/* shell functions*/
char *_getline(int *a);
char **parsing(char *line);
void *_realloc(char *ptr, unsigned int old_size, unsigned int new_size);
void *_realloc2(char *a, char *p, unsigned int old, unsigned int new_size);
char *str_concat(char *s1, char *s2);
int _strlen(char *s);

/* getline functions*/
void gridfree(char **grid, int height);
void _fork(char **p, char *line, int a, int loop, char *v[]);
void *_calloc(unsigned int nume, unsigned int size);
char *_strtok(char *s, char *d);
int _cd(char **p, int loop, char *v[]);
char *_gethome(void);
int _ex(char **p, int loop, char *line, int x, char *v[]);
void _signal(int s);
int _atoi(char *s);
char **checkbin(char **b);

#define SIZE 1024

void _put_err(char **p, int loop, int sig, char *v[]);
void _builtinerr(char **p);
void _errorcd(char **p);
void _errorexit(char **p);
void _errorhelp(char **p);
void _errorgarbage(char **p);

int _ishelp(char **p, int loop, char *v[]);
void _help_builtin(char **p, int loop, char *v[]);
void _help(char **p, int loop, char *v[]);
ssize_t read_help(void);
ssize_t read_cdhelp(void);
ssize_t read_exithelp(void);
ssize_t read_helphelp(void);

int _isenv(char **p);

#endif
