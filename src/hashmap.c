#include "hashmap.h"

int hashFunction(char key)
{
    key = toUpperCase(key);   

    // Reduce the key into the range (0 - 25) for characters (A - Z)
    key -= 'A';

    // In this way, every alphabet can go into it's respective bucket of our map_ array
    return (key % 26);
}

void insertBookInMap(BookHashMap* hashmap, Book* book)
{
    // HashMap needs to be allocated in main and sent over
    int value = hashFunction(getInitialChar(book));

    if(hashmap->map[value] == NULL){
        AVLBook* root = (AVLBook*)malloc(sizeof(AVLBook));
        hashmap->map[value] = root;
    }

    insertBookInTree(hashmap->map[value], book);
}

void listAllBooksInMap(BookHashMap* hashmap)
{
    for(int i = 0; i < 26; i++){
        printf("\n");
        printf("For books starting from letter %c:\n", i + 'A');
        displayBookTree(hashmap->map[i]);
        printf("\n\n");
    }
}

void listAllBooksInBucket(BookHashMap* hashmap, char letter){
    displayBookTree(hashmap->map[hashFunction(letter)]);
};