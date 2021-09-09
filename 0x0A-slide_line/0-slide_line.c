#include "slide_line.h"

/**
* move_left - move left
* @size2: array size
* @line: array
* Return: 1 ok, 0 no
**/
void move_left(int *line, int size2)
{
	int i, j = 0, sw = 0;

	for (i = 0; i < size2; i++)
	{
		if (line[i] != 0)
		{
			line[j] = line[i];
			j++;
		}
	}

	for (i = 0; i < size2 - 1; i++)
	{
		if (i < j && line[i] == line[i + 1])
		{
			sw = 1;
			line[i] += line[i + 1];
			line[i + 1] = 0;
		}
		else if (i >= j)
		{
			line[i] = 0;
		}
	}
	if (sw == 1 && j < size2)
		line[size2 - 1] = 0;
	j = 0;
	for (i = 0; i < size2; i++)
	{
		if (line[i] != 0)
		{
			line[j] = line[i];
			j++;
		}
	}
	for (i = j; i < size2; i++)
		line[i] = 0;
}
/**
* move_right - move right
* @size2: array size
* @line: array
* Return: 1 ok, 0 no
**/
void move_right(int *line, int size2)
{
	int i, j = size2 - 1, sw = 0;

	for (i = size2 - 1; i >= 0; i--)
	{
		if (line[i] != 0)
		{
			line[j] = line[i];
			j--;
		}
	}
	if (j >= 0)
		line[j] = 0;
	for (i = size2 - 1; i >= 0; i--)
	{
		if (i > j && line[i] == line[i - 1])
		{
			sw = 1;
			line[i] += line[i - 1];
			line[i - 1] = 0;
		}
		else if (i <= j)
		{
			line[i] = 0;
		}
	}
	if (sw == 1 && j >= 0)
		line[0] = 0;
	j = size2 - 1;
	for (i = size2 - 1; i >= 0; i--)
	{
		if (line[i] != 0)
		{
			line[j] = line[i];
			j--;
		}
	}
	for (i = 0; i <= j; i++)
		line[i] = 0;
}
/**
* slide_line - entry point
* @size: array size
* @direction: direction
* @line: array
* Return: 1 ok, 0 no
**/
int slide_line(int *line, size_t size, int direction)
{
	int size2 = size;

	if (direction == 1)
	{
		move_left(line, size2);
	}
	else if (direction == 0)
	{
		move_right(line, size2);
	}
	return (1);
}
