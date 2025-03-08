#ifndef BOOK_TREE_H
#define BOOK_TREE_H

#include<stdio.h>
#include "book.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// AVLTree for books Structure
struct avl_book{
    Book* book;
    struct avl_book* left;
    struct avl_book* right;
    int height;
};
typedef struct avl_book AVLBook;

// Functions to perform Operations in the AVL tree
void insertBookInTree(AVLBook**, Book*);
void deleteBookInTree(AVLBook**, Book*);
void searchBookInTree(AVLBook*, Book*);
void displayBookTree(AVLBook*);
void freeBookTree(AVLBook*);

// AVLTree Rebalancing Functions
static int max(int a, int b);
static AVLBook* minValueNode(AVLBook* node);
static int getBalanceFactor(AVLBook* node);
static void updateHeight(AVLBook* node);

#endif