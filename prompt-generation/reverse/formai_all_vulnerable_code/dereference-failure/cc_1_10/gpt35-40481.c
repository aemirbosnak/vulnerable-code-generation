//FormAI DATASET v1.0 Category: Memory management ; Style: optimized
#include <stdio.h>
#include <stdlib.h>

typedef struct MemoryBlock { 
    size_t size; 
    void* ptr; 
    struct MemoryBlock* next; 
} MemoryBlock;

MemoryBlock* head = NULL;

void addBlock(void* ptr, size_t size) {
    MemoryBlock* newBlock = (MemoryBlock*)malloc(sizeof(MemoryBlock));
    newBlock->size = size;
    newBlock->ptr = ptr;
    newBlock->next = head;
    head = newBlock;
}

void* myAlloc(size_t size) {
    void* ptr = malloc(size);
    addBlock(ptr, size);
    return ptr;
}

void myFree(void* ptr) {
    MemoryBlock* curr = head;
    MemoryBlock* prev = NULL;
    
    while (curr != NULL) {
        if (curr->ptr == ptr) {
            if (prev == NULL) {
                head = curr->next;
            } else {
                prev->next = curr->next;
            }
            free(curr->ptr);
            free(curr);
            break;
        }
        prev = curr;
        curr = curr->next;
    }
}

int main() {
    int* p = (int*)myAlloc(sizeof(int));
    *p = 5;
    printf("p = %d\n", *p);
    
    char* str = (char*)myAlloc(10 * sizeof(char));
    strcpy(str, "hello");
    printf("str = %s\n", str);
    
    myFree(p);
    myFree(str);
    
    return 0;
}