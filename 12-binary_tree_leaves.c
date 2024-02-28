#include "binary_trees.h"

/**
 * binary_tree_leaves - Counts the leaves in a binary tree.
 * @tree: A pointer to the root node of the tree to count the leaves.
 *
 * Return: Number of leaves in the tree. If tree is NULL, return 0.
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
    if (tree == NULL)
        return (0);

    /* Check if the current node is a leaf */
    if (tree->left == NULL && tree->right == NULL)
        return (1);

    /* Recursively count leaves in the left and right subtrees */
    size_t left_leaves = binary_tree_leaves(tree->left);
    size_t right_leaves = binary_tree_leaves(tree->right);

    /* Return the total number of leaves */
    return (left_leaves + right_leaves);
}

