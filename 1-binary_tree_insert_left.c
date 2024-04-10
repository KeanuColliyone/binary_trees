#include "binary_trees.h"

/**
 * binary_tree_insert_left - Inserts a node as the left-child of another node
 * @parent: Pointer to the node to insert the left-child in
 * @value: The value to store in the new node
 *
 * Return: A pointer to the created node, or NULL on failure or if parent is NULL
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
    binary_tree_t *new_node;

    if (parent == NULL)
    {
        return (NULL); // Cannot insert into a NULL parent
    }

    // Allocate memory and initialize the new node
    new_node = malloc(sizeof(binary_tree_t));
    if (new_node == NULL)
    {
        return (NULL); // Memory allocation failed
    }

    new_node->n = value;
    new_node->parent = parent;
    new_node->left = parent->left; // New node's left child is parent's former left child
    new_node->right = NULL; // New node doesn't have a right child

    if (parent->left != NULL)
    {
        parent->left->parent = new_node; // Set the new node as the parent of the old left child
    }
    parent->left = new_node; // Set the new node as the left child of the parent

    return (new_node);
}

