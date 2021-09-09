#include "menger.h"

/**
 * print_simple - entry point
 **/
void print_simple(void)
{
	printf("###\n");
	printf("# #\n");
	printf("###\n");
}

/**
 * print_menger - entry point
 * @level: level
 **/
void print_menger(int level)
{
	double i, j;

	level = pow(3, level);

	for (i = 0; i < level / 3; i++)
		for (j = 0; j < level / 3; j++)
			printf("#");
}

/**
 * menger - entry point
 * @level: level
 **/
void menger(int level)
{
	if (level == 1)
		print_simple();
	else if (level == 0)
		printf("#\n");
	else if (level > 1)
		print_menger(level);
}
