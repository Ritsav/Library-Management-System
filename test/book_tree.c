#include "book_tree.h"

void insertBook(AVLBook **node, int value){
    if(*node == NULL){
        *node = (AVLBook*)malloc(sizeof(AVLBook));
        (*node)->data = value;
        (*node)->left = NULL;
        (*node)->right = NULL;
        return;
    }

    if(value < (*node)->data){
        insertBook(&((*node)->left), value);
    } else{
        insertBook(&((*node)->right), value);
    }
}

void traverse(AVLBook* node){
    if(node == NULL){
        return;
    }

    traverse(node->left);

    printf(" | %d | ", node->data);

    traverse(node->right);
    
}

void freeTree(AVLBook* node){
    if(node == NULL) return;

    freeTree(node->left);
    freeTree(node->right);

    free(node);
}

// AVLBook* searchBook(AVLBook *node, int value){
//     if(node == NULL){
//         printf("Empty bucket!");
//         return;
//     }

//     searchBook(node->left, value);

//     printf(" | %d | ", node->data);

//     searchBook(node->right, value);
// }