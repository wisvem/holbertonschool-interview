#include "palindrome.h"

/**
* is_palindrome - checks if a list is palindrome
* @n: long int
* Return: 0 if it is not a palindrome, 1 if it is a palindrome
**/
int is_palindrome(unsigned long n)
{
	int m[10240];
	unsigned long x = 0, i;

	while (n > 0)
		m[x] = n % 10, n = n / 10, x++;
	for (i = 0; i < x / 2; i++)
		if (m[i] != m[x - 1 - i])
			return (0);
	return (1);
}
