#include "hashmap.h"

BookHashMap *BookMap;
UserHashMap *UserMap;

int hashFunction(char key)
{
    key = toUpperCase(key);   

    // Reduce the key into the range (0 - 25) for characters (A - Z)
    key -= 'A';

    // In this way, every alphabet can go into it's respective bucket of our map_ array
    return (key % 26);
}

// void insertBook(Book* book)
// {
//     int value = hashFunction(getInitialChar(book));

//     BookMap->map[value];
// }

void listAllBooks(Book* book)
{
    for(int i = 0; i < 26; i++){
        
    }
}

// void listAllBooksInBucket();