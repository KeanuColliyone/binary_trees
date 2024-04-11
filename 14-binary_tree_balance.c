#include "binary_trees.h"

/**
 * binary_tree_balance - Measures the balance factor of a binary tree
 * @tree: Pointer to the root node of the tree to measure the balance factor
 *
 * Return: The balance factor of the tree. If tree is NULL, return 0.
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int height_left, height_right;

	if (tree == NULL)
	{
		return (0);
	}

	height_left = tree->left ? binary_tree_height(tree->left) : 0;
	height_right = tree->right ? binary_tree_height(tree->right) : 0;

	return (height_left - height_right);
}

