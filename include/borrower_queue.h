#ifndef BORROWER_QUEUE_H
#define BORROWER_QUEUE_H

#include<stdio.h>
#include "user.h"

typedef struct BorrowerQueue{
    BorrowerQueue* next;
    User* user;
} BorrowerQueue;

void initBorrowerQueue(Book*);
void enqueueUser(Book*, User*);
void dequeueUser(Book*);
void displayBorrowerQueue(Book*);

#endif