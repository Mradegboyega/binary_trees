#include "binary_trees.h"

/**
 * binary_tree_sibling - Finds the sibling of a node in a binary tree.
 * @node: A pointer to the node to find the sibling.
 *
 * Return: A pointer to the sibling node. If node is NULL, the parent is NULL,
 * or the node has no sibling, return NULL.
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
    if (node == NULL || node->parent == NULL)
        return (NULL);

    /* Check if the node is the left child */
    if (node == node->parent->left)
        return (node->parent->right);

    /* Check if the node is the right child */
    if (node == node->parent->right)
        return (node->parent->left);

    /* If the node is neither the left nor right child, return NULL */
    return (NULL);
}

