#include "binary_trees.h"
#include <stdlib.h>

#define MAX(a, b) ((a > b) ? a : b)

/**
 * avl_insert - Inserts a value in an AVL Tree.
 * @tree: Double pointer to the root node of the AVL tree.
 * @value: The value to store in the node to be inserted.
 *
 * Return: Pointer to the created node, or NULL on failure.
 */
avl_t *avl_insert(avl_t **tree, int value)
{
    if (tree == NULL)
        return NULL;

    /* Perform standard BST insert */
    if (*tree == NULL)
        return *tree = binary_tree_node(NULL, value);

    if (value < (*tree)->n)
        (*tree)->left = avl_insert(&((*tree)->left), value);
    else if (value > (*tree)->n)
        (*tree)->right = avl_insert(&((*tree)->right), value);
    else
        return NULL; /* Duplicate values are not allowed in AVL */

    /* Update height of the current node */
    (*tree)->height = 1 + MAX(binary_tree_height((*tree)->left), binary_tree_height((*tree)->right));

    /* Perform rotations to balance the tree */
    int balance = binary_tree_balance(*tree);

    /* Left Heavy */
    if (balance > 1) {
        if (value < (*tree)->left->n)
            return binary_tree_rotate_right(tree); /* Right-Right case */
        else {
            (*tree)->left = binary_tree_rotate_left(&((*tree)->left)); /* Left-Left case */
            return binary_tree_rotate_right(tree); /* Right-Right case */
        }
    }

    /* Right Heavy */
    if (balance < -1) {
        if (value > (*tree)->right->n)
            return binary_tree_rotate_left(tree); /* Left-Left case */
        else {
            (*tree)->right = binary_tree_rotate_right(&((*tree)->right)); /* Right-Right case */
            return binary_tree_rotate_left(tree); /* Left-Left case */
        }
    }

    return *tree;
}

