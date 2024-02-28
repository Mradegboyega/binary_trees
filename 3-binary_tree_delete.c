#include "binary_trees.h"

/**
 * binary_tree_delete - Deletes an entire binary tree.
 * @tree: A pointer to the root node of the tree to delete.
 *
 * Description: Uses post-order traversal to delete nodes from the bottom up.
 */
void binary_tree_delete(binary_tree_t *tree)
{
    if (tree == NULL)
        return;

    /* First, delete both subtrees */
    binary_tree_delete(tree->left);
    binary_tree_delete(tree->right);

    /* Then, delete the current node */
    free(tree);
}

