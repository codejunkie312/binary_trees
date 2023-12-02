#include "binary_trees.h"

/**
 * is_complete - checks if a binary tree is complete
 * @tree: pointer to the root node of the tree to check
 * @index: index of the node
 * @number_nodes: number of nodes in the tree
 * Return: 1 if tree is complete, and 0 otherwise
 * If tree is NULL, return 0
 */
int is_complete(const binary_tree_t *tree, int index, int number_nodes)
{
	if (tree == NULL)
		return (1);

	if (index >= number_nodes)
		return (0);

	return (is_complete(tree->left, 2 * index + 1, number_nodes) &&
			is_complete(tree->right, 2 * index + 2, number_nodes));
}

/**
 * count_nodes - Helper function to count the number
 * of nodes in a binary tree
 * @tree: pointer to the root node of the tree to count the number of nodes
 * Return: number of nodes in a binary tree
*/
int count_nodes(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (1 + count_nodes(tree->left) + count_nodes(tree->right));
}

/**
 * is_max_heap - Helper function to check if a binary tree is a
 * valid Max Binary Heap
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if tree is a valid Max Binary Heap, and 0 otherwise
*/
int is_max_heap(const binary_tree_t *tree)
{
	if (tree->left == NULL && tree->right == NULL)
		return (1);

	if (tree->right == NULL)
		return (tree->n >= tree->left->n);

	if (tree->n >= tree->left->n && tree->n >= tree->right->n)
		return (is_max_heap(tree->left) && is_max_heap(tree->right));

	return (0);
}

/**
 * binary_tree_is_heap - checks if a binary tree is a valid Max Binary Heap
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if tree is a valid Max Binary Heap, and 0 otherwise
 * If tree is NULL, return 0
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
	int node_count, index = 0;

	if (tree == NULL)
		return (0);

	node_count = count_nodes(tree);

	if (is_complete(tree, index, node_count) && is_max_heap(tree))
		return (1);
	return (0);
}
