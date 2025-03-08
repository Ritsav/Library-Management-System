#include "book_tree.h"

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

void insertBookInTree(AVLBook** node, Book* book) {
    if (*node == NULL) {
        *node = createBookNode(book); // Set the new node directly
        return;
    }

    int cmp = strcmp(book->name, (*node)->book->name);
    if (cmp < 0)
        insertBookInTree(&(*node)->left, book);  // Pass address of left child
    else if (cmp > 0)
        insertBookInTree(&(*node)->right, book);  // Pass address of right child
    else
        return; // Duplicate entries not allowed

    updateHeight(*node);

    int balance = getBalanceFactor(*node);

    // Left Left Case
    if (balance > 1 && strcmp(book->name, (*node)->left->book->name) < 0)
        *node = rightRotate(*node);

    // Right Right Case
    if (balance < -1 && strcmp(book->name, (*node)->right->book->name) > 0)
        *node = leftRotate(*node);

    // Left Right Case
    if (balance > 1 && strcmp(book->name, (*node)->left->book->name) > 0) {
        (*node)->left = leftRotate((*node)->left);
        *node = rightRotate(*node);
    }

    // Right Left Case
    if (balance < -1 && strcmp(book->name, (*node)->right->book->name) < 0) {
        (*node)->right = rightRotate((*node)->right);
        *node = leftRotate(*node);
    }
}

void deleteBookInTree(AVLBook** root, Book* book) {
    if (*root == NULL) return;

    int cmp = strcmp(book->name, (*root)->book->name);
    if (cmp < 0)
        deleteBookInTree(&(*root)->left, book);  // Pass address of left child
    else if (cmp > 0)
        deleteBookInTree(&(*root)->right, book);  // Pass address of right child
    else {
        // Node with only one child or no child
        if ((*root)->left == NULL || (*root)->right == NULL) {
            AVLBook* temp = (*root)->left ? (*root)->left : (*root)->right;

            if (temp == NULL) {
                temp = *root;
                *root = NULL;
            } else {
                *(*root) = *temp;
            }

            // Free the book data also
            free((*root)->book);
            free(temp);
        } else {
            // Node with two children
            AVLBook* temp = minValueNode((*root)->right);
            (*root)->book = temp->book;
            deleteBookInTree(&(*root)->right, temp->book);
        }
    }

    if (*root == NULL) return;

    updateHeight(*root);

    int balance = getBalanceFactor(*root);

    // Left Left Case
    if (balance > 1 && getBalanceFactor((*root)->left) >= 0)
        *root = rightRotate(*root);

    // Left Right Case
    if (balance > 1 && getBalanceFactor((*root)->left) < 0) {
        (*root)->left = leftRotate((*root)->left);
        *root = rightRotate(*root);
    }

    // Right Right Case
    if (balance < -1 && getBalanceFactor((*root)->right) <= 0)
        *root = leftRotate(*root);

    // Right Left Case
    if (balance < -1 && getBalanceFactor((*root)->right) > 0) {
        (*root)->right = rightRotate((*root)->right);
        *root = leftRotate(*root);
    }
}

AVLBook* minValueNode(AVLBook* node) {
    AVLBook* current = node;
    while (current->left != NULL)
        current = current->left;
    return current;
}

void searchBookInTree(AVLBook* root, Book* book) {
    if (root == NULL){
        printf("\n\nBook not found in library!\n\n");
        return;
    }
    
    int cmp = strcmp(book->name, root->book->name);
    if (cmp == 0)
        displayBookInfo(book);
    else if (cmp < 0)
        searchBookInTree(root->left, book);
    else
        searchBookInTree(root->right, book);
}

void displayBookTree(AVLBook* root) {
    if (root != NULL) {
        displayBookTree(root->left);
        printf("Book: %s (Height: %d)\n", root->book->name, root->height);
        displayBookTree(root->right);
    }
}

void freeBookTree(AVLBook* root){
    if(root == NULL) return;

    freeBookTree(root->left);

    free(root->book);
    free(root);

    freeBookTree(root->right);
}