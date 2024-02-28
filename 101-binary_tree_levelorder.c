#include "binary_trees.h"
#include <stdio.h>

/**
 * binary_tree_levelorder - Goes through a binary tree using level-order traversal.
 * @tree: A pointer to the root node of the tree to traverse.
 * @func: A pointer to a function to call for each node.
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
    if (tree == NULL || func == NULL)
        return;

    /* Initialize a queue to store nodes at each level */
    const binary_tree_t *node;
    const binary_tree_t *queue[10000];
    int front = 0, rear = 0;

    /* Enqueue the root node */
    queue[rear++] = tree;

    /* Process nodes until the queue is empty */
    while (front < rear)
    {
        /* Dequeue a node and call the function on it */
        node = queue[front++];
        func(node->n);

        /* Enqueue the left child if it exists */
        if (node->left != NULL)
            queue[rear++] = node->left;

        /* Enqueue the right child if it exists */
        if (node->right != NULL)
            queue[rear++] = node->right;
    }
}

