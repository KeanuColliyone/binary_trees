#include "binary_trees.h"

/**
 * enqueue - Helper function to enqueue an item in the queue
 * @queue: pointer to the queue array
 * @tail: pointer to the end of the queue
 * @node: tree node to enqueue
 */
void enqueue(binary_tree_t ***queue, size_t *tail, binary_tree_t *node)
{
	(*queue)[(*tail)++] = node;
}

/**
 * dequeue - Helper function to dequeue an item from the queue
 * @queue: pointer to the queue array
 * @head: pointer to the start of the queue
 * @tail: updated when an item is dequeued
 * Return: Dequeued tree node
 */
binary_tree_t *dequeue(binary_tree_t ***queue, size_t *head, size_t *tail)
{
	if (*head == *tail)
	{
		return NULL;
	}
	return (*queue)[(*head)++];
}

/**
 * binary_tree_levelorder - Goes through a binary tree using level-order
 * @tree: pointer to the root node of the tree to traverse
 * @func: pointer to a function to call for each node's value
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	binary_tree_t **queue;
	size_t head = 0, tail = 0, queue_size = 256;

	if (tree == NULL || func == NULL)
		return;

	queue = malloc(queue_size * sizeof(*queue));
	if (queue == NULL)
		return;

	enqueue(&queue, &tail, (binary_tree_t *)tree);

	while (head < tail)
	{
		binary_tree_t *node = dequeue(&queue, &head, &tail);
		func(node->n);
		if (node->left != NULL)
			enqueue(&queue, &tail, node->left);
		if (node->right != NULL)
			enqueue(&queue, &tail, node->right);
	}
	free(queue);
}

