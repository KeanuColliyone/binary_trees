#include "binary_trees.h"

/**
 * sorted_array_to_avl - Builds an AVL tree from a sorted array
 * @array: Pointer to the first element of the array
 * @size: Number of elements in the array
 *
 * Return: Pointer to the root node of the AVL tree, or NULL on failure
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
    if (array == NULL || size == 0)
        return (NULL);

    return (sorted_array_to_avl_helper(array, 0, size - 1));
}

/**
 * sorted_array_to_avl_helper - Helper function to recursively build an AVL tree
 * @array: Pointer to the first element of the array
 * @start: Index of the first element of the current subarray
 * @end: Index of the last element of the current subarray
 *
 * Return: Pointer to the root node of the AVL tree, or NULL on failure
 */
avl_t *sorted_array_to_avl_helper(int *array, int start, int end)
{
    if (start > end)
        return (NULL);

    int mid = (start + end) / 2;
    avl_t *root = binary_tree_node(NULL, array[mid]);

    if (root == NULL)
        return (NULL);

    root->left = sorted_array_to_avl_helper(array, start, mid - 1);
    root->right = sorted_array_to_avl_helper(array, mid + 1, end);

    return (root);
}

