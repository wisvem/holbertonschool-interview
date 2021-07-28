#include "lists.h"

/**
 * insert_node - function to insert node sorted
 * @head: list head
 * @number: number to insert
 * Return: a new node
 **/
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *h;
	listint_t *new = NULL;
	listint_t *prev;

	if (head != NULL)
	{
		h = *head;
		prev = *head;
		while (h != NULL && (number > (*h).n))
		{
			prev = h;
			h = (*h).next;
		}
		new = malloc(sizeof(listint_t));
		if (new == NULL)
			return (NULL);
		(*new).n = number;
		if (prev == h)
		{
			(*new).next = prev;
			*head = new;
		}
		else
		{
			(*new).next = (*prev).next;
			(*prev).next = new;
		}
	}
	return (new);
}
