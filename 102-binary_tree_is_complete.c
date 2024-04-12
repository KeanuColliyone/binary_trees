#include "binary_trees.h"

/**
 * binary_tree_is_complete - Checks if a binary tree is complete
 * @tree: Pointer to the root node of the tree to check
 * Return: 1 if tree is complete, 0 otherwise or if tree is NULL
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	const binary_tree_t **queue;
	size_t head = 0, tail = 0, queue_size = 256;
	int null_child_seen = 0;

	if (tree == NULL)
		return (0);
	queue = malloc(queue_size * sizeof(*queue));

	if (queue == NULL)
		return (0);
	queue[tail++] = tree;
	while (head < tail)
	{
		const binary_tree_t *current = queue[head++];

		if (current == NULL)
		{
			null_child_seen = 1;
		}
		else
		{
			if (null_child_seen)
			{
				free(queue);
				return (0);
			}
			if (tail + 2 > queue_size)
			{
				queue_size *= 2;
				queue = realloc(queue,
						queue_size * sizeof(*queue));
				if (queue == NULL)
					return (0);
			}
			queue[tail++] = current->left;
			queue[tail++] = current->right;
		}
	}
	free(queue);
	return (1);
}

