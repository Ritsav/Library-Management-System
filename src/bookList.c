#include "book_list.h"

void initBookList(BookList* start)
{
    start = NULL;
}

void insertBookList(BookList* start, Book* book) {
    BookList* current = start;
    
    // Find last node
    while(current->next != NULL){
        current = current->next;
    }

    // Create and attach new node
    BookList* newBook = malloc(sizeof(BookList));
    newBook->next = NULL;
    current->next = newBook;

    strcpy(newBook->bookName, book->name);
}

// Simplified display
void displayBookList(BookList* start) {
    BookList* current = start;
    while(current != NULL) {
        printf("%s -> ", current->bookName);
        current = current->next;
    }
    printf("\n");
}
