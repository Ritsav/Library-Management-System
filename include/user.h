#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include "book.h"
#include "bookList.h"

typedef struct User{
    char name[50];
    char address[50];
    bool hasTakenBook;
    Book *book;
    bookList *bookCatalog;
} User;

void displayCatalog(User*);
void displayUserInfo(User*);
char getInitialChar(User*);