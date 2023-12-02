#include "binary_trees.h"

/**
 * count_nodes_134 - counts the number of nodes in a binary tree
 * @root: pointer to the root node of the tree to count the number of nodes
 * Return: number of nodes in a binary tree
 */
size_t count_nodes_134(heap_t *root)
{
	if (root == NULL)
		return (0);
	return (1 + count_nodes_134(root->left) + count_nodes_134(root->right));
}

/**
 * heap_to_sorted_array - converts a Binary Max Heap to a sorted array of
 * integers
 * @heap: pointer to the root node of the heap to convert
 * @size: address to store the size of the array
 * Return: pointer to the sorted array, or NULL on failure
 */
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
	int *array = NULL;
	size_t i;

	if (heap == NULL || size == NULL)
		return (NULL);

	*size = count_nodes_134(heap);

	array = malloc(sizeof(int) * (*size));
	if (array == NULL)
	{
		*size = 0;
		return (NULL);
	}

	for (i = 0; i < *size; ++i)
	{
		array[i] = heap_extract(&heap);
	}

	return (array);
}
