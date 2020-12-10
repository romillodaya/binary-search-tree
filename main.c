#include <assert.h>
#include <stdlib.h>
#include "bst.h"
#include "bst.c"

void test_new(){
    BST tree1 = new_bst();
    BST *tree = &tree1;
    assert (count_element(tree)==0);
    tree = add_element(tree, 5);
    tree = add_element(tree, 4);
    tree = add_element(tree, 6);
    tree = add_element(tree, 3);
    assert (count_element(tree)==4);
    assert (search_element(tree,5)==1);
    assert (search_element(tree,4)==1);
    assert (search_element(tree,10)==0);

}

int main(){
    test_new();
    return 0;
}
 