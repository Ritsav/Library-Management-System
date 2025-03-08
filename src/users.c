#include "user.h"

void displayCatalog(User *s){
    displayBookInList();
}

void displayUserInfo(User *s){
    printf("Name of the user: %s\n", s->name);
    printf("Address: %s\n", s->address);
    printf("UserId: &d\n", s->userId);
    printf("Book taken: %s\n", (s->hasTakenBook ? "Yes" : "No"));
}

char getInitialChar(User *s) {
    return s->name[0];  
}
