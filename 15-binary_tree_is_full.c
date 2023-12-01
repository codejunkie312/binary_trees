#include "binary_trees.h"

/**
 * binary_tree_is_leaf_15 - checks if a node is a leaf
 * @node: pointer to the node to check
 *
 * Return: 1 if node is a leaf, otherwise 0
 * If node is NULL, return 0
 */
int binary_tree_is_leaf_15(const binary_tree_t *node)
{
	if (node == NULL)
		return (0);

	if ((node->left == NULL) && (node->right == NULL))
		return (1);
	else
		return (0);
}

/**
 * binary_tree_is_full - checks if a binary tree is full
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if tree is full, otherwise 0
 * If tree is NULL, return 0
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	int left_full, right_full;

	left_full = 0;
	right_full = 0;

	if (tree == NULL)
		return (0);

	if (binary_tree_is_leaf_15(tree))
		return (1);

	left_full = binary_tree_is_full(tree->left);
	right_full = binary_tree_is_full(tree->right);

	if (left_full && right_full)
		return (1);
	else
		return (0);
}
