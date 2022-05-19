#include "sshell.h"

/**
 * _gethome - funtion to get env HOME
 *Return: string inside the HOME env variable
 */

char *_gethome(void)
{
	int i, j, k, cont = 0;
	char str[] = "HOME=";
	char *home;

	for (i = 0; environ[i] != NULL; i++)
	{
		for (j = 0; environ[i][j] != '\0'; j++)
		{
			if (cont == 5)
				break;
			if (environ[i][j] == str[j])
				cont++;
			else
				break;
		}
		if (cont == 5)
			break;
	}
	home = environ[i];
	for (k = 0; k < 5; k++)
	{
		home++;
	}
	return (home);
}
