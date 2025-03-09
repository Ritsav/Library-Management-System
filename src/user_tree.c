#include "user_tree.h"

// Function to get the maximum of two integers
int maxUser(int a,int b){
    return (a > b) ? a:b;
}
AVLUser* createUserNode(User* user) {
    AVLUser* newNode = (AVLUser*)malloc(sizeof(AVLUser));
    newNode->user = user;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->height = 1;
    return newNode;
}

int getHeight(AVLUser* node) {
    if (node == NULL) return 0;
    return node->height;
}

void updateHeightUser(AVLUser* node) {
    if (node == NULL) return;
    node->height = 1 + max(getHeight(node->left), getHeight(node->right));
}

int getBalanceFactorUser(AVLUser* node) {
    if (node == NULL) return 0;
    return getHeight(node->left) - getHeight(node->right);
}

AVLUser* rightRotate(AVLUser* y) {
    AVLUser* x = y->left;
    AVLUser* T2 = x->right;

    x->right = y;
    y->left = T2;

    updateHeightUser(y);
    updateHeightUser(x);

    return x;
}

AVLUser* leftRotate(AVLUser* x) {
    AVLUser* y = x->right;
    AVLUser* T2 = y->left;

    y->left = x;
    x->right = T2;

    updateHeightUser(x);
    updateHeightUser(y);

    return y;
}

void insertUserInTree(AVLUser** node, User* user) {
    if (*node == NULL) {
        *node = createUserNode(user); // Set the new node directly
        printf("The user is now registered in the system.\n");
        return;
    }

    int cmp = strcmp(user->name, (*node)->user->name);
    if (cmp < 0)
        insertUserInTree(&(*node)->left, user);  // Pass address of left child
    else if (cmp > 0)
        insertUserInTree(&(*node)->right, user);  // Pass address of right child
    else
        return; // Duplicate entries not allowed

    updateHeightUser(*node);

    int balance = getBalanceFactorUser(*node);

    // Left Left Case
    if (balance > 1 && strcmp(user->name, (*node)->left->user->name) < 0)
        *node = rightRotate(*node);

    // Right Right Case
    if (balance < -1 && strcmp(user->name, (*node)->right->user->name) > 0)
        *node = leftRotate(*node);

    // Left Right Case
    if (balance > 1 && strcmp(user->name, (*node)->left->user->name) > 0) {
        (*node)->left = leftRotate((*node)->left);
        *node = rightRotate(*node);
    }

    // Right Left Case
    if (balance < -1 && strcmp(user->name, (*node)->right->user->name) < 0) {
        (*node)->right = rightRotate((*node)->right);
        *node = leftRotate(*node);
    }
}

void deleteUserInTree(AVLUser** root, char userName[]) {
    if (*root == NULL) return;

    int cmp = strcmp(userName, (*root)->user->name);
    if (cmp < 0)
        deleteUserInTree(&(*root)->left, userName);
    else if (cmp > 0)
        deleteUserInTree(&(*root)->right, userName);
    else {
        // Node with only one child or no child
        if ((*root)->left == NULL || (*root)->right == NULL) {
            AVLUser* temp = (*root)->left ? (*root)->left : (*root)->right;

            if (temp == NULL) {
                temp = *root;
                *root = NULL;
            } else {
                *(*root) = *temp;
            }

            // Free the user data also
            free((*root)->user);
            free(temp);
        } else {
            // Node with two children
            AVLUser* temp = minValueNodeUser((*root)->right);
            (*root)->user = temp->user;
            deleteUserInTree(&(*root)->right, temp->user->name);
        }
    }

    if (*root == NULL) return;

    updateHeightUser(*root);

    int balance = getBalanceFactorUser(*root);

    // Left Left Case
    if (balance > 1 && getBalanceFactorUser((*root)->left) >= 0)
        *root = rightRotate(*root);

    // Left Right Case
    if (balance > 1 && getBalanceFactorUser((*root)->left) < 0) {
        (*root)->left = leftRotate((*root)->left);
        *root = rightRotate(*root);
    }

    // Right Right Case
    if (balance < -1 && getBalanceFactorUser((*root)->right) <= 0)
        *root = leftRotate(*root);

    // Right Left Case
    if (balance < -1 && getBalanceFactorUser((*root)->right) > 0) {
        (*root)->right = rightRotate((*root)->right);
        *root = leftRotate(*root);
    }
}

AVLUser* minValueNodeUser(AVLUser* node) {
    AVLUser* current = node;
    while (current->left != NULL)
        current = current->left;
    return current;
}

User* searchUserInTree(AVLUser* root, char userName[]) {
    if (root == NULL) {
        printf("\n\nUser not found in system!\n\n");
        return NULL;
    }
    
    int cmp = strcmp(userName, root->user->name);
    if (cmp == 0) {
        return root->user;  // Return the found user
    } 
    else if (cmp < 0) 
        return searchUserInTree(root->left, userName);  // Return recursive call result
    else 
        return searchUserInTree(root->right, userName);  // Return recursive call result
}

void displayUserTree(AVLUser* root) { // inorder traversal
    if (root != NULL) {
        displayUserTree(root->left);
        printf("\tUser: %s\t", root->user->name);
        displayUserTree(root->right);
    }
}

void freeUserTree(AVLUser* root){
    if(root == NULL) return;

    freeUserTree(root->left);
    
    free(root->user);
    free(root);
    
    freeUserTree(root->right);
}