#include "binary_trees.h"

/**
 * binary_tree_size - Measures the size of a binary tree
 * @tree: A pointer to the root node of the tree to measure the size
 * Return: The size of the tree, or 0 if tree is NULL
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
    if (tree == NULL)
        return (0);

    return (1 + binary_tree_size(tree->left) + binary_tree_size(tree->right));
}

/**
 * binary_tree_is_complete - Checks if a binary tree is complete
 * @tree: A pointer to the root node of the tree to check
 * @index: The index of the current node
 * @size: The number of nodes in the tree
 * Return: 1 if the tree is complete, otherwise 0
 */
int binary_tree_is_complete(const binary_tree_t *tree, size_t index, size_t size)
{
    if (tree == NULL)
        return (1);

    if (index >= size)
        return (0);

    return (binary_tree_is_complete(tree->left, 2 * index + 1, size) &&
            binary_tree_is_complete(tree->right, 2 * index + 2, size));
}

/**
 * binary_tree_is_heap - Checks if a binary tree is a valid Max Binary Heap
 * @tree: A pointer to the root node of the tree to check
 * Return: 1 if the tree is a valid Max Binary Heap, otherwise 0
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
    if (tree == NULL)
        return (0);

    if (!binary_tree_is_complete(tree, 0, binary_tree_size(tree)))
        return (0);

    if (tree->left && tree->left->n > tree->n)
        return (0);

    if (tree->right && tree->right->n > tree->n)
        return (0);

    return (binary_tree_is_heap(tree->left) && binary_tree_is_heap(tree->right));
}

