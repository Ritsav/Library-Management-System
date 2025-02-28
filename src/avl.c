#include<stdio.h>
#include<stdlib.h>
struct Node{
    int key;
    struct Node *left;
    struct Node *right;
    int height;
}
int height(struct Node *N){
    if(N==NULL)
        return 0;
    return N->height;
}
