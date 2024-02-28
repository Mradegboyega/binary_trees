#include "binary_trees.h"

/**
 * binary_tree_inorder - Goes through a binary tree using in-order traversal.
 * @tree: A pointer to the root node of the tree to traverse.
 * @func: A pointer to a function to call for each node.
 *
 * Description: The value in the node must be passed as a parameter to func.
 * If tree or func is NULL, do nothing.
 */
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
    if (tree == NULL || func == NULL)
        return;

    /* Recursively traverse the left subtree */
    binary_tree_inorder(tree->left, func);

    /* Call func on the current node's value */
    func(tree->n);

    /* Recursively traverse the right subtree */
    binary_tree_inorder(tree->right, func);
}

