#ifndef USER_TREE_H
#define USER_TREE_H

#include<stdio.h>
#include "user.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// AVLTree for books Structure
typedef struct AVLUser{
    Book* book;
    struct AVLUser* left;
    struct AVLUser* right;
    int height;
} AVLUser;

// Functions to perform Operations in the AVL tree
void insertUserInTree(AVLUser**, User*);
void deleteUserInTree(AVLUser**, char[]);
User* searchUserInTree(AVLUser*, char[]);
void displayUserTree(AVLUser*);
void freeUserTree(AVLUser*); // Also frees the book

// AVLTree Rebalancing Functions
static int maxUser(int a, int b);
static AVLUser* minValueNodeUser(AVLUser* node);
static int getBalanceFactorUser(AVLUser* node);
static void updateHeightUser(AVLUser* node);

#endif