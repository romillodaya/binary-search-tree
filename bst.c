#include <stdlib.h>
#include <assert.h>
#include "bst.h"

BST  new_bst()
{
BST bst = {NULL, 0};
return bst;
}

uint16_t   count_element(BST* tree){
    assert(tree!=NULL);
    return tree->mass;
}

static  BstNode* _get_new_node_(int32_t ele){
    BstNode *newnode = (BstNode*)malloc(sizeof(BstNode));
    newnode->data = ele;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

BST*       add_element(BST* tree,int element)
{
    assert(tree != NULL);
    BstNode *current, *parent;
    current = parent = tree->root;

    while(current != NULL && element!= current->data){
        parent = current;
        if (element < current->data){
            current = current->left;
        }
        else if(element > current->data){
            current = current->right;
        }
    }

if (current == NULL){
    BstNode  *newnode = _get_new_node_(element);
    if (parent == NULL){
        tree->root = newnode;
    }
    else if(element < parent->data){
        parent->left = newnode;
    }
    else if(element > parent->data){
        parent->right = newnode;
    }
    ++tree->mass;
    return tree;
}

}

uint8_t    search_element(BST* tree, int key){
    assert(tree!=NULL);
    BstNode *current = tree->root;
    while(current!=NULL && key != current->data){
        if (key < current->data){
            current = current->left;
        }
        else if(key > current->data){
            current = current->right;
        }
    }
    return  (current != NULL);
}

BST*   delete_element(BST* tree, int element){
    assert(tree != NULL);
    tree->root = _delete_(tree, tree->root, element);
    return tree;
}

