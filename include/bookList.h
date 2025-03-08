#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "book.h"


typedef struct bookList
{
   struct bookList *next;
   char bookName[50];
}bookList;

void insertBookList(bookList*, Book*);
void displayBookList(bookList*);
