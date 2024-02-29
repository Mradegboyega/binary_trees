#include "binary_trees.h"
#include <stdlib.h>

/**
 * avl_remove - Removes a node from an AVL tree.
 * @root: Pointer to the root node of the tree for removing a node.
 * @value: The value to remove in the tree.
 *
 * Return: Pointer to the new root node of the tree after removing the desired
 * value and after rebalancing.
 */
avl_t *avl_remove(avl_t *root, int value)
{
    if (root == NULL)
        return NULL;

    /* Perform regular BST delete */
    if (value < root->n)
        root->left = avl_remove(root->left, value);
    else if (value > root->n)
        root->right = avl_remove(root->right, value);
    else
    {
        /* Node with only one child or no child */
        if (root->left == NULL || root->right == NULL)
        {
            avl_t *temp = root->left ? root->left : root->right;

            /* No child case */
            if (temp == NULL)
            {
                temp = root;
                root = NULL;
            }
            else /* One child case */
                *root = *temp; /* Copy the contents of the non-empty child */

            free(temp);
        }
        else
        {
            /* Node with two children, get the in-order successor (smallest
               in the right subtree) */
            avl_t *temp = find_min(root->right);

            /* Copy the in-order successor's data to this node */
            root->n = temp->n;

            /* Delete the in-order successor */
            root->right = avl_remove(root->right, temp->n);
        }
    }

    /* If the tree had only one node, then return */
    if (root == NULL)
        return NULL;

    /* Update height of the current node */
    root->height = 1 + MAX(binary_tree_height(root->left), binary_tree_height(root->right));

    /* Get the balance factor of this node to check whether it became unbalanced */
    int balance = get_balance(root);

    /* If the node became unbalanced, then there are 4 cases */
    /* Left Left Case */
    if (balance > 1 && get_balance(root->left) >= 0)
        return rotate_right(root);

    /* Left Right Case */
    if (balance > 1 && get_balance(root->left) < 0)
    {
        root->left = rotate_left(root->left);
        return rotate_right(root);
    }

    /* Right Right Case */
    if (balance < -1 && get_balance(root->right) <= 0)
        return rotate_left(root);

    /* Right Left Case */
    if (balance < -1 && get_balance(root->right) > 0)
    {
        root->right = rotate_right(root->right);
        return rotate_left(root);
    }

    return root;
}

/* Helper function to find the node with the minimum value */
avl_t *find_min(avl_t *node)
{
    avl_t *current = node;

    /* Loop down to find the leftmost leaf */
    while (current->left != NULL)
        current = current->left;

    return current;
}

/* Helper function to get the balance factor of a node */
int get_balance(avl_t *node)
{
    if (node == NULL)
        return 0;

    return binary_tree_height(node->left) - binary_tree_height(node->right);
}

/* Helper function to perform right rotation */
avl_t *rotate_right(avl_t *y)
{
    avl_t *x = y->left;
    avl_t *T2 = x->right;

    /* Perform rotation */
    x->right = y;
    y->left = T2;

    /* Update heights */
    y->height = 1 + MAX(binary_tree_height(y->left), binary_tree_height(y->right));
    x->height = 1 + MAX(binary_tree_height(x->left), binary_tree_height(x->right));

    /* Return new root */
    return x;
}

/* Helper function to perform left rotation */
avl_t *rotate_left(avl_t *x)
{
    avl_t *y = x->right;
    avl_t *T2 = y->left;

    /* Perform rotation */
    y->left = x;
    x->right = T2;

    /* Update heights */
    x->height = 1 + MAX(binary_tree_height(x->left), binary_tree_height(x->right));
    y->height = 1 + MAX(binary_tree_height(y->left), binary_tree_height(y->right));

    /* Return new root */
    return y;
}

/* Helper function to get the maximum of two integers */
int MAX(int a, int b)
{
    return (a > b) ? a : b;
}

