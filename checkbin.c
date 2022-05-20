#include "sshell.h"

/**
  * _getpwd - get the PWD env variable
  * @m: copoy of environment variables
  * Return: the string inside PWD env variable
  */
char *_getpwd(char **m)
{
	int i, j, k = 0, cont = 0;
	char str[] = "PWD=";
	char *pwd;

	for (i = 0; m[i] != NULL; i++)
	{
		for (j = 0; m[i][j] != '\0'; j++)
		{
			if (cont == 4)
				break;
			if (m[i][j] == str[j])
				cont++;
			else
				break;
		}
		if (cont == 4)
			break;
	}
	if (cont == 4)
	{
		while (m[i][k] != '\0')
			k++;
		pwd = _calloc(k + 1, sizeof(char));
		if (pwd == NULL)
			return (NULL);
		k = 4;
		while (m[i][k] != '\0')
		{
			pwd[k - 4] = m[i][k];
			k++;
		}
		return (pwd);
	}
	return (NULL);
}
/**
 * _verifypath - check if the path has a : at the begining
 * or if exist ::
 *@path: string inside PATH env varible
 *@pwd: string inside PWD env variable
 *Return: path, or pwd concatenated to path if there is a : at the begining or
 *pwd concatenated when there is ::
 */
char *_verifypath(char *path, char *pwd)
{
	char *newpath = NULL, *str1 = NULL, *str2 = NULL, dosp = ':';
	int cont, pa, pw, k1, k2;

	if (path == NULL || pwd == NULL)
		return (NULL);
	for (pw = 0; pwd[pw] != '\0'; pw++)
		;
	for (pa = 0; path[pa] != '\0'; pa++)
		;
	for (cont = 0; path[cont] != '\0'; cont++)
	{
		if (path[0] == dosp)
		{
			newpath = str_concat(pwd, path);
			free(pwd), free(path);
			return (newpath);
		}
		else if (path[cont] == dosp && path[cont + 1] == dosp)
		{
			str1 = _calloc(pa + 1, sizeof(char));
			if (!str1)
				return (NULL);
			str2 = _calloc(pa + 1, sizeof(char));
			if (!str2)
				return (NULL);
			for (k1 = 0; k1 <= cont; k1++)
				str1[k1] = path[k1];
			for (k2 = 0; path[k1] != '\0'; k2++, k1++)
				str2[k2] = path[k1];
			newpath = str_concat(pwd, str2);
			newpath = str_concat(str1, newpath);
			free(str1);
			free(str2);
			free(pwd);
			free(path);
			return (newpath);
		}
	}
	free(pwd);
	return (path);
}
/**
 *_getpath - get the string in PATH env
 * @m: environment variables
 * Return: string inside PATH env variable
 */
char *_getpath(char **m)
{
	int i, j, k = 0, w = 0, cont = 0;
	char str[] = "PATH=";
	char *path;

	for (i = 0; m[i] != NULL; i++)
	{
		for (j = 0; m[i][j] != '\0'; j++)
		{
			if (cont == 5)
				break;
			if (m[i][j] == str[j])
				cont++;
			else
				break;
		}
		if (cont == 5)
			break;
	}
	k = cont;
	if (cont == 5)
	{
		while (m[i][k] != '\0')
		{
			w++;
			k++;
		}
		if (w == 0)
			return (NULL);
		path = _calloc(w + 1, sizeof(char));
		if (path == NULL)
			return (NULL);
		k = 5;
		while (m[i][k] != '\0')
		{
			path[k - 5] = m[i][k];
			k++;
		}
		return (path);
	}
	return (NULL);
}
/**
 * checkbin - checks if arg[0] has /bin/
 * @b: input of user, array of pointers
 * @m: copy of environment variables
 * Return: 0.
 */

char **checkbin(char **b, char **m)
{
	unsigned int i = 0, j = 0, k = 0;
	struct stat veri;
	char *path, *tokens, *buf, *pwd, *newpath;
	char *valor;

	i = _strlen(b[0]);
	if (b == NULL || i == 0)
		return (NULL);
	path = _getpath(m);
	if (path == NULL)
		return (b);
	pwd = _getpwd(m);
	newpath = _verifypath(path, pwd);
	tokens = _strtok(newpath, ":");
	if (!tokens)
		return (NULL);
	while (tokens != NULL)
	{
		while (tokens[j] != '\0')
			j++;
		buf = _calloc((j + 2), sizeof(char));
		if (buf == NULL)
			perror("No memory");
		for (k = 0; k < j; k++)
			buf[k] = tokens[k];
		buf[k] = '/';
		valor = str_concat(buf, b[0]);
		if (stat(valor, &veri) == 0)
		{
			b[0] = _realloc2(buf, b[0], i, _strlen(valor));
			free(buf), free(valor);
			free(newpath);
			return (b);
		}
		tokens = _strtok(NULL, ":");
		j = 0;
		free(buf), free(valor);
	}
	free(newpath);
	return (b);
}
