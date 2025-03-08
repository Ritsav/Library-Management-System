#include "functions.h"

char toUpperCase(char ch)
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

    printf("\n\nRunTime Error: The starting char of the book title is not an alphabet!!\n\n");
    return -1;
}