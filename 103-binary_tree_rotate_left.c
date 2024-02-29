#include "binary_trees.h"

/**
 * binary_tree_rotate_left - Performs a left-rotation on a binary tree.
 * @tree: A pointer to the root node of the tree to rotate.
 *
 * Return: A pointer to the new root node of the tree once rotated.
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
    binary_tree_t *new_root;

    if (tree == NULL || tree->right == NULL)
        return (NULL);

    new_root = tree->right; /* The right child becomes the new root */
    tree->right = new_root->left; /* Move left child of new root to right child of original root */

    if (new_root->left != NULL)
        new_root->left->parent = tree; /* Update parent pointer for the moved node */

    new_root->parent = tree->parent; /* Update parent pointer for new root */

    if (tree->parent != NULL)
    {
        if (tree->parent->left == tree)
            tree->parent->left = new_root; /* Update parent's left child */
        else
            tree->parent->right = new_root; /* Update parent's right child */
    }

    tree->parent = new_root; /* Update parent pointer for original root */
    new_root->left = tree; /* Set original root as the left child of new root */

    return (new_root);
}

