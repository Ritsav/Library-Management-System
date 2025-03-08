#ifndef USER_H
#define USER_H

#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include "book.h"
#include "book_list.h"

typedef struct User{
    char name[50];
    char address[50];
    bool hasTakenBook;
    Book *book;
    BookList *bookCatalogStart;
} User;

User* initUser(); 
void displayCatalog(User*);
void displayUserInfo(User*);
char getInitialChar(User*);

#endif