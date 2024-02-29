#include "binary_trees.h"
#include <limits.h>

/**
 * binary_tree_height - Measures the height of a binary tree.
 * @tree: A pointer to the root node of the tree to measure the height.
 *
 * Return: The height of the tree, or 0 if tree is NULL.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
    size_t left_height, right_height;

    if (tree == NULL)
        return (0);

    left_height = binary_tree_height(tree->left);
    right_height = binary_tree_height(tree->right);

    return (1 + (left_height > right_height ? left_height : right_height));
}
/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL Tree.
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: 1 if tree is a valid AVL Tree, 0 otherwise.
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
    if (tree == NULL)
        return (0);

    /* Check BST property */
    if (!binary_tree_is_bst(tree))
        return (0);

    /* Check AVL property: balance factor for every node */
    size_t left_height = binary_tree_height(tree->left);
    size_t right_height = binary_tree_height(tree->right);
    if (left_height > right_height ? left_height - right_height : right_height - left_height > 1)
        return (0);

    /* Check AVL property for left and right subtrees */
    return (binary_tree_is_avl(tree->left) && binary_tree_is_avl(tree->right));
}

