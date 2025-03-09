#include "user.h"

// Function to create a new user record
User* initUser(){
    // Dynamically malloc memory
    User* user = (User*)malloc(sizeof(User));
    initBookList(user->bookCatalogStart);
    
    printf("Enter Name: ");
    fgets(user->name, sizeof(user->name), stdin);
    user->name[strcspn(user->name, "\n")] = '\0';  // Remove newline

    printf("Enter Address: ");
    fgets(user->address, sizeof(user->address), stdin);
    user->address[strcspn(user->address, "\n")] = '\0';
    printf("\n");

    return user;
}

// Function to display the history of books the user has read
void displayCatalog(User* user){
    displayBookList(user->bookCatalogStart);
}

// Function to display user
void displayUserInfo(User* user){
    printf("<----- User Info ----->\n");
    printf("Name: %s\n", user->name);
    printf("Address: %s\n", user->address);
    printf("Book taken: %s\n", (user->hasTakenBook ? "Yes" : "No"));

    if(user->hasTakenBook){
        printf("Book: %s\n", user->book->name);
    }
}

char getInitialChar(User* user) {
    return user->name[0];  
}
