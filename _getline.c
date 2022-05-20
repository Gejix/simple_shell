#include "sshell.h"
/**
 * salida2 - out with double Ctrl+D
 *@m: copy of environmental variables
 *@e: number of elements in m
 *@line: input of user
 */
void salida2(char **m, int e, char *line)
{
	free(line);
	gridfree(m, e);
	write(STDIN_FILENO, "#cisfun$ ", 9);
	write(STDIN_FILENO, "\n", 1);
	exit(0);
}
/**
 * salida1 - normal out
 * @m: copy of environmental variables
 * @e: number of elements in m
 * @line: input of user
 */
void salida1(char **m, int e, char *line)
{
	(void)line;

	gridfree(m, e);
	write(STDIN_FILENO, "\n", 1);
	exit(0);
}
/**
 * _getline - function to read what the user writes
 * @a: pointer to loop counter
 * @e: length of m
 * @m: copy of environmental
 * Return: line in sucess otherwise NULL.
 */
char *_getline(int *a, char **m, int e)
{
	char letter[1] = {0}, *line = NULL;
	size_t bufsize = 0;
	static int num = 1;

	if (num == 2)
		salida2(m, e, line);
	for (; (num != 0); bufsize = 0, free(line))
	{
		write(STDIN_FILENO, "#cisfun$ ", 9);
		*a = *a + 1;
		signal(SIGINT, _signal);
		for (; ((num = read(STDIN_FILENO, letter, 1)) > 0); bufsize++)
		{
			if (bufsize == 0)
				line = _calloc(bufsize + 3, sizeof(char));
			else
				line = _realloc(line, bufsize, bufsize + 3);
			if (!line)
			{
				num = 0;
				break;
			}
			line[bufsize] = letter[0], line[bufsize + 1] = '\n';
			line[bufsize + 2] = '\0';
			if (line[bufsize] == '\n')
				break;
		}
		if (num == 0 && bufsize == 0)
			break;
		else if (num == 0 && bufsize != 0)
		{
			num = 2;
			break;
		}
		else if (line[0] != '\n')
			return (line);
	}
	if (num == 0)
		salida1(m, e, line);
	return (line);
}
/**
 * _getlineav - function to read what the user writes
 * @a: pointer to loop counter
 * @e: length of m
 * @m: copy of environmental
 * Return: line in sucess otherwise NULL.
 */
char *_getlineav(int *a, char **m, int e)
{
	char letter[1] = {0}, *line = NULL;
	size_t bufsize = 0;
	static int num = 1;

	if (num == 2)
		salida2(m, e, line);
	for (; (num != 0); bufsize = 0, free(line))
	{
		*a = *a + 1;
		signal(SIGINT, _signal);
		while ((num = read(STDIN_FILENO, letter, 1)) > 0)
		{
			if (bufsize == 0)
				line = _calloc(bufsize + 3, sizeof(char));
			else
				line = _realloc(line, bufsize, bufsize + 3);
			if (!line)
			{
				num = 0;
				break;
			}
			line[bufsize] = letter[0], line[bufsize + 1] = '\n';
			line[bufsize + 2] = '\0';
			if (line[bufsize] == '\n')
				break;
			bufsize++;
		}
		if (num == 0 && bufsize == 0)
			break;
		else if (num == 0 && bufsize != 0)
		{
			num = 2;
			break;
		}
		else if (line[0] != '\n')
			return (line);
	}
	if (num == 0)
		salida1(m, e, line);
	return (line);
}
