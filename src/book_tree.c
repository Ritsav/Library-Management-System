

#include "book_tree.h"
#include "book.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



// Actual implementation
int max(int a, int b) {
    return (a > b) ? a : b;
}

AVLBook* createBookNode(Book* book) {
    AVLBook* newNode = (AVLBook*)malloc(sizeof(AVLBook));
    newNode->book = book;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->height = 1;
    return newNode;
}

int getHeight(AVLBook* node) {
    if (node == NULL) return 0;
    return node->height;
}

void updateHeight(AVLBook* node) {
    if (node == NULL) return;
    node->height = 1 + max(getHeight(node->left), getHeight(node->right));
}

int getBalanceFactor(AVLBook* node) {
    if (node == NULL) return 0;
    return getHeight(node->left) - getHeight(node->right);
}

AVLBook* rightRotate(AVLBook* y) {
    AVLBook* x = y->left;
    AVLBook* T2 = x->right;

    x->right = y;
    y->left = T2;

    updateHeight(y);
    updateHeight(x);

    return x;
}

AVLBook* leftRotate(AVLBook* x) {
    AVLBook* y = x->right;
    AVLBook* T2 = y->left;

    y->left = x;
    x->right = T2;

    updateHeight(x);
    updateHeight(y);

    return y;
}

AVLBook* insertBook(AVLBook* node, Book* book) {
    if (node == NULL) return createBookNode(book);

    int cmp = strcmp(book->name, node->book->name);
    if (cmp < 0)
        node->left = insertBook(node->left, book);
    else if (cmp > 0)
        node->right = insertBook(node->right, book);
    else
        return node; // Duplicate entries not allowed if cmp == 0

    updateHeight(node);

    int balance = getBalanceFactor(node);

    // Left Left Case
    if (balance > 1 && strcmp(book->name, node->left->book->name) < 0)
        return rightRotate(node);

    // Right Right Case
    if (balance < -1 && strcmp(book->name, node->right->book->name) > 0)
        return leftRotate(node);

    // Left Right Case
    if (balance > 1 && strcmp(book->name, node->left->book->name) > 0) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Right Left Case
    if (balance < -1 && strcmp(book->name, node->right->book->name) < 0) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

AVLBook* deleteBook(AVLBook* root, Book* book) {
    if (root == NULL) return root;

    int cmp = strcmp(book->name, root->book->name);
    if (cmp < 0)
        root->left = deleteBook(root->left, book);
    else if (cmp > 0)
        root->right = deleteBook(root->right, book);
    else {
        // Node with only one child or no child
        if ((root->left == NULL) || (root->right == NULL)) {
            AVLBook* temp = root->left ? root->left : root->right;

            if (temp == NULL) {
                temp = root;
                root = NULL;
            } else {
                *root = *temp;
            }
            free(temp);
        } else {
            // Node with two children
            AVLBook* temp = minValueNode(root->right);
            root->book = temp->book;
            root->right = deleteBook(root->right, temp->book);
        }
    }

    if (root == NULL) return root;

    updateHeight(root);

    int balance = getBalanceFactor(root);

    // Left Left
    if (balance > 1 && getBalanceFactor(root->left) >= 0)
        return rightRotate(root);

    // Left Right
    if (balance > 1 && getBalanceFactor(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // Right Right
    if (balance < -1 && getBalanceFactor(root->right) <= 0)
        return leftRotate(root);

    // Right Left
    if (balance < -1 && getBalanceFactor(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

AVLBook* minValueNode(AVLBook* node) {
    AVLBook* current = node;
    while (current->left != NULL)
        current = current->left;
    return current;
}

AVLBook* searchBook(AVLBook* root, Book* book) {
    if (root == NULL) return NULL;
    
    int cmp = strcmp(book->name, root->book->name);
    if (cmp == 0)
        return root;
    else if (cmp < 0)
        return searchBook(root->left, book);
    else
        return searchBook(root->right, book);
}

void displayBookTree(AVLBook* root) { // inorder traversal
    if (root != NULL) {
        displayBookTree(root->left);
        printf("Book: %s (Height: %d)\n", root->book->name, root->height);
        displayBookTree(root->right);
    }
}