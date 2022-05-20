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
char **create_env(char *envp[]);
void _updateoldpwd(char *buf, char **myenv);
void _updatepwd(char *buf, char **myenv);

/* shell functions*/
void _argv_plus(char *argv[], char *envp[]);
void _argv_nil(char *argv[], char *envp[]);
int revision(char **p, int loop, char *li, int i, char *av[], char **m, int *e);
void functions(char *line, int loop, char *argv[], char **m, int *e, char *f);
char *_getline(int *a, char **m, int e);
char **parsing(char *line);
void *_realloc(char *ptr, unsigned int old_size, unsigned int new_size);
void *_realloc2(char *a, char *p, unsigned int old, unsigned int new_size);
char *str_concat(char *s1, char *s2);
int _strlen(char *s);
char *_getlineav(int *a, char **m, int e);
char **parsing(char *line);
char *_comments(char *line);
int semicolon(char *line, int loop, char **argv);

/* getline functions*/
void gridfree(char **grid, int height);
void _fork(char **p, char *l, int a, int L, char **v, int e, char **m, char *f);
void *_calloc(unsigned int nume, unsigned int size);
char *_strtok(char *s, char *d);
char *_strtok2(char *s, char *d);
int _cd(char **p, int loop, char *v[], char **myenv);
void _iscd(char **a, int loop, char *v[], char **myenv);
char *_gethome(char **m);
int _ex(char **p, int loop, char *li, int x, char *v[], char **m, int e);
void _signal(int s);
int _atoi(char *s);
char **checkbin(char **b, char **m);

#define SIZE 1024

void _put_err(char **p, int loop, int sig, char *v[]);
void _builtinerr(char **p);
void _builtinerr2(char **p);
void _errorcd(char **p);
void _errorexit(char **p);
void _errorhelp(char **p);
void _errorgarbage(char **p);
void print_number(int n);

int _ishelp(char **p, int loop, char *v[], char **m);
void _help_builtin(char **p, int loop, char *v[], char **m);
void _help(char **p, int loop, char *v[], char **m);
ssize_t read_help(char **m);
ssize_t read_cdhelp(char **m);
ssize_t read_exithelp(char **m);
ssize_t read_helphelp(char **m);

/* unsetenv*/
int _env(char **p, char **myenv);
void _isenv(char **myenv);
int _isunsetenv(char **p, char **myenv, int *e, int loop, char *v[]);
void _unsetenv(char **p, char **myenv, int *e, int loop, char *v[]);
void _errorenv(char **p);

#endif
