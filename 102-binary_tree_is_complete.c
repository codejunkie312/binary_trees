#include "binary_trees.h"

/**
 * enqueue_102 - adds a new node at the end of a queue_t list
 * @head: pointer to the head of the queue_t list
 * @data: data to store in the new node
 * Return: pointer to the new node, or NULL on failure
 */
queue_t *enqueue_102(queue_t **head, void *data)
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
 * dequeue_102 - Removes and returns the front element of a queue.
 * @head: pointer to the head of the queue_t list
 * Return: The front element of the queue.
*/
binary_tree_t *dequeue_102(queue_t **head)
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
 * binary_tree_is_complete - checks if a binary tree is complete
 * @tree: pointer to the root node of the tree to check
 *
 * Return: 1 if tree is complete, otherwise 0
 * If tree is NULL, return 0
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	queue_t *queue;
	binary_tree_t *node;
	int flag = 0;

	if (tree == NULL)
		return (0);
	
	queue = NULL;
	enqueue_102(&queue, (void *)tree);

	while (queue != NULL)
    {
        node = dequeue_102(&queue);

        if (node->left == NULL)
            flag = 1;
        else if (flag == 1)
            return (0);
        else
            enqueue_102(&queue, node->left);

        if (node->right == NULL)
            flag = 1;
        else if (flag == 1)
            return (0);
        else
            enqueue_102(&queue, node->right);
    }

    return (1);
}
