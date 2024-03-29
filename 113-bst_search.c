#include "binary_trees.h"

/**
 * bst_search - Searches for a value in a Binary Search Tree (BST).
 * @tree: A pointer to the root node of the BST to search.
 * @value: The value to search for in the tree.
 *
 * Return: A pointer to the node containing a value equals to `value`,
 * or NULL if not found or if `tree` is NULL.
 */
bst_t *bst_search(const bst_t *tree, int value)
{
    if (tree == NULL)
        return (NULL);

    if (value == tree->n)
        return ((bst_t *)tree);
    else if (value < tree->n)
        return (bst_search(tree->left, value));
    else
        return (bst_search(tree->right, value));
}

