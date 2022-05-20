#include "sshell.h"

/**
 * _errorcd - writes the error
 * @p: input pointer
 * Return: nothing.
 */
void _errorcd(char **p)
{
	write(STDERR_FILENO, p[0], 2);
	write(STDERR_FILENO, ": can't cd to ", 14);
	write(STDERR_FILENO, p[1], _strlen(p[1]));
	write(STDERR_FILENO, "\n", 1);
}
/**
 * _errorexit - writes the error
 * @p: input pointer
 * Return: nothing.
 */
void _errorexit(char **p)
{
	write(STDERR_FILENO, p[0], 4);
	write(STDERR_FILENO, ": Illegal number: ", 18);
	write(STDERR_FILENO, p[1], _strlen(p[1]));
	write(STDERR_FILENO, "\n", 1);
}
/**
 * _errorhelp - writes the error
 * @p: input pointer
 * Return: nothing.
 */
void _errorhelp(char **p)
{
	write(STDERR_FILENO, p[0], 4);
	write(STDERR_FILENO, ": no help topics match '", 24);
	write(STDERR_FILENO, p[1], _strlen(p[1]));
	write(STDERR_FILENO, "'. Try 'help help' or 'man -k '", 31);
	write(STDERR_FILENO, p[1], _strlen(p[1]));
	write(STDERR_FILENO, "' or info '", 11);
	write(STDERR_FILENO, p[1], _strlen(p[1]));
	write(STDERR_FILENO, "'\n", 2);
}
/**
 * _errorgarbage - writes the error
 * @p: input pointer
 * Return: nothing.
 */
void _errorgarbage(char **p)
{
	write(STDERR_FILENO, p[0], _strlen(p[0]));
	write(STDERR_FILENO, ": not found\n", 13);
}
/**
 * _errorenv - writes the error
 * @p: input pointer
 * Return: nothing.
 */
void _errorenv(char **p)
{
	write(STDERR_FILENO, p[0], _strlen(p[0]));
	write(STDERR_FILENO, ": unable to add/rm variable ", 28);
	write(STDERR_FILENO, p[1], _strlen(p[1]));
	write(STDERR_FILENO, "\n", 1);
}
