#include "binary_trees.h"

/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes
 * @first: pointer to the first node
 * @second: pointer to the second node
 *
 * Return: pointer to the lowest common ancestor node of the two given nodes
 * If no common ancestor was found, return NULL
 */

binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
					 const binary_tree_t *second)
{
	const binary_tree_t *temp1;
	const binary_tree_t *temp2;

	if (first == NULL || second == NULL)
		return (NULL);

	temp1 = first;
	temp2 = second;

	while (temp1 != temp2)
	{
		temp1 = temp1->parent;
		temp2 = temp2->parent;

		if (temp1 == NULL && temp2 == NULL)
			return (NULL);

		if (temp1 == NULL)
			temp1 = second;

		if (temp2 == NULL)
			temp2 = first;
	}

	return ((binary_tree_t *)temp1);
}
