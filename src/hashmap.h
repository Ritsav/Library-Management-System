#ifndef HASHMAP_H
#define HASHMAP_H

#include<iostream>
#include<memory>
#include "book.h"
#include "functions.h"

template<class T>
class HashMap{
public:
    void insert(std::shared_ptr<T> object)
    {
        // Need to get the initial character for retrieving the key to push our value to our hashmap
        int value = HashMap::hashFunction(object->getInitialChar()); 

        // TODO: GetInitialChar() must be defined in both Book & User Class
        
        map_[value] = object;
    }

    void listAllBucketObjects(int key) const
    {
        // Make a start pointer to point to the first value in the bucket
        auto start = map_[key];
        
        start->displayTree();
    }

    void listAllObjects() const
    {
        // Going through each value to display the AVL
        for(int i = 0; i < 26; i++){
            auto start = map_[i];
            start->displayTree();
        }

        // TODO: Make a method displayTree() to traverse the AVL
    }

private:
    int hashFunction(char key) const
    {
        key = func::toUpperCase(key);

        // Reduce the key into the range (0 - 25) for characters (A - Z)
        key -= 'A';

        // In this way, every alphabet can go into it's respective bucket of our map_ array
        return (key % 26);
    }

    std::shared_ptr<T> map_[26];
};

#endif