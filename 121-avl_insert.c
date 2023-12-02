#include "binary_trees.h"

binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree);
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree);
int binary_tree_balance(const binary_tree_t *tree);

/**
 * avl_insert_recursive - inserts a value in an AVL Tree
 * @tree: double pointer to the root node of the AVL
 * tree for inserting the value
 * @parent: pointer to the parent node
 * @new: double pointer to the created node
 * @val: value to store in the node to be inserted
 * Return: pointer to the created node, or NULL on failure
 */
avl_t *avl_insert_recursive(avl_t **tree, avl_t *parent, avl_t **new, int val)
{
	avl_t *inserted_node = NULL;

	if (*tree == NULL)
	{
		*tree = binary_tree_node(parent, val);
		if (*tree == NULL)
			return (NULL);
		*new = *tree;
		return (*tree);
	}

	if (val < (*tree)->n)
	{
		inserted_node = avl_insert_recursive(&((*tree)->left), *tree, new, val);
		if (inserted_node == NULL)
			return (NULL);
		if (binary_tree_balance(*tree) > 1)
		{
			if (val < (*tree)->left->n)
				*tree = binary_tree_rotate_right(*tree);
			else
			{
				(*tree)->left = binary_tree_rotate_left((*tree)->left);
				*tree = binary_tree_rotate_right(*tree);
			}
		}
	}
	else if (val > (*tree)->n)
	{
		inserted_node = avl_insert_recursive(&((*tree)->right), *tree, new, val);
		if (inserted_node == NULL)
			return (NULL);
		if (binary_tree_balance(*tree) < -1)
		{
			if (val > (*tree)->right->n)
				*tree = binary_tree_rotate_left(*tree);
			else
			{
				(*tree)->right = binary_tree_rotate_right((*tree)->right);
				*tree = binary_tree_rotate_left(*tree);
			}
		}
	}
	else
		return (NULL);

	return (inserted_node);
}

/**
 * avl_insert - inserts a value in an AVL Tree
 * @tree: double pointer to the root node of the AVL
 * tree for inserting the value
 * @value: value to store in the node to be inserted
 * Return: pointer to the created node, or NULL on failure
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *new_node = NULL;
	avl_t *inserted_node = NULL;

	inserted_node = avl_insert_recursive(tree, NULL, &new_node, value);

	return (inserted_node);
}
