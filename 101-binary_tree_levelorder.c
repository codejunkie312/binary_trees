#include "binary_trees.h"

/**
 * enqueue - adds a new node at the end of a queue_t list
 * @head: pointer to the head of the queue_t list
 * @data: data to store in the new node
 * Return: pointer to the new node, or NULL on failure
 */
queue_t *enqueue(queue_t **head, void *data)
{
	queue_t *new_node = malloc(sizeof(queue_t));
	queue_t *last = *head;

	if (new_node == NULL)
		return (NULL);

	new_node->node = data;
	new_node->next = NULL;

	if (*head == NULL)
	{
		*head = new_node;
		return (new_node);
	}

	while (last->next != NULL)
		last = last->next;

	last->next = new_node;
	return (new_node);
}

/**
 * dequeue - Removes and returns the front element of a queue.
 * @head: pointer to the head of the queue_t list
 * Return: The front element of the queue.
*/
binary_tree_t *dequeue(queue_t **head)
{
	queue_t *tmp = *head;
	void *data = NULL;

	if (*head == NULL)
		return (NULL);

	data = (*head)->node;
	*head = (*head)->next;
	free(tmp);

	return (data);
}

/**
 * binary_tree_levelorder - goes through a binary tree using level-order
 * traversal
 * @tree: pointer to the root node of the tree to traverse
 * @func: pointer to a function to call for each node.
 * Return: nothing
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	queue_t *queue = NULL;
	binary_tree_t *current = NULL;

	if (tree == NULL || func == NULL)
		return;

	enqueue(&queue, (void *)tree);

	while (queue != NULL)
	{
		current = dequeue(&queue);
		func(current->n);

		if (current->left != NULL)
			enqueue(&queue, (void *)current->left);

		if (current->right != NULL)
			enqueue(&queue, (void *)current->right);
	}
}
