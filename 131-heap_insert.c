#include "binary_trees.h"

/**
 * enqueue_131 - enqueues a binary tree node to a queue
 * @queue: double pointer to the queue to enqueue the node in
 * @node: pointer to the binary tree node to enqueue
 * Return: pointer to the created queue node, or NULL on failure
*/
queue_t *enqueue_131(queue_t **queue, binary_tree_t *node)
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
 * dequeue_131 - dequeues a binary tree node from a queue
 * @queue: double pointer to the queue to dequeue the node from
 * Return: pointer to the dequeued node, or NULL on failure
*/
binary_tree_t *dequeue_131(queue_t **queue)
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
 * insert_at_correct_position - inserts a node at the correct position
 * in a binary tree
 * @root: double pointer to the root node of the binary tree
 * @node: pointer to the node to insert
 * Return: nothing
*/
void insert_at_correct_position(heap_t **root, heap_t *node)
{
	queue_t *queue = NULL;
	binary_tree_t *temp;

	enqueue_131(&queue, *root);
	while (queue != NULL)
	{
		temp = dequeue_131(&queue);
		if (temp->left == NULL)
		{
			temp->left = node;
			node->parent = temp;
			break;
		}
		else
			enqueue_131(&queue, temp->left);
		if (temp->right == NULL)
		{
			temp->right = node;
			node->parent = temp;
			break;
		}
		else
			enqueue_131(&queue, temp->right);
	}

	while (queue != NULL)
		dequeue_131(&queue);
}

/**
 * heapify_up - heapifies a node up the Heap
 * @node: pointer to the node to heapify up
 * Return: pointer to the heapified node
*/
heap_t *heapify_up(heap_t *node)
{
	heap_t *current, *parent;
	int temp;

	current = node;
	while (current->parent != NULL)
	{
		parent = current->parent;
		if (parent->n < current->n)
		{
			temp = parent->n;
			parent->n = current->n;
			current->n = temp;
			current = parent;
		}
		else
			break;
	}
	return (current);
}


/**
 * heap_insert - inserts a value into a Max Binary Heap
 * @root: double pointer to the root node of the Heap
 * @value: value to store in the node to be inserted
 * Return: pointer to the inserted node, or NULL on failure
*/

heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new_node;

	if (root == NULL)
		return (NULL);

	new_node = binary_tree_node(NULL, value);
	if (new_node == NULL)
		return (NULL);

	if (*root == NULL)
	{
		*root = new_node;
		return (new_node);
	}

	insert_at_correct_position(root, new_node);
	heapify_up(new_node);

	return (new_node);
}
