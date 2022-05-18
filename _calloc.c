#include "sshell.h"

/**
 * _calloc - concatenate tw strings specially
 * @nume: number of elements
 * @size: type of elements
 * Return: nothing
 */

void *_calloc(unsigned int nume, unsigned int size)
{
	void *p = NULL;
	unsigned int i;

	if (nume == 0 || size == 0)
	{
		return (NULL);
	}
	p = malloc(nume * size);
	if (p == NULL)
	{
		return (NULL);
	}
	for (i = 0; i < (nume * size); i++)
	{
		*((char *)(p) + i) = 0;
	}
	return (p);
}
