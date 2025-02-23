#include "functions.h"

char func::toUpperCase(char ch)
{
    // Check if char is already in Uppercase
    if(ch >= 'A' && ch <= 'Z'){
        return ch;
    }

    // Operation for char being lowercase
    if(ch >= 'a' && ch <= 'z'){
        ch -= 32;
        return ch;
    }
    
    throw "The starting char of book title is not an alphabet";
}