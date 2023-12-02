#include "binary_trees.h"

/**
 * sorted_array_to_avl_helper - builds an AVL tree from an array
 * @array: pointer to the first element of the array to be converted
 * @start: start index of the subarray
 * @end: end index of the subarray
 * Return: pointer to the root node of the created AVL tree, or NULL on failure
 */
avl_t *sorted_array_to_avl_helper(int *array, int start, int end)
{
	avl_t *new_node = NULL;
	int mid;

	if (start > end)
		return (NULL);

	mid = (start + end) / 2;
	new_node = binary_tree_node(NULL, array[mid]);
	if (new_node == NULL)
		return (NULL);

	new_node->left = sorted_array_to_avl_helper(array, start, mid - 1);
	new_node->right = sorted_array_to_avl_helper(array, mid + 1, end);

	if (new_node->left != NULL)
		new_node->left->parent = new_node;
	if (new_node->right != NULL)
		new_node->right->parent = new_node;

	return (new_node);
}

/**
 * sorted_array_to_avl - builds an AVL tree from an array
 * @array: pointer to the first element of the array to be converted
 * @size: number of elements in the array
 * Return: pointer to the root node of the created AVL tree, or NULL on failure
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (array == NULL || size == 0)
		return (NULL);

	return (sorted_array_to_avl_helper(array, 0, size - 1));
}
