#include <stdint.h>
#ifndef BST_H_INCLUDED
#define BST_H_INCLUDED

typedef struct _bst_node_ BstNode;

struct _bst_node_
{
    int data;
    BstNode *left;
    BstNode *right;
};

typedef struct _bst_ BST;
struct _bst_
{
    BstNode *root;
    uint32_t mass;
};

BST        new_bst();
BST*       add_element(BST* tree,int element);
BST*       delete_element(BST* tree, int element);
uint8_t    search_element(BST* tree, int key);
uint16_t   count_element(BST* tree);

#endif