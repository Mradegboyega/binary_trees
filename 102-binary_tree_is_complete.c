#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_is_complete - Checks if a binary tree is complete.
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: 1 if the tree is complete, 0 otherwise. If tree is NULL, return 0.
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
    const binary_tree_t **queue = NULL;
    size_t front = 0, rear = 0;
    int non_full_encountered = 0;

    if (tree == NULL)
        return (0);

    /* Allocate memory for the queue */
    queue = malloc(sizeof(binary_tree_t *) * 10000);
    if (queue == NULL)
        return (0);

    /* Enqueue the root node */
    queue[rear++] = tree;

    /* Process nodes until the queue is empty */
    while (front < rear)
    {
        const binary_tree_t *node = queue[front++];

        /* Check if a non-full node is encountered after a full node */
        if (node == NULL)
            non_full_encountered = 1;
        else
        {
            if (non_full_encountered)
            {
                free(queue);
                return (0);
            }

            /* Enqueue the left and right children */
            queue[rear++] = node->left;
            queue[rear++] = node->right;
        }
    }

    free(queue);
    return (1);
}

