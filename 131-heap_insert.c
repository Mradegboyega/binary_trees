#include "binary_trees.h"
#include <stdlib.h>

/**
 * heap_insert - Inserts a value in a Max Binary Heap.
 * @root: A double pointer to the root node of the Heap.
 * @value: The value to store in the new node.
 *
 * Return: A pointer to the created node, or NULL on failure.
 */
heap_t *heap_insert(heap_t **root, int value)
{
    heap_t *new_node, *parent;

    if (root == NULL)
        return (NULL);

    new_node = binary_tree_node(NULL, value);
    if (new_node == NULL)
        return (NULL);

    if (*root == NULL)
    {
        *root = new_node;
        return (new_node);
    }

    parent = find_insertion_point(*root);
    if (parent->left == NULL)
        parent->left = new_node;
    else
        parent->right = new_node;

    new_node->parent = parent;
    heapify_up(new_node);

    return (new_node);
}

/**
 * find_insertion_point - Finds the insertion point for a new node.
 * @root: A pointer to the root node.
 *
 * Return: A pointer to the parent node where the new node should be inserted.
 */
heap_t *find_insertion_point(heap_t *root)
{
    int left_height, right_height;

    left_height = binary_tree_height(root->left);
    right_height = binary_tree_height(root->right);

    if (left_height <= right_height)
    {
        if (binary_tree_is_perfect(root->left, left_height - 1))
            return (find_insertion_point(root->left));
        return (root);
    }
    else
    {
        if (binary_tree_is_perfect(root->right, right_height - 1))
            return (find_insertion_point(root->right));
        return (root);
    }
}

/**
 * binary_tree_height - Measures the height of a binary tree.
 * @tree: A pointer to the root node of the tree.
 *
 * Return: The height of the tree.
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
 * binary_tree_is_perfect - Checks if a binary tree is perfect.
 * @tree: A pointer to the root node of the tree.
 * @height: The height of the tree.
 *
 * Return: 1 if the tree is perfect, 0 otherwise.
 */
int binary_tree_is_perfect(const binary_tree_t *tree, size_t height)
{
    if (tree == NULL)
        return (height == 0);

    if (tree->left == NULL && tree->right == NULL)
        return (height == 1);

    if (tree->left == NULL || tree->right == NULL)
        return (0);

    return (binary_tree_is_perfect(tree->left, height - 1) &&
            binary_tree_is_perfect(tree->right, height - 1));
}

/**
 * heapify_up - Maintains the Max Heap property by fixing the tree upwards.
 * @node: A pointer to the newly inserted node.
 */
void heapify_up(heap_t *node)
{
    heap_t *current = node;

    while (current->parent != NULL && current->n > current->parent->n)
    {
        swap_values(current, current->parent);
        current = current->parent;
    }
}

/**
 * swap_values - Swaps the values of two nodes.
 * @node1: A pointer to the first node.
 * @node2: A pointer to the second node.
 */
void swap_values(heap_t *node1, heap_t *node2)
{
    int temp;

    temp = node1->n;
    node1->n = node2->n;
    node2->n = temp;
}

