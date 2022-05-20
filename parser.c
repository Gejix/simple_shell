#include "sshell.h"
/**
 * Counter - counts the number of lim found in the input
 * @C: the input string;
 * @lim: character to find inside the C string
 * Return: number of characters found
 */
int Counter(char *C, char *lim)
{
	int i = 0, num = 0;

	if (lim != NULL)
	{
		while (C && C[i] != '\0')
		{
			if (C[i] != lim[0])
			{
				if (C[i + 1] == lim[0] || C[i + 1] == '\0')
					num++;
			}
			i++;
		}
	}
	return (num);
}
/**
 * parsing - create an array of pointers depending of the delimit characters
 * @line: input of the user
 * Return: an array of pointers of n size
 */
char **parsing(char *line)
{
	char *token = NULL, **p = NULL;
	int length = 0, j = 0, i = 0, buffsize = 0;

	if (line == NULL)
		return (NULL);
	buffsize = Counter(line, " ");
	p = _calloc((buffsize + 1), sizeof(char *));
	if (!p)
	{
		perror("No memory");
		return (NULL);
	}
	/*store the token partition inside **p */
	token = _strtok(line, " \t\n");
	if (!token)
	{
		free(p);
		return (NULL);
	}
	while (token)
	{
		while (token[length] != '\0')
			length++;
		p[j] = _calloc((length + 1), sizeof(char));
		if (p[j] == NULL)
		{
			gridfree(p, j);
			perror("No memory");
			return (NULL);
		}
		/*fill the pointer with the content of token*/
		for (i = 0; i < length; i++)
			p[j][i] = token[i];
		length = 0;
		j++;
		/*get the next element*/
		token = _strtok(NULL, " \t\n");
	}
	p[j] = NULL;
	return (p);
}
