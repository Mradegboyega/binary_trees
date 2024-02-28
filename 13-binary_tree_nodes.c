#include "binary_trees.h"

/**
 * binary_tree_nodes - Counts the nodes with at least 1 child in a binary tree.
 * @tree: A pointer to the root node of the tree to count the nodes.
 *
 * Return: Number of nodes with at least 1 child. If tree is NULL, return 0.
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
    if (tree == NULL)
        return (0);

    /* Check if the current node has at least 1 child */
    if (tree->left != NULL || tree->right != NULL)
    {
        /* Recursively count nodes in the left and right subtrees */
        size_t left_nodes = binary_tree_nodes(tree->left);
        size_t right_nodes = binary_tree_nodes(tree->right);

        /* Return the total number of nodes with at least 1 child */
        return (1 + left_nodes + right_nodes);
    }

    /* If the current node has no children, return 0 */
    return (0);
}

