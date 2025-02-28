#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "book.h"
#include "functions.h"

int main() {

    Book* book = initBook();

    char key = toUpperCase(book->name[0]);

    if (book) {
        displayBookInfo(book);
        free(book);  // Free dynamically allocated memory
    }

    return 0;
}
