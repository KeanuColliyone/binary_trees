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
 * heap_insert - Inserts a value in Max Binary Heap
 * @root: A double pointer to the root node of the Heap to insert the value
 * @value: The value to store in the node to be inserted
 * Return: A pointer to the created node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
    heap_t *new_node, *parent;
    size_t size, index;
    int mask;

    if (root == NULL)
        return (NULL);

    if (*root == NULL)
    {
        *root = binary_tree_node(NULL, value);
        return (*root);
    }

    size = binary_tree_size(*root);
    index = size + 1;
    new_node = binary_tree_node(NULL, value);
    if (new_node == NULL)
        return (NULL);

    while (index > 1)
    {
        parent = *root;
        mask = (int)(index >> 1) ^ (int)index;
        while (mask)
        {
            if (mask & 1)
                parent = parent->right;
            else
                parent = parent->left;
            mask >>= 1;
        }
        if (parent->n < value)
        {
            new_node->n = parent->n;
            parent->n = value;
            value = new_node->n;
        }
        index >>= 1;
    }

    if (index == 1 && (*root)->n < value)
    {
        new_node->n = (*root)->n;
        (*root)->n = value;
        value = new_node->n;
    }

    return (new_node);
}

