#include "lists.h"

/**
* check_cycle - checks if a singly linked list has a cycle in it
* @list: head of the list
* Return: 0 if there is no cycle, 1 if there is a cycle
**/
int check_cycle(listint_t *list)
{
	listint_t *slow = list, *normal = list;

	while ((slow != NULL) && (normal != NULL) && (*normal).next != NULL)
	{
		normal = normal->next->next;
		slow = (*slow).next;
		if (slow == normal)
			return (1);
	}
	return (0);
}
