#include "sshell.h"
/**
 * _exit - finds if line input is exit therefore process termination
 * @p: input of user
 */
void _ex(char *p)
{
	char str[5] = "exit";
	int i = 0, j = 0, cont = 0;

	while (p[j] != '\0')
	{
		j++;
	}
	if (j == 5)
	{
		while (i < 4)
		{
			if(p[i] == str[i])
				cont++;
			i++;
		}
		if (cont == 4)
			exit(0);
	}
}
