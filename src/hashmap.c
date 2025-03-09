#include "hashmap.h"

int hashFunction(char key)
{
    key = toUpperCase(key);

    // Reduce the key into the range (0 - 25) for characters (A - Z)
    key -= 'A';

    // In this way, every alphabet can go into it's respective bucket of our map_ array
    return (key % 26);
}

void initHashMap(BookHashMap* hashmap)
{
    // Initialize the trees
    for(int i = 0; i < 26; i++){
        hashmap->map[i] = NULL;
    }
}

void insertBookInMap(BookHashMap* hashmap, Book* book)
{
    // HashMap needs to be allocated in main and sent over
    char key = getInitialBookChar(book);
    int value = hashFunction(key);

    insertBookInTree(&hashmap->map[value], book);
}

void listAllBooksInMap(BookHashMap* hashmap)
{
    for(int i = 0; i < 26; i++){
        printf("\n");
        printf("For books starting from letter %c:\n", i + 'A');

        if(hashmap->map[i] == NULL){
            continue;
        }

        displayBookTree(hashmap->map[i]);
        printf("\n");
    }
    printf("\n\n");
}

void listAllBooksInBucket(BookHashMap* hashmap, char letter){
    int value = hashFunction(letter);

    if(hashmap->map[value] == NULL){
        printf("No books in that bucket!");
        return;
    }
    displayBookTree(hashmap->map[value]);
};

Book* searchBookInBucket(BookHashMap* hashmap, char bookName[])
{
    int value = hashFunction(bookName[0]);

    return searchBookInTree(hashmap->map[value], bookName);
}

void freeHashMap(BookHashMap* hashmap)
{
    // Free all the buckets associated with the hashmap
    for(int i = 0; i < 26; i++){
        printf("\n");

        if(hashmap->map[i] == NULL){
            continue;
        }

        freeBookTree(hashmap->map[i]);

        printf("\n\n");
    }

    // Free Hashmap after freeing all the buckets
    free(hashmap);
}


// <------ UserHashMap Section ----->

void initUserHashMap(UserHashMap* hashmap)
{
    hashmap = (UserHashMap*)malloc(sizeof(UserHashMap));

    // Initialize the trees
    for(int i = 0; i < 26; i++){
        hashmap->map[i] = NULL;
    }
}