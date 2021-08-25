#include "lists.h"

/**
* is_palindrome - checks if a list is palindrome
* @head: pointer to the list
* Return: 0 if it is not a palindrome, 1 if it is a palindrome
**/
int is_palindrome(listint_t **head)
{
	listint_t *start = *head;
	int i = 0, j, t[10240];

	if (*head)
	{
		while (start != NULL)
		{
			t[i] = (*start).n;
			start = (*start).next;
			i++;
		}
		for (j = 0; j < i; j++)
		{
			if (t[j] != t[i - j - 1])
				return (0);
		}
	}
	return (1);
}
