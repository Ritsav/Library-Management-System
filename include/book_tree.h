#include<stdio.h>
#include "book.h"
struct avl_book{
    Book* book;
    struct avl_book* left;
    struct avl_book* right;
    int height;
};
typedef struct avl_book AVLBook;
AVLBook* insertBook(AVLBook*, Book*);
AVLBook* deleteBook(AVLBook*, Book*);
AVLBook* searchBook(AVLBook*, Book*);
void displayBookTree(AVLBook*);
static int max(int a, int b);
static AVLBook* minValueNode(AVLBook* node);
static int getBalanceFactor(AVLBook* node);
static void updateHeight(AVLBook* node);
