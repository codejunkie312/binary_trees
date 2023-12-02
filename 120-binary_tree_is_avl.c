#include "binary_trees.h"
#include <limits.h>

/**
 * height - measures the height of a binary tree
 * @tree: pointer to the root node of the tree
 * Return: height of the tree, or 0 if tree is NULL
 */
int height(const binary_tree_t *tree)
{
	int left_height, right_height;

	if (tree == NULL)
		return (0);
	left_height = height(tree->left);
	right_height = height(tree->right);
	if (left_height > right_height)
		return (left_height + 1);
	else
		return (right_height + 1);
}

/**
 * is_bst_helper_120 - checks if a binary tree is a valid Binary Search Tree
 * @tree: pointer to the root node of the tree to check
 * @min: pointer to the min value
 * @max: pointer to the max value
 * Return: 1 if tree is a valid BST, and 0 otherwise
*/

int is_bst_helper_120(const binary_tree_t *tree, int min, int max)
{
	int left_height, right_height;

	if (tree == NULL)
		return (1);

	if (tree->n < min || tree->n > max)
		return (0);
	left_height = height(tree->left);
	right_height = height(tree->right);
	if (left_height - right_height > 1 || right_height - left_height > 1)
		return (0);

	return (is_bst_helper_120(tree->left, min, tree->n - 1) &&
		is_bst_helper_120(tree->right, tree->n + 1, max));
}

/**
 * binary_tree_is_avl - checks if a binary tree is a valid AVL Tree
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if tree is a valid AVL Tree, and 0 otherwise
*/
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (is_bst_helper_120(tree, INT_MIN, INT_MAX));

}
