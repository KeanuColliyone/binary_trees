#include "binary_trees.h"

/**
 * binary_trees_ancestor - Finds the lowest common ancestor of two nodes
 * @first: Pointer to the first node
 * @second: Pointer to the second node
 *
 * Return: Pointer to the lowest common ancestor node of the two given nodes
 *         If no common ancestor was found, return NULL
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	const binary_tree_t *node1, *node2;

	if (!first || !second)
		return (NULL);

	for (node1 = first; node1 != NULL; node1 = node1->parent)
	{
		for (node2 = second; node2 != NULL; node2 = node2->parent)
		{
			if (node1 == node2)
				return ((binary_tree_t *)node1);
		}
	}
	return (NULL);
}

