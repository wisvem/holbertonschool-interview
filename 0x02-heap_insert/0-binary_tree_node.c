#include "binary_trees.h"

/**
* binary_tree_node - Entry point
* @parent: parent node
* @value: data to create the new node
* Return: a new node
**/
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new;
	new = malloc(sizeof(binary_tree_t));
	if (new)
	{
		(*new).parent = parent;
		(*new).n = value;
		return (new);
	}

	return (NULL);
}
