#include "sshell.h"

/**
 * read_help - reads all builtins text file and prints it to POSIX stdout
 * Return: number of letters to write, otherwise 0.
 */

ssize_t read_help(void)
{
	int fd, r, w;
	char *buf;
	size_t letters = 1024;

	buf = malloc((sizeof(char) * letters + 1));
	if (buf == NULL)
		return (0);

	fd = open("./_helpfiles/help_all.txt", O_RDONLY);
	if (fd == -1)
		return (0);
	r = read(fd, buf, letters);
	if (r == -1)
		return (0);
	w = write(STDOUT_FILENO, buf, r);
	if (w == -1)
		return (0);
	close(fd);
	free(buf);
	return (r);
}

/**
 * read_cdhelp - reads cd text file and prints it to POSIX stdout
 * Return: number of letters to write, otherwise 0.
 */

ssize_t read_cdhelp(void)
{
	int fd, r, w;
	char *buf;
	size_t letters = 1024;

	buf = malloc((sizeof(char) * letters + 1));
	if (buf == NULL)
		return (0);
	fd = open("./_helpfiles/help_cd.txt", O_RDONLY);
	if (fd == -1)
		return (0);
	r = read(fd, buf, letters);
	if (r == -1)
		return (0);
	w = write(STDOUT_FILENO, buf, r);
	if (w == -1)
		return (0);
	close(fd);
	free(buf);
	return (r);
}

/**
 * read_exithelp - reads exit text file and prints it to POSIX stdout
 * Return: number of letters to write, otherwise 0.
 */

ssize_t read_exithelp(void)
{
	int fd, r, w;
	char *buf;
	size_t letters = 1024;

	buf = malloc((sizeof(char) * letters + 1));
	if (buf == NULL)
		return (0);
	fd = open("./_helpfiles/help_exit.txt", O_RDONLY);
	if (fd == -1)
		return (0);
	r = read(fd, buf, letters);
	if (r == -1)
		return (0);
	w = write(STDOUT_FILENO, buf, r);
	if (w == -1)
		return (0);
	close(fd);
	free(buf);
	return (r);
}

/**
 * read_helphelp - reads help text file and prints it to POSIX stdout
 * Return: number of letters to write, otherwise 0.
 */

ssize_t read_helphelp(void)
{
	int fd, r, w;
	char *buf;
	size_t letters = 1024;

	buf = malloc((sizeof(char) * letters + 1));
	if (buf == NULL)
		return (0);
	fd = open("./_helpfiles/help_help.txt", O_RDONLY);
	if (fd == -1)
		return (0);
	r = read(fd, buf, letters);
	if (r == -1)
		return (0);
	w = write(STDOUT_FILENO, buf, r);
	if (w == -1)
		return (0);
	close(fd);
	free(buf);
	return (r);
}
