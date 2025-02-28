#ifndef HASHMAP_H
#define HASHMAP_H

#include<stdio.h>
#include "functions.h"
#include "book.h"
// #include "user.h"

// BookMap struct: Key based on starting alphabet
typedef struct BookHashMap
{
    BookTree* map[26];
} BookHashMap;

// Functions for BookMap
int hashFunction(char);
void insertBook(Book*);
void listAllBooks();
void listAllBooksInBucket();

// UserMap struct: Key based on starting alphabet
typedef struct UserHashMap
{
    UserTree* map[26];
} UserHashMap;

#endif