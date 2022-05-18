#include "sshell.h"
/**
 * _getline - function to read what the user writes
 * Return: line in sucess otherwise NULL.
 */
char *_getline(void)
{
	char *line = NULL;
	size_t bufsize = 0;
	ssize_t num = 0, pos = 0;

	write(STDOUT_FILENO, "#cisfun$ ", 9);
	num = getline(&line, &bufsize, stdin);

	/*infinity loop while is different of EOF or error*/
	while (num != -1)
	{
		_ex(line);
		pos = 0;
		if (!(line[0] == '\n'))
		{
			while (line[pos] != '\0')
			{
				if (line[pos] == '\n')
					return (line);
				pos++;
			}
		}
		write(STDOUT_FILENO, "#cisfun$ ", 9);
		num = getline(&line, &bufsize, stdin);
	}
	/* to get an end of line when the shell finish*/
	write(STDOUT_FILENO, "\n", 1);
	free(line);
	return (NULL);
}
