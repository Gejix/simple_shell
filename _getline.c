#include "sshell.h"
/**
 * _getline - function to read what the user writes
 * @a: pointer to loop counter
 * Return: line in sucess otherwise NULL.
 */
char *_getline(int *a)
{
	char letter[1] = {0}, *line = NULL;
	size_t bufsize = 0;
	int num = 1;

	while (num != 0)
	{
		bufsize = 0;
		write(STDIN_FILENO, "#cisfun$ ", 9);
		*a = *a + 1;
		signal(SIGINT, _signal);

		while ((num = read(STDIN_FILENO, letter, 1)) > 0)
		{
			if (bufsize == 0)
				line = _calloc(bufsize + 1, sizeof(char));
			else
				line = _realloc(line, bufsize, bufsize + 1);
			if (!line)
			{
				num = 0;
				break;
			}
			line[bufsize] = letter[0];
			if (line[bufsize] == '\n')
				break;
			bufsize++;
		}
		if (!line && num == 0)
			break;
		if (line[0] != '\n')
			return (line);
	}
	if (num == 0)
	{
		write(STDIN_FILENO, "\n", 1);
		exit(0);
	}
	free(line);
	return (NULL);
}
