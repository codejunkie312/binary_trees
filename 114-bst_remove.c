#include "binary_trees.h"

/**
 * min_value - finds the minimum value in a binary tree
 * @node: pointer to the root node of the tree to traverse
 *
 * Return: pointer to the node containing the minimum value
*/
bst_t *min_value(bst_t *node)
{
	bst_t *current = node;

	while (current && current->left != NULL)
		current = current->left;

	return (current);
}

/**
 * bst_remove - removes a node from a Binary Search Tree
 * @root: pointer to the root node of the tree where you will remove a node
 * @value: value to remove in the tree
 *
 * Return: pointer to the new root node of the tree after removing the desired
*/
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *temp;

	if (root == NULL)
		return (NULL);

	if (value < root->n)
		root->left = bst_remove(root->left, value);
	else if (value > root->n)
		root->right = bst_remove(root->right, value);
	else
	{
		if (root->left == NULL)
		{
			temp = root->right;
			free(root);
			return (temp);
		}
		else if (root->right == NULL)
		{
			temp = root->left;
			free(root);
			return (temp);
		}

		temp = min_value(root->right);
		root->n = temp->n;
		root->right = bst_remove(root->right, temp->n);
	}
	return (root);
}
