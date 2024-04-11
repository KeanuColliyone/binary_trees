#include "binary_trees.h"

/**
 * binary_tree_postorder - Goes through binary tree with post-order traversal
 * @tree: Pointer to the root node of the tree to traverse
 * @func: Pointer to a function to call for each node's value
 *
 * Description: If tree or func is NULL, do nothing. Otherwise, recursively
 * traverse the tree in a post-order manner.
 */
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
	{
		return;
	}

	binary_tree_postorder(tree->left, func);
	binary_tree_postorder(tree->right, func);
	func(tree->n);
}

