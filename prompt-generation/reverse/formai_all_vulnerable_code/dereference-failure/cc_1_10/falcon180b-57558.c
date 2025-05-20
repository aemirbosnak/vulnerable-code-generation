//Falcon-180B DATASET v1.0 Category: Memory management ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct{
    void *ptr;
    size_t size;
    int free;
}block;

block *freeList = (void*)0;

void init(){
    freeList = (block*)malloc(sizeof(block));
    freeList->ptr = (void*)0;
    freeList->size = 0;
    freeList->free = 1;
}

void* myMalloc(size_t size){
    block *curr, *prev = (void*)0;
    void *ret;

    curr = freeList;

    while((curr->size < size) && (curr!= (void*)0)){
        prev = curr;
        curr = curr->ptr;
    }

    if(curr->size == size){
        curr->free = 0;
        ret = curr->ptr;
    }
    else{
        ret = (void*)0;
    }

    return ret;
}

void myFree(void* ptr){
    block *curr = freeList, *prev = (void*)0;

    while((curr!= (void*)0) && (curr->ptr!= ptr)){
        prev = curr;
        curr = curr->ptr;
    }

    if(curr!= (void*)0){
        curr->free = 1;
    }
}

int main(){
    char *s1, *s2, *s3;

    init();

    s1 = (char*)myMalloc(10);
    s2 = (char*)myMalloc(20);
    s3 = (char*)myMalloc(30);

    strcpy(s1, "Hello");
    strcpy(s2, "World");
    strcpy(s3, "This is a test");

    printf("%s\n", s1);
    printf("%s\n", s2);
    printf("%s\n", s3);

    myFree(s1);
    myFree(s2);
    myFree(s3);

    return 0;
}