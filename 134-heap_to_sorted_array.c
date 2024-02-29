#include "binary_trees.h"
#include <stdlib.h>

/**
 * heap_to_sorted_array - Converts a Binary Max Heap to a sorted array.
 * @heap: A pointer to the root node of the heap to convert.
 * @size: An address to store the size of the array.
 *
 * Return: A pointer to the sorted array of integers.
 */
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
    int *sorted_array;
    size_t i, heap_size;

    if (heap == NULL || size == NULL)
        return (NULL);

    heap_size = heap_count(heap);
    sorted_array = malloc(sizeof(int) * heap_size);
    if (sorted_array == NULL)
        return (NULL);

    for (i = 0; i < heap_size; i++)
        sorted_array[i] = heap_extract(&heap);

    *size = heap_size;
    return (sorted_array);
}

