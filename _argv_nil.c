#include "sshell.h"

/**
 *revision - gets if the input of user is env, cd
 *@p: input user, array of pointers
 *@loop: counter of loops
 *@li: input user
 *@i:number of pointers inside array of pointers
 *@av: arguments in input
 *@m: copy of environmental variable
 *@e: number of elements in m
 * Return: -1 if the input is different to env or cd
 *or 0 if the input is cd or env
 */
int revision(char **p, int loop, char *li, int i, char *av[], char **m, int *e)
{
	int valenv = 0, valcd = 0, other = -1, valex = 0, valhel = 0;
	int valunset = 0;

	valunset = _isunsetenv(p, m, e, loop, av);
	if (valunset == 0)
		return (valunset);
	valex = _ex(p, loop, li, i, av, m, *e);
	if (valex == 0)
		return (valex);
	valhel = _ishelp(p, loop, av, m);
	if (valhel == 0)
		return (valhel);
	valenv = _env(p, m);
	valcd = _cd(p, loop, av, m);
	if (valenv == 0)
		return (valenv);
	if (valcd == 0)
		return (valcd);
	return (other);
}
/**
 * functions - realize all the funcitons
 *@line: input of user
 *@loop: number of loops
 *@argv: argumnets
 *@m: copy of environment variables
 *@e: number of elements in m
 *@f: complete input of user
 */
void functions(char *line, int loop, char *argv[], char **m, int *e, char *f)
{
	char **args = NULL;
	int value = 1, i = 0;

	line = _comments(line);
	args = parsing(line);
	if (args)
	{
		for (i = 0; args[i] != NULL; i++)
			;
		value = revision(args, loop, line, i, argv, m, e);
		if (value != 0)
		{
			args = checkbin(args, m);
			if (args)
				_fork(args, line, i, loop, argv, *e, m, f);
		}
		gridfree(args, i);
		free(line);
	}
	else
	{
		free(line);
		fflush(STDIN_FILENO);
	}
	_put_err(args, loop, 0, argv);
}
/**
 * _argv_nil - shell form without filename at input
 * @argv: arguments in the input
 * @envp: environment variables
 */
void _argv_nil(char *argv[], char *envp[])
{
	char *line = NULL, **m = NULL, *p = NULL, *pr1 = NULL;
	int e = 0, *ploop, i = 0, sem = 0;
	static int loop;

	loop = 0;
	ploop = &loop;
	while (1)
	{
		if (loop == 0)
		{
			m = create_env(envp);
			for (e = 0; m[e] != NULL; e++)
				;
		}
		line = _getline(ploop, m, e);
		sem = semicolon(line, loop, argv);
		if (!(sem == 1))
		{
			p = _strtok2(line, ";\n");
			while (p)
			{
				pr1 = _calloc(_strlen(p) + 2, sizeof(char));
				for (i = 0; p[i] != '\0'; i++)
					pr1[i] = p[i];
				pr1[i] = '\n';
				pr1[i + 1] = '\0';
				functions(pr1, loop, argv, m, &e, line);
				p = _strtok2(NULL, ";\n");
			}
		}
		free(line);
	}
}

