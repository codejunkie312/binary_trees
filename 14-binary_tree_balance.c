#include "binary_trees.h"

/**
 * binary_tree_height1 - measures the height of a binary tree
 * @tree: pointer to the root node of the tree
 * Return: height of the tree, or 0 if tree is NULL
 */
size_t binary_tree_height1(const binary_tree_t *tree)
{
	size_t left_height = 0;
	size_t right_height = 0;

	if (tree == NULL)
		return (0);

	if (tree->left)
		left_height = 1 + binary_tree_height1(tree->left);

	if (tree->right)
		right_height = 1 + binary_tree_height1(tree->right);

	return (left_height > right_height ? left_height : right_height);
}

/**
 * binary_tree_balance - measures the balance factor of a binary tree
 * @tree: pointer to the root node of the tree to measure the balance factor
 * Return: balance factor of the tree, or 0 if tree is NULL
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int left_height, right_height;

	if (tree == NULL)
		return (0);

	left_height = (tree->left) ? (int)binary_tree_height1(tree->left) : -1;
	right_height = (tree->right) ? (int)binary_tree_height1(tree->right) : -1;

	return (left_height - right_height);
}
