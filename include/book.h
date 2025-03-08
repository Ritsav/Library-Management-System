#ifndef BOOK_H
#define BOOK_H

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#include "borrower_queue.h"

typedef struct Book
{
    int yearOfPublication;
    char name[50];
    char genre[50];
    char author[50];
    bool isAvailable;
    BorrowerQueue* front;
    BorrowerQueue* rear;
} Book;

Book* initBook();
void displayBookInfo(Book*);
char getInitialChar(Book*);

#endif