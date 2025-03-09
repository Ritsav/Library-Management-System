#include <stdio.h>
#include "hashmap.h"
#include "functions.h"

int main() {
    // User input choices
    int initialChoice = 0;
    int bookChoice = 0;
    int userChoice = 0;

    // User defined types for functions
    BookHashMap* hashmap = (BookHashMap*)malloc(sizeof(BookHashMap));
    if(!hashmap){
        printf("Hashmap not initialized!");
        return -1;
    }
    initHashMap(hashmap);

    UserHashMap* usermap = (UserHashMap*)malloc(sizeof(UserHashMap));
    if (!usermap) {
        printf("User hashmap not initialized!\n");
        return -1;
    }
    initUserHashMap(usermap);
    
    // variables for operations
    char bookName[50];
    char userName[50];

    // Program UI: Library Management System
    while(1){
        // MENU
        printf("\n1. Book Management\n");
        printf("2. User Management\n");
        scanf("%d", &initialChoice);
        getchar();  // Consume newline left by scanf

        switch(initialChoice){
            case 1:
                printf("\n1. Insert Book\n");
                printf("2. Delete Book\n");
                printf("3. Search Book\n");
                printf("4. List All Books\n");
                printf("5. Borrow Book\n");
                printf("6. Return Book\n");
                scanf("%d", &bookChoice);
                getchar();  // Consume newline left by scanf

                switch(bookChoice){
                    case 1:
                        printf("\n<----- Enter Book Details ----->\n");

                        Book *book = (Book*)malloc(sizeof(Book));
                        // Dynamically Allocate memory for book
                        if (book == NULL) {
                            printf("Memory allocation failed!\n");
                            return -1; 
                        }

                        initBook(&book);
                        printf("HMMl");
                        insertBook(hashmap, book);
                        break;
                    
                    case 2:
                        printf("Enter the name of the book you want to delete: ");
                        fgets(bookName, sizeof(bookName), stdin);
                        bookName[strcspn(bookName, "\n")] = '\0';  // Remove newline

                        book = searchBookInBucket(hashmap, bookName);

                        if(book){
                            deleteBook(hashmap, bookName);
                            printf("%s has been deleted from the library records.\n", bookName);
                        } else{
                            printf("Book not found in library!\n");
                        }
                        break;

                    case 3:
                        printf("Enter the name of the book you want to search: ");
                        fgets(bookName, sizeof(bookName), stdin);
                        bookName[strcspn(bookName, "\n")] = '\0';  // Remove newline

                        book = searchBookInBucket(hashmap, bookName);
                        if(book){
                            displayBookInfo(book);
                        } else {
                            printf("Book not found in library!\n");
                        }
                        break;

                    case 4:
                        printf("\n<----- List of all books in Library ----->\n");
                        listAllBooksInMap(hashmap);
                        break;
                    
                    case 5:
                        printf("Enter the book the user wants to borrow: ");
                        fgets(bookName, sizeof(bookName), stdin);
                        bookName[strcspn(bookName, "\n")] = '\0';  // Remove newline

                        book = searchBookInBucket(hashmap, bookName);
                        if(book){
                            printf("Enter the name of the user borrowing the book: ");
                            fgets(userName, sizeof(userName), stdin);
                            userName[strcspn(userName, "\n")] = '\0'; // Remove newline

                            // userBookBorrow(usermap, userName, book);
                        } else{
                            printf("Book not found in library!\n");
                        }
                        break;

                    case 6:
                        printf("Enter the name of the user returning the book: ");
                        fgets(userName, sizeof(userName), stdin);
                        userName[strcspn(userName, "\n")] = '\0'; // Remove newline

                        // userBookReturn(usermap, userName);
                        break;
                    
                    default: printf("Enter a valid option!\n");
                }
                break;

            case 2:
                printf("\n1. Register User\n");
                printf("2. Delete User\n");
                printf("3. Search User\n");
                printf("4. List All Users\n");
                scanf("%d", &userChoice);

                switch(userChoice){
                    
                }
                break;

            default:
                printf("Invalid Choice!");
        }
    }

    return 0;
}
