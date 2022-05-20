#include "sshell.h"
/**
 *type_exit - get the type of exit
 * @p: input user, array of pointers
 * @loop: counter of loops
 * @li: input user
 * @i: number of pointers inside the array of pointers
 * @v: arguments in input
 * @m: copy of environmental variables
 * @e: number of elements in m
 */
void type_exit(char **p, int loop, char *li, int i, char *v[], char **m, int e)
{
	unsigned int valor = 0, cont = 0, flag = 0;

	if (p[1] == NULL || (p[1][0] == '0' && p[1][1] == '\0'))
	{
		free(li);
		gridfree(p, i);
		gridfree(m, e);
		exit(0);
	}
	else
	{
		while (p[1][cont] != '\0')
		{
			if (p[1][cont] < 48 || p[1][cont] > 57)
			{
				flag = 1;
				break;
			}
			cont++;
		}
		if (flag == 1)
			_put_err(p, loop, 1, v);
		else
		{
			valor = _atoi(p[1]);

			if (!(valor > INT_MAX))
			{
				valor = valor % 256;
				free(li);
				gridfree(p, i);
				gridfree(m, e);
				exit(valor);
			}
			else
				_put_err(p, loop, 1, v);
		}
	}
}
/**
 * _ex - finds if line input is exit therefore process termination
 * @p: input of user
 * @loop: loop counter
 * @li: input user
 * @x: number of pointers inside array of pointers
 * @v: arguments in input
 * @m: copy of environmental variables
 * @e: number of elements in m
 * Return: -1 if there is no exit or 0 if there is the word exit
 */
int _ex(char **p, int loop, char *li, int x, char *v[], char **m, int e)
{
	char str[] = "exit";
	int i, cont = 0, salida = -1;

	i = 0;
	while (p[0][i] != '\0')
	{
		if (i < 4)
		{
			if (p[0][i] == str[i])
				cont++;
		}
		i++;
	}
	if (i == 4)
		cont++;

	if (cont == 5)
	{
		type_exit(p, loop, li, x, v, m, e);
		salida = 0;
	}
	else if (cont == 4)
	{
		salida = 0;
		_put_err(p, loop, 3, v);
	}
	return (salida);
}
