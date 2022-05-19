#include "sshell.h"

/**
 * _env - function to print the environment variables
 * environ points to an array of pointers to strings called the "environment"
 * @p: input of user, array of pointers
 */

void _env(char *p)
{
	int i;
	(void)p;

	for (i = 0; environ[i] != NULL; i++)
	{
		write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
	}
}
/**
 * _isenv - finds if line input is env
 * @p: input of user, array of pointers
 * Return: -1 if fails or 0 if success
 */
int _isenv(char **p)
{
	char str[4] = "env";
	int i = 0, j = 0, cont = 0;

	while (p[0][j] != '\0')
		j++;
	if (j == 3)
	{
		while (i < 3)
		{
			if (p[0][i] == str[i])
				cont++;
			i++;
		}
		if (cont == 3)
		{
			_env(p[0]);
			return (0);
		}
	}
	return (-1);
}

