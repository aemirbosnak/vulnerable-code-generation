//FormAI DATASET v1.0 Category: Memory management ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

typedef struct block {
    int size;
    int isFree;
    struct block *next;
} Block;

Block *head = NULL; 

void createMemory(int size){
    head = (Block*)malloc(size);
    head->size = size - sizeof(Block);
    head->isFree = 1;
    head->next = NULL;
}

void splitBlock(Block *b, int size){
    Block *newBlock = (void*)((void*)b + sizeof(Block) + size);
    newBlock->size = (b->size - size) - sizeof(Block);
    newBlock->isFree = 1;
    newBlock->next = b->next;
    b->next = newBlock;
    b->size = size;
}

void *allocateMemory(int size){
    Block *current = head;
    while(current){
        if(current->isFree && current->size >= size){
            if(current->size >= (size + sizeof(Block))){
                splitBlock(current,size);
            }
            current->isFree = 0;
            return ((void*)current + sizeof(Block));
        }
        current = current->next;
    }
    return NULL;   
}

void combineBlocks(){
    Block *current = head;
    while(current && current->next){
        if(current->isFree && current->next->isFree){
            current->size += (current->next->size) + sizeof(Block);
            current->next = current->next->next;
        }
        current = current->next;
    }
}

void freeMemory(void *ptr){
    if(!ptr){
        return;
    }
    Block *currentBlock = (Block*)ptr - 1;
    currentBlock->isFree = 1;
    combineBlocks();   
}

void printBlocks(){
    Block *current = head;
    int i=0;
    while(current){
        printf("Block %d - Size: %d, IsFree: %d\n",i+1,current->size,current->isFree);
        current = current->next;
        i++;
    }
}

int main(){
    createMemory(1000);
    printBlocks();

    int *p = allocateMemory(sizeof(int));
    int *q = allocateMemory(sizeof(int)*5);

    printBlocks();

    freeMemory(p);
    freeMemory(q);
    printBlocks();

    return 0;
}