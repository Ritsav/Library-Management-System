#include "bookList.h"

void insertBookList(bookList* head, Book* book) {
    bookList* current = head;
    
    // Find last node
    while(current->next != NULL){
        current = current->next;
    }

    // Create and attach new node
    bookList* newBook = malloc(sizeof(bookList));
    newBook->next = NULL;
    current->next = newBook;

    strcpy(newBook->bookName, book->name);
}

// Simplified display
void displayBookList(bookList* head) {
    while(head != NULL) {
        printf("%s -> ", head->bookName);
        head = head->next;
    }
    printf("NULL\n");
}
