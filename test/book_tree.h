#ifndef BOOK_TREE_H
#define BOOK_TREE_H

#include<stdio.h>
#include<stdlib.h>

typedef struct AVLBook{
    int data;
    struct AVLBook* left;
    struct AVLBook* right;
    int height;
} AVLBook;

void insertBook(AVLBook**, int value);
AVLBook* deleteBook(AVLBook*, int value);
// AVLBook* searchBook(AVLBook*, int value);
void traverse(AVLBook*);
void displayBookTree(AVLBook*);
void freeTree(AVLBook*);

#endif