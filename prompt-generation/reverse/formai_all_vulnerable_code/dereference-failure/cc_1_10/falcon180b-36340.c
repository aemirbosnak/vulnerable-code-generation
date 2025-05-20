//Falcon-180B DATASET v1.0 Category: Memory management ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct block{
    int size;
    int free;
    struct block* next;
}block;

block* freelist = (void*)0;

void init(){
    freelist = (block*)malloc(sizeof(block));
    freelist->size = MAX_SIZE - sizeof(block);
    freelist->free = 1;
    freelist->next = (void*)0;
}

void* my_malloc(int size){
    block* current = freelist;
    while(current!= (void*)0 && current->size < size){
        current = current->next;
    }
    if(current == (void*)0){
        printf("Memory Error: Not enough memory available\n");
        exit(1);
    }
    if(current->size == size){
        current->free = 0;
        return (void*)(++current);
    }else if(current->size > size){
        block* temp = (block*)malloc(sizeof(block));
        temp->size = current->size - size - sizeof(block);
        temp->free = 1;
        temp->next = current->next;
        current->size = size;
        current->free = 0;
        current->next = temp;
        return (void*)(++current);
    }
    return (void*)0;
}

void my_free(void* ptr){
    if(ptr == (void*)0){
        return;
    }
    block* current = (block*)ptr;
    current->free = 1;
}

int main(){
    init();
    int i = 0;
    while(i < 10){
        void* ptr = my_malloc(rand() % 50);
        printf("Allocated %d bytes at %p\n", rand() % 50, ptr);
        i++;
    }
    i = 0;
    while(i < 10){
        my_free(my_malloc(rand() % 50));
        printf("Freed %d bytes at %p\n", rand() % 50, my_malloc(rand() % 50));
        i++;
    }
    return 0;
}