#include "main.h"

#include <stdlib.h>

/**
 * alloc_grid - nested loop to make grid
 * @width: width input
 * @height: height input
 * Return: pointer to 2 dim. array
 */


int **alloc_grid(int width, int height)
{
	if (width <= 0 || height <= 0)
		return (NULL);

	int **grid = malloc(sizeof(int *) * height);

	if (grid == NULL)
		return (NULL);

	for (int i = 0; i < height; i++)
	{
		grid[i] = malloc(sizeof(int) * width);

		if (grid[i] == NULL)
		{
			for (int j = i - 1; j >= 0; j--)
				free(grid[j]);

			free(grid);
			return (NULL);
		}

		for (int j = 0; j < width; j++)
			grid[i][j] = 0;
	}

	return (grid);
}

