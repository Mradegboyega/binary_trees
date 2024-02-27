#ifndef BINARY_TREES_H
#define BINARY_TREES_H

#include <stdlib.h>

/**
 * struct binary_tree_s - Basic binary tree node structure
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
struct binary_tree_s
{
    int n;
    struct binary_tree_s *parent;
    struct binary_tree_s *left;
    struct binary_tree_s *right;
};

/* Typedefs for different types of binary trees */
void binary_tree_print(const binary_tree_t *);
typedef struct binary_tree_s binary_tree_t; /* Basic Binary Tree */
typedef struct binary_tree_s bst_t;         /* Binary Search Tree */
typedef struct binary_tree_s avl_t;         /* AVL Tree */
typedef struct binary_tree_s heap_t;        /* Max Binary Heap */

/* Function prototypes and other definitions can go here */

#endif /* BINARY_TREES_H */

