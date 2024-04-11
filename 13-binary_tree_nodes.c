#include "binary_trees.h"

/**
 * binary_tree_nodes - Counts nodes with at least one child in a binary tree
 * @tree: Pointer to the root node of the tree to count nodes
 *
 * Return: Number of nodes with at least one child. If tree is NULL, return 0.
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t count_left, count_right;

	if (tree == NULL)
	{
		return (0);
	}

	count_left = binary_tree_nodes(tree->left);
	count_right = binary_tree_nodes(tree->right);

	if (tree->left != NULL || tree->right != NULL)
	{
		return (1 + count_left + count_right);
	}

	return (count_left + count_right);
}

