#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of a binary tree.
 * @tree: A pointer to the root node of the tree to measure the height.
 *
 * Return: Height of the tree. If tree is NULL, return 0.
 */
size_t binary_tree_height(const binary_tree_t *tree);

/**
 * binary_tree_size - Measures the size of a binary tree.
 * @tree: A pointer to the root node of the tree to measure the size.
 *
 * Return: Size of the tree. If tree is NULL, return 0.
 */
size_t binary_tree_size(const binary_tree_t *tree);

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect.
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: 1 if the tree is perfect, 0 otherwise. If tree is NULL, return 0.
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
    size_t height, size, perfect_size;

    if (tree == NULL)
        return (0);

    /* Calculate the height and size of the tree */
    height = binary_tree_height(tree);
    size = binary_tree_size(tree);

    /* Calculate the perfect size based on the height */
    perfect_size = (1 << (height + 1)) - 1;

    /* Check if the tree has the perfect number of nodes */
    return (size == perfect_size);
}

