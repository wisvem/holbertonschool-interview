#include "sandpiles.h"

/**
 * print_grid - Print 3x3 grid
 * @grid: 3x3 grid
 */
void print_grid(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}

/**
 * is_stable - entry point
 * @grid: 3x3 grid
 * Return: 0 stable, 1 unstable
 */
int is_stable(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid[i][j] > 3)
				return (1);
		}
	}
	return (0);
}

/**
 * sandpile - entry point
 * @grid1: grid1
 * @grid2: grid2
**/
void sandpile(int grid1[3][3], int grid2[3][3])
{
	int ok = 0, i, j;

	if (grid1[0][0] > 3)
		grid2[0][0] -= 4, grid2[0][1] += 1, grid2[1][0] += 1;
	if (grid1[0][1] > 3)
		grid2[0][1] -= 4, grid2[0][0] += 1, grid2[0][2] += 1, grid2[1][1] += 1;
	if (grid1[0][2] > 3)
		grid2[0][2] -= 4, grid2[0][1] += 1, grid2[1][2] += 1;
	if (grid1[1][0] > 3)
		grid2[1][0] -= 4, grid2[0][0] += 1, grid2[1][1] += 1, grid2[2][0] += 1;
	if (grid1[1][1] > 3)
	{
		grid2[1][1] -= 4, grid2[0][1] += 1, grid2[2][1] += 1, grid2[1][2] += 1;
		grid2[1][0] += 1;
	}
	if (grid1[1][2] > 3)
		grid2[1][2] -= 4, grid2[1][1] += 1, grid2[0][2] += 1, grid2[2][2] += 1;
	if (grid1[2][0] > 3)
		grid2[2][0] -= 4, grid2[2][1] += 1, grid2[1][0] += 1;
	if (grid1[2][1] > 3)
		grid2[2][1] -= 4, grid2[1][1] += 1, grid2[2][0] += 1, grid2[2][2] += 1;
	if (grid1[2][2] > 3)
		grid2[2][2] -= 4, grid2[2][1] += 1, grid2[1][2] += 1;

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			grid1[i][j] = grid2[i][j];
	ok = is_stable(grid1);
	if (ok == 1)
	{
		printf("=\n");
		print_grid(grid1);
		sandpile(grid1, grid2);
	}
}

/**
 * sandpiles_sum - entry point
 * @grid1: grid1
 * @grid2: grid2
**/
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			grid1[i][j] = grid1[i][j] + grid2[i][j], grid2[i][j] = grid1[i][j];

	if (is_stable(grid1))
	{
		printf("=\n");
		print_grid(grid1);
	}
	sandpile(grid1, grid2);
}
