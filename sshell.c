#include "sshell.h"
/**
 * main - shell main function
 * Return: nothing
 */
int main(void)
{
	char *line = NULL;
	char **args = NULL;
	int i = 0;

	while (1)
	{
		line = _getline();
		if (line == NULL)
			return (0);
		args = parsing(line);
		if (args == NULL)
			return (0);

		for (i = 0; args[i] != NULL; i++)
			;
		_fork(args, line, i);
		free(line);
		gridfree(args, i);
	}
	return (0);
}
