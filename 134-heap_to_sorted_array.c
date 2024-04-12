#include "binary_trees.h"

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
 * heap_to_sorted_array - Convert a Max Binary Heap to a sorted array
 * @heap: A pointer to the root node of the heap
 * @size: A pointer to store the size of the array
 * Return: A pointer to the sorted array
 */
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
    int *array;
    size_t i;

    if (heap == NULL || size == NULL)
        return (NULL);

    *size = binary_tree_size(heap);
    array = malloc(sizeof(int) * (*size));
    if (array == NULL)
        return (NULL);

    for (i = 0; i < *size; i++)
    {
        array[i] = heap->n;
        if (heap->left && heap->right)
        {
            if (heap->left->n > heap->right->n)
            {
                heap->n = heap->left->n;
                heap = heap->left;
            }
            else
            {
                heap->n = heap->right->n;
                heap = heap->right;
            }
        }
        else if (heap->left)
        {
            heap->n = heap->left->n;
            heap = heap->left;
        }
        else if (heap->right)
        {
            heap->n = heap->right->n;
            heap = heap->right;
        }
        else
            break;
        heapify_down(&heap);
    }

    return (array);
}

