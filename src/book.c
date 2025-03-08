#include "book.h"

char getInitialChar(Book* book)
{
    return book->name[0];
}

// Function to Create Book
Book* initBook()
{
    // Dynamically Allocate memory for book
    Book *book = (Book*)malloc(sizeof(Book));
    initBorrowerQueue(book);

    // Declaration of necessary Data Types
    int year;
    char name[50]; 
    char author[50]; 
    char genre[50];

    // Input Section
    printf("Enter name: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';  // Remove newline

    printf("Enter author: ");
    fgets(author, sizeof(author), stdin);
    author[strcspn(author, "\n")] = '\0';  // Remove newline

    printf("Enter genre: ");
    fgets(genre, sizeof(genre), stdin);
    genre[strcspn(genre, "\n")] = '\0';  // Remove newline

    printf("Enter year: ");
    scanf("%d", &year);
    getchar();  // Consume newline left by scanf

    // Struct member initialization section
    book->yearOfPublication = year;
    strcpy(book->name, name);
    strcpy(book->author, author);
    strcpy(book->genre, genre);

    printf("\n");
    return book;
}

// Function to display Book
void displayBookInfo(Book* book)
{
    printf("<----- Book Info ----->\n");
    printf("Title: %s\n", book->name);
    printf("Author: %s\n", book->author);
    printf("Genre: %s\n", book->genre);
    printf("Year Of Publication: %d\n", book->yearOfPublication);
    showBookStatus(book);
}

void showBookStatus(Book* book){
    printf("%s\n", (book->isAvailable ? "Available" : "Taken"));
}