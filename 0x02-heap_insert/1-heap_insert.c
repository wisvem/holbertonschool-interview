#include "binary_trees.h"

/**
 * heap_insert - entry point
 * @root: root of tree
 * @value: value to insert
 * Return: return new nodes
**/
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new, *parent;

	if (root)
	{
		parent = *root;
		new = malloc(sizeof(heap_t));
		if (!new)
			return (NULL);
		(*new).n = value;
		(*new).left = NULL;
		(*new).right = NULL;
		if (parent == NULL)
		{
			*root = new;
			return (new);
		}

		return (new);
	}

	return (NULL);
}
