#include<stdio.h>
#include "book_tree.h"

int main()
{
    AVLBook* root = NULL;
    insertBook(&root, 10);
    insertBook(&root, 12);
    insertBook(&root, 9);

    traverse(root);
    printf("\n");

    freeTree(root);
}