#include "binary_trees.h"

/**
 * binary_tree_is_full - Checks if a binary tree is full.
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: 1 if the tree is full, 0 otherwise. If tree is NULL, return 0.
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
    if (tree == NULL)
        return (0);

    /* If the current node has either zero or two children, continue checking */
    if ((tree->left == NULL && tree->right == NULL) ||
        (tree->left != NULL && tree->right != NULL))
    {
        /* Recursively check the left and right subtrees */
        return (binary_tree_is_full(tree->left) && binary_tree_is_full(tree->right));
    }

    /* If the current node has only one child, the tree is not full */
    return (0);
}

