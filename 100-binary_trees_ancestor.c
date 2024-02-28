#include "binary_trees.h"

/**
 * binary_trees_ancestor - Finds the lowest common ancestor of two nodes.
 * @first: A pointer to the first node.
 * @second: A pointer to the second node.
 *
 * Return: A pointer to the lowest common ancestor node. If no common ancestor
 * was found, return NULL.
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first, const binary_tree_t *second)
{
    const binary_tree_t *ancestor;

    if (first == NULL || second == NULL)
        return (NULL);

    /* Check if first is an ancestor of second */
    ancestor = first;
    while (ancestor != NULL)
    {
        if (ancestor == second)
            return ((binary_tree_t *)ancestor);
        ancestor = ancestor->parent;
    }

    /* Check if second is an ancestor of first */
    ancestor = second;
    while (ancestor != NULL)
    {
        if (ancestor == first)
            return ((binary_tree_t *)ancestor);
        ancestor = ancestor->parent;
    }

    return (NULL);
}

