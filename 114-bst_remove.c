#include "binary_trees.h"

/**
 * find_successor - Finds the in-order successor of a given node.
 * @node: A pointer to the node for which to find the successor.
 *
 * Return: A pointer to the in-order successor.
 */
bst_t *find_successor(bst_t *node)
{
    bst_t *successor = node->right;

    while (successor->left != NULL)
        successor = successor->left;

    return successor;
}

/**
 * bst_remove - Removes a node from a Binary Search Tree (BST).
 * @root: A pointer to the root node of the tree where to remove a node.
 * @value: The value to remove from the tree.
 *
 * Return: A pointer to the new root node of the tree after removing
 * the desired value.
 */
bst_t *bst_remove(bst_t *root, int value)
{
    if (root == NULL)
        return NULL;

    if (value < root->n)
        root->left = bst_remove(root->left, value);
    else if (value > root->n)
        root->right = bst_remove(root->right, value);
    else
    {
        /* Node with one child or no child */
        if (root->left == NULL)
        {
            bst_t *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            bst_t *temp = root->left;
            free(root);
            return temp;
        }

        /* Node with two children, get in-order successor (smallest
           in the right subtree) */
        bst_t *temp = find_successor(root);

        /* Copy the in-order successor's data to this node */
        root->n = temp->n;

        /* Delete the in-order successor */
        root->right = bst_remove(root->right, temp->n);
    }

    return root;
}

