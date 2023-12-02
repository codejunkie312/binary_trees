#include "binary_trees.h"

/**
 * swap_values - swaps the values of two integers
 * @a: pointer to the first integer
 * @b: pointer to the second integer
 * Return: nothing
 */
void swap_values(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

/**
 * get_last_node - gets the last node of a binary tree
 * @root: pointer to the root node of the tree
 * Return: pointer to the last node, or NULL on failure
 */
heap_t *get_last_node(heap_t *root)
{
    if (root == NULL)
        return NULL;

    while (root->left != NULL || root->right != NULL)
    {
        if (root->right != NULL)
            root = root->right;
        else
            root = root->left;
    }

    return root;
}


/**
 * heapify_down - heapifies a binary tree
 * @root: pointer to the root node of the tree
 * Return: pointer to the last node, or NULL on failure
 */
void heapify_down(heap_t *root)
{
    heap_t *largest = root;
    heap_t *left = root->left;
    heap_t *right = root->right;

    if (left != NULL && left->n > largest->n)
        largest = left;

    if (right != NULL && right->n > largest->n)
        largest = right;

    if (largest != root)
    {
        swap_values(&(root->n), &(largest->n));
        heapify_down(largest);
    }
}


/**
 * heap_extract - extracts the root node of a Max Binary Heap
 * @root: double pointer to the root node of the heap
 * Return: value stored in the root node, or 0 on failure
 */
int heap_extract(heap_t **root)
{
    int extracted_value;
    heap_t *last_node;
    
    if (root == NULL || *root == NULL)
        return 0;

    extracted_value = (*root)->n;
    last_node = get_last_node(*root);

    if (*root == last_node)
    {
        free(*root);
        *root = NULL;
        return extracted_value;
    }

    (*root)->n = last_node->n;

    if (last_node->parent->left == last_node)
        last_node->parent->left = NULL;
    else
        last_node->parent->right = NULL;

    free(last_node);
    heapify_down(*root);

    return extracted_value;
}
