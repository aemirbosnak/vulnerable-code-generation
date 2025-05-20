//Falcon-180B DATASET v1.0 Category: Memory management ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    void* data;
    size_t size;
    int ref_count;
} Block;

void* alloc(size_t size) {
    Block* block = malloc(sizeof(Block) + size);
    if (block == NULL) {
        return NULL;
    }
    block->data = (char*)block + sizeof(Block);
    block->size = size;
    block->ref_count = 1;
    return block->data;
}

void free(void* ptr) {
    if (ptr == NULL) {
        return;
    }
    Block* block = (Block*)ptr - sizeof(Block);
    block->ref_count--;
    if (block->ref_count == 0) {
        free(block);
    }
}

void* realloc(void* ptr, size_t size) {
    if (ptr == NULL) {
        return alloc(size);
    }
    Block* block = (Block*)ptr - sizeof(Block);
    if (size <= block->size) {
        return ptr;
    }
    void* new_ptr = alloc(size);
    if (new_ptr == NULL) {
        return NULL;
    }
    memcpy(new_ptr, ptr, block->size);
    free(ptr);
    return new_ptr;
}

int main() {
    char* str1 = (char*)alloc(10);
    strcpy(str1, "Hello");
    printf("%s\n", str1);

    char* str2 = (char*)alloc(20);
    strcpy(str2, "World");
    printf("%s\n", str2);

    char* str3 = (char*)realloc(str1, 20);
    strcpy(str3, "Hello World");
    printf("%s\n", str3);

    free(str1);
    free(str2);
    free(str3);

    return 0;
}