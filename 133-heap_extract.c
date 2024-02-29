#include "binary_trees.h"
#include <stdlib.h>

/**
 * heap_extract - Extracts the root node of a Max Binary Heap.
 * @root: A double pointer to the root node of the heap.
 *
 * Return: The value stored in the root node.
 */
int heap_extract(heap_t **root)
{
    int value;

    if (root == NULL || *root == NULL)
        return (0);

    value = (*root)->n;

    /* Find the last node */
    while ((*root)->left != NULL || (*root)->right != NULL)
    {
        if ((*root)->right == NULL || (*root)->left->n > (*root)->right->n)
        {
            (*root)->n = (*root)->left->n;
            *root = (*root)->left;
        }
        else
        {
            (*root)->n = (*root)->right->n;
            *root = (*root)->right;
        }
    }

    /* Delete the last node */
    if ((*root)->parent != NULL)
    {
        if ((*root)->parent->left == *root)
            (*root)->parent->left = NULL;
        else
            (*root)->parent->right = NULL;

        free(*root);
        *root = NULL;
    }
    else
    {
        free(*root);
        *root = NULL;
    }

    /* Rebuild the heap */
    if (*root != NULL)
        heapify_down(*root);

    return (value);
}

