#include <stdio.h>
#include "hashmap.h"

int main() {
    int initialChoice = 0;
    int bookChoice = 0;
    int userChoice = 0;

    // Program UI: Library Management System
    while(1){
        // MENU
        printf("\n1. Book Management\n");
        printf("2. User Management\n");
        scanf("%d", &initialChoice);

        switch(initialChoice){
            case 1:
                printf("\n1. Insert Book\n");
                printf("2. Delete Book\n");
                printf("3. Search Book\n");
                printf("4. List All Books\n");
                scanf("%d", bookChoice);

                switch(bookChoice){

                }

            case 2:
                printf("\n1. Register User\n");
                printf("2. Delete User\n");
                printf("3. Search User\n");
                printf("4. List All Users\n");
                scanf("%d", userChoice);

                switch(userChoice){
                    
                }

            default:
                printf("Invalid Choice!");
        }
    }

    return 0;
}
