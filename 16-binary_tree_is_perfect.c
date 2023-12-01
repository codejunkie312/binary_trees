#include "binary_trees.h"

/**
 * binary_tree_is_leaf_16 - checks if a node is a leaf
 * @node: pointer to the node to check
 *
 * Return: 1 if node is a leaf, otherwise 0
 * If node is NULL, return 0
 */
int binary_tree_is_leaf_16(const binary_tree_t *node)
{
	if (node == NULL)
		return (0);

	if ((node->left == NULL) && (node->right == NULL))
		return (1);
	else
		return (0);
}

/**
 * binary_tree_height_16 - measures the height of a binary tree
 * @tree: pointer to the root node of the tree
 * Return: height of the tree, or 0 if tree is NULL
 */
size_t binary_tree_height_16(const binary_tree_t *tree)
{
	size_t left_height, right_height;

	left_height = 0;
	right_height = 0;

	if (tree == NULL)
		return (0);

	if (binary_tree_is_leaf_16(tree))
		return (0);

	left_height = binary_tree_height_16(tree->left);
	right_height = binary_tree_height_16(tree->right);

	if (left_height > right_height)
		return (left_height + 1);
	else
		return (right_height + 1);
}

/**
 * binary_tree_is_full_16 - checks if a binary tree is full
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if tree is full, otherwise 0
 * If tree is NULL, return 0
 */
int binary_tree_is_full_16(const binary_tree_t *tree)
{
	int left_full, right_full;

	left_full = 0;
	right_full = 0;

	if (tree == NULL)
		return (0);

	if (binary_tree_is_leaf_16(tree))
		return (1);

	left_full = binary_tree_is_full_16(tree->left);
	right_full = binary_tree_is_full_16(tree->right);

	if (left_full && right_full)
		return (1);
	else
		return (0);
}

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: pointer to the root node of the tree to check
 *
 * Return: 1 if tree is perfect, otherwise 0
 * If tree is NULL, return 0
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t left_height, right_height;

	if (tree == NULL)
		return (0);

	left_height = binary_tree_height_16(tree->left);
	right_height = binary_tree_height_16(tree->right);

	if (left_height == right_height && binary_tree_is_full_16(tree))
		return (1);
	else
		return (0);
}
