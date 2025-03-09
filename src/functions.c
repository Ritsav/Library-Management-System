#include "functions.h"

char toUpperCase(char ch)
{
    // Check if char is already in Uppercase
    if(ch >= 'A' && ch <= 'Z'){
        return ch;
    }

    // Operation for char being lowercase
    if(ch >= 'a' && ch <= 'z'){
        ch -= 32;
        return ch;
    }

    printf("\n\nRunTime Error: The starting char of the book title is not an alphabet!!\n\n");
    return -1;
}

// Function to insert book in the library
void insertBook(BookHashMap* hashmap, Book* book)
{
    insertBookInMap(hashmap, book);
}

// Function to delete book from the library
void deleteBook(BookHashMap* hashmap, char bookName[])
{
    int value = hashFunction(bookName[0]);
    deleteBookInTree(&hashmap->map[value], bookName);
}

// Function to search for book in library
Book* searchBook(BookHashMap* hashmap, char bookName[])
{
    return searchBookInBucket(hashmap, bookName);
}

// Function to update user info when borrowing book
void userBookBorrow(UserHashMap* hashmap, char userName[], Book* book)
{
    User* user = searchUserInBucket(hashmap, userName);

    // In the case that the user doesn't exist
    if(!user){
        printf("Register the user first!\n");
        return;
    }

    if(book->front != NULL){
        // For the case that book is not available and is currently taken by some other user
        if(!book->isAvailable){
            int choice;
            printf("The book has been taken by some other user currently.\n");

            // Displaying borrower's queue
            displayBorrowerQueue(book);
            printf("Would you like to add yourself to the borrower's queue?\n(Press 1 to accept & 2 to refuse)\n");
            scanf("%d", &choice);

            // Adding the user to the borrower's queue if accept
            if(choice == 1){
                enqueueUser(book, user);
            }
            return;
        }

        // For the case in which user from borrower's queue has come to take the book
        if(strcmp(book->front->user->name, user->name) == 0){
            dequeueUser(book);
        }
    }

    user->hasTakenBook = true;
    book->isAvailable = false;
    user->book = book;
    printf("Book has been issued to the %s.\n", user->name);
}

// Function to return book taken by user
void userBookReturn(UserHashMap* hashmap, char userName[])
{
    User* user = searchUserInBucket(hashmap, userName);

    // In case the user returning the book doesn't have an account or doesn't exist
    if(!user){
        printf("User record does not exist!\n");
        return;
    }

    // In case the user hadn't taken any books
    if(user->book == NULL){
        printf("The user had not issued/taken any book!");
        return;
    }

    user->hasTakenBook = false;
    user->book->isAvailable = true;
    printf("The book %s has been returned by the user.\n", user->book->name);
    user->book = NULL;
}

