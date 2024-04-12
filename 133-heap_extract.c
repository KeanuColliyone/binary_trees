#include "binary_trees.h"

/**
 * get_tree_height - Get the height of a binary tree
 * @tree: A pointer to the root node of the tree
 * Return: The height of the tree
 */
size_t get_tree_height(const binary_tree_t *tree)
{
    size_t left_height, right_height;

    if (tree == NULL)
        return (0);

    left_height = get_tree_height(tree->left);
    right_height = get_tree_height(tree->right);

    return (1 + (left_height > right_height ? left_height : right_height));
}

/**
 * get_last_node - Get the last node in level order
 * @tree: A pointer to the root node of the tree
 * @height: The height of the tree
 * @level: The current level
 * Return: A pointer to the last node in level order
 */
binary_tree_t *get_last_node(binary_tree_t *tree, size_t height, size_t level)
{
    if (tree == NULL)
        return (NULL);

    if (level == height)
        return (tree);

    return get_last_node(tree->right, height, level + 1) ?
           get_last_node(tree->right, height, level + 1) :
           get_last_node(tree->left, height, level + 1);
}

/**
 * heapify_down - Fix the heap downwards from the root node
 * @root: A pointer to the root node of the heap
 */
void heapify_down(heap_t **root)
{
    binary_tree_t *current = *root;
    binary_tree_t *largest;
    int temp;

    while (1)
    {
        largest = current;
        if (current->left && current->left->n > largest->n)
            largest = current->left;
        if (current->right && current->right->n > largest->n)
            largest = current->right;
        if (largest == current)
            break;
        temp = current->n;
        current->n = largest->n;
        largest->n = temp;
        current = largest;
    }
}

/**
 * heap_extract - Extract the root node of a Max Binary Heap
 * @root: A double pointer to the root node of the heap
 * Return: The value stored in the root node
 */
int heap_extract(heap_t **root)
{
    binary_tree_t *last_node, *current;
    int value;

    if (root == NULL || *root == NULL)
        return (0);

    current = *root;
    value = current->n;
    last_node = get_last_node(*root, get_tree_height(*root), 1);

    if (last_node->parent)
    {
        if (last_node->parent->left == last_node)
            last_node->parent->left = NULL;
        else
            last_node->parent->right = NULL;
    }

    current->n = last_node->n;
    free(last_node);

    heapify_down(root);

    return (value);
}

