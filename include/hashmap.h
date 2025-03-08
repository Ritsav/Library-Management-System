#ifndef HASHMAP_H
#define HASHMAP_H

#include<stdio.h>
#include<stdlib.h>
#include "functions.h"
#include "book.h"
#include "book_tree.h"
// #include "user.h"

// BookMap struct: Key based on starting alphabet
typedef struct BookHashMap
{
    AVLBook* map[26];
} BookHashMap;

// Functions for BookMap
int hashFunction(char);
void insertBook(BookHashMap* ,Book*);
void listAllBooks(BookHashMap*);
void listAllBooksInBucket(BookHashMap*, char);

// UserMap struct: Key based on starting alphabet
typedef struct UserHashMap
{
    // UserTree* map[26];
} UserHashMap;

#endif