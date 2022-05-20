#include "sshell.h"

/**
 * _fork - program that creates process and execute
 * @p: array of pointer (args)
 * @l: input typed by the user
 * @a: count of pointers
 * @L: count of loops
 * @v: arguments in input
 * @e: env length
 * @m: copy of environmental variable
 * @f: complete input
 * Return: Nothing.
 */

void _fork(char **p, char *l, int a, int L, char **v, int e, char **m, char *f)
{
	pid_t child_pid;
	int status;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Error");
		exit(127);
	}
	if (child_pid == 0)
	{
		if (execve(p[0], p, m) == -1)
		{
			_put_err(p, L, 3, v);
		}
		free(f);
		free(l);
		gridfree(p, a);
		gridfree(m, e);
		/*printf("After execve\n");*/
		exit(127);
	}
	else
	{
		wait(&status);
	}
}
