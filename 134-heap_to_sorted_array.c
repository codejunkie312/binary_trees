#include "binary_trees.h"

/**
 * heap_to_sorted_array - converts a Binary Max Heap to a sorted array of
 * integers
 * @heap: pointer to the root node of the heap to convert
 * @size: address to store the size of the array
 * Return: pointer to the sorted array, or NULL on failure
 */
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
	size_t i = 0;
	int *sorted_array;

	if (heap == NULL || size == NULL)
		return (NULL);

	sorted_array = malloc(sizeof(int) * (*size));
	if (sorted_array == NULL)
		return (NULL);

	while (heap != NULL)
	{
		sorted_array[i] = heap_extract(&heap);
		i++;
	}
	*size = i;

	return (sorted_array);
}
