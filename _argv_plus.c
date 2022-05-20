#include "sshell.h"

/**
 * _argv_plus - shell form without filename at input
 * @argv: arguments in the input
 * @envp: environment variables
 */
void _argv_plus(char *argv[], char *envp[])
{
	char *line = NULL, **m = NULL;
	int e = 0, *ploop;
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
		line = _getlineav(ploop, m, e);
		if (line[0] == ';')
			perror("PAILA");
		else
			functions(line, loop, argv, m, &e, line);
	}
}
