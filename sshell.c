#include "sshell.h"
/**
 *revision - gets if the input of user is env, cd
 *@p: input user, array of pointers
 *@loop: counter of loops
 *@line: input user
 *@i:number of pointers inside array of pointers
 *@argv: arguments in input
 * Return: -1 if the input is different to env or cd
 *or 0 if the input is cd or env
 */
int revision(char **p, int loop, char *line, int i, char *argv[])
{
	int valenv = 0, valcd = 0, other = -1, valex = 0, valhel = 0;

	valex = _ex(p, loop, line, i, argv);
	if (valex == 0)
		return (valex);
	valhel = _ishelp(p, loop, argv);
	if (valhel == 0)
		return (valhel);
	valenv = _isenv(p);
	valcd = _cd(p, loop, argv);
	if (valenv == 0)
		return (valenv);
	if (valcd == 0)
		return (valcd);
	return (other);
}
/**
 *main - shell skeleton
 * Return: 0 on Success
 */
int main(int argc, char *argv[])
{
	char *line = NULL;
	char **args = NULL;
	int value = 1, i = 0, *ploop;
	static int loop;
	(void)argc;

	loop = 0;
	ploop = &loop;
	while (1)
	{
		line = _getline(ploop);
		args = parsing(line);

		if (args)
		{
			for (i = 0; args[i] != NULL; i++)
				;
			value = revision(args, loop, line, i, argv);
			if (value != 0)
			{
				args = checkbin(args);
				if (args)
					_fork(args, line, i, loop, argv);
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
	return (0);
}
