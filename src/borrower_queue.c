#include "borrower_queue.h"

void initBorrowerQueue(Book* book)
{
    book->front = NULL;
    book->rear = NULL;
}

void enqueueUser(Book* book, User* user)
{
    BorrowerQueue* temp = (BorrowerQueue*)malloc(sizeof(BorrowerQueue));
    temp->user = user;

    // Deal with underflow
    if(book->front == book->rear){
        book->front = temp;
        book->rear = temp->next;
    }

    book->rear = temp;
    temp->next = book->rear;
}

void dequeueUser(Book* book)
{
    // Deal with underflow
    if(book->front == book->rear){
        printf("No users currently in the queue!");
        return;
    }

    BorrowerQueue* temp = book->front;
    
    book->front = book->front->next;
    free(temp);
}

void displayBorrowerQueue(Book* book)
{
    BorrowerQueue* temp = book->front;

    printf("<----- Borrower's Queue ----->\n");
    while(temp != book->rear){
        printf("%s-->\t", temp->user->name);
        temp = temp->next;
    }
    printf("\n");
}