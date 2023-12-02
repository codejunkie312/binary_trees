#include "binary_trees.h"

/**
 * enqueue_133 - enqueues a binary tree node to a queue
 * @queue: double pointer to the queue to enqueue the node in
 * @node: pointer to the binary tree node to enqueue
 * Return: pointer to the created queue node, or NULL on failure
*/
queue_t *enqueue_133(queue_t **queue, binary_tree_t *node)
{
	queue_t *new_node, *tmp;

	new_node = malloc(sizeof(queue_t));

	if (new_node == NULL)
		return (NULL);

	new_node->node = node;
	new_node->next = NULL;

	if (*queue == NULL)
		*queue = new_node;
	else
	{
		tmp = *queue;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new_node;
	}

	return (new_node);
}

/**
 * dequeue_133 - dequeues a binary tree node from a queue
 * @queue: double pointer to the queue to dequeue the node from
 * Return: pointer to the dequeued node, or NULL on failure
*/
binary_tree_t *dequeue_133(queue_t **queue)
{
	queue_t *tmp;
	binary_tree_t *node;

	if (*queue == NULL)
		return (NULL);

	tmp = *queue;
	*queue = (*queue)->next;
	node = tmp->node;
	free(tmp);
	return (node);
}

/**
 * get_last_node - gets the last node of a binary tree
 * @tree: pointer to the root node of the tree to traverse
 * Return: pointer to the last node, or NULL if tree is NULL
 */
heap_t *get_last_node(heap_t *tree)
{
	queue_t *queue = NULL;
	heap_t *node;

	if (tree == NULL)
		return (NULL);

	enqueue_133(&queue, tree);

	while (queue != NULL)
	{
		node = dequeue_133(&queue);
		if (node->left != NULL)
			enqueue_133(&queue, node->left);
		if (node->right != NULL)
			enqueue_133(&queue, node->right);
	}

	return (node);
}

/**
 * heapify_down - heapifies a binary tree
 * @root: pointer to the root node of the tree to heapify
 * Return: nothing
 */
void heapify_down(heap_t *root)
{
	heap_t *largest = root, *left = root->left, *right = root->right;
	int temp;

	if (left != NULL && left->n > largest->n)
		largest = left;
	if (right != NULL && right->n > largest->n)
		largest = right;

	if (largest != root)
	{
		temp = root->n;
		root->n = largest->n;
		largest->n = temp;
		heapify_down(largest);
	}
}

/**
 * heap_extract - extracts the root node of a Max Binary Heap
 * @root: double pointer to the root node of the heap
 * Return: value stored in the root node, or 0 if root is NULL
 */
int heap_extract(heap_t **root)
{
	int root_value;
	heap_t *last_node;

	if (*root == NULL || root == NULL)
		return (0);

	root_value = (*root)->n;
	last_node = get_last_node(*root);

	if (last_node != *root)
	{
		(*root)->n = last_node->n;

		if (last_node->parent->left == last_node)
			last_node->parent->left = NULL;
		else
			last_node->parent->right = NULL;

		free(last_node);
		heapify_down(*root);
	}
	else
	{
		free(*root);
		*root = NULL;
	}

	return (root_value);
}
