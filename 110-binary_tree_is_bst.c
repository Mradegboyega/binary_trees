#include "binary_trees.h"
#include <limits.h>

/**
 * binary_tree_is_bst - Checks if a binary tree is a valid Binary Search Tree.
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: 1 if tree is a valid BST, 0 otherwise. If tree is NULL, return 0.
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
    static int prev_value = INT_MIN;

    if (tree == NULL)
        return (1);

    /* Check the left subtree */
    if (!binary_tree_is_bst(tree->left))
        return (0);

    /* Check the current node's value */
    if (tree->n <= prev_value)
        return (0);
    prev_value = tree->n;

    /* Check the right subtree */
    if (!binary_tree_is_bst(tree->right))
        return (0);

    return (1);
}

