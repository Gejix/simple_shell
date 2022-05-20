#include "sshell.h"
/**
 * gridfree - free a matrix
 * @grid: it is the matrix
 * @height: height of the matrix
 * Return: nothing
 */
void gridfree(char **grid, int height)
{
	int i;

	for (i = 0; i < height; i++)
	{
		free(grid[i]);
	}
	free(grid);
}
