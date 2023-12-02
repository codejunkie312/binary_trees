#include "binary_trees.h"

binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree);
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree);
int binary_tree_balance(const binary_tree_t *tree);

/**
 * min_value_123 - finds the minimum value in a binary tree
 * @tree: pointer to the root node of the tree to search
 * Return: pointer to the node containing the minimum value
 */
avl_t *min_value_123(avl_t *tree)
{
	avl_t *current = tree;

	while (current->left != NULL)
		current = current->left;

	return (current);
}

/**
 * rebalance - rebalances an AVL tree
 * @tree: double pointer to the root node of the AVL tree for rebalancing
 * Return: pointer to the new root node of the tree after rebalancing
 */
avl_t *rebalance(avl_t *tree)
{
	int balance;

	balance = binary_tree_balance(tree);
	if (balance > 1)
	{
		if (binary_tree_balance((tree)->left) < 0)
			(tree)->left = binary_tree_rotate_left((tree)->left);
		tree = binary_tree_rotate_right(tree);
	}
	else if (balance < -1)
	{
		if (binary_tree_balance((tree)->right) > 0)
			(tree)->right = binary_tree_rotate_right((tree)->right);
		tree = binary_tree_rotate_left(tree);
	}

	return (tree);
}

/**
 * avl_remove - removes a node from an AVL tree
 * @root: pointer to the root node of the tree for removing a node
 * @value: value to remove in the tree
 * Return: pointer to the new root node of the tree after removing the value
 */
avl_t *avl_remove(avl_t *root, int value)
{
	avl_t *temp;

	if (root == NULL)
		return (NULL);

	if (value < root->n)
		root->left = avl_remove(root->left, value);
	else if (value > root->n)
		root->right = avl_remove(root->right, value);
	else
	{
		if ((root->left == NULL) || (root->right == NULL))
		{
			temp = root->left ? root->left : root->right;

			if (temp == NULL)
			{
				temp = root;
				root = NULL;
			}
			else
			{
				*root = *temp;
			}
			free(temp);
		}
		else
		{
			temp = min_value_123(root->right);
			root->n = temp->n;
			root->right = avl_remove(root->right, temp->n);
		}
	}

	if (root == NULL)
		return (root);

	root = rebalance(root);

	return (root);
}
