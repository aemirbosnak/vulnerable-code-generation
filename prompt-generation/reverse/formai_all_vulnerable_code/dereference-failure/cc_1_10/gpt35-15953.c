//FormAI DATASET v1.0 Category: Memory management ; Style: single-threaded
#include<stdio.h>
#include<stdlib.h>

#define BLOCK_SIZE 4096

typedef struct header {
    size_t size;
    struct header* next;
    int free;
} header_t;

header_t* head;

void initialize() {
    head = sbrk(0);
    void* block_start = sbrk(BLOCK_SIZE);
    if (block_start == (void*) -1) {
        printf("Failed to allocate memory!\n");
        return;
    }
    head->size = BLOCK_SIZE - sizeof(header_t);
    head->next = NULL;
    head->free = 1;
}

void split(header_t* block, size_t size) {
    header_t* new_block = (void*) (block + 1) + size;
    new_block->size = block->size - size - sizeof(header_t);
    new_block->next = block->next;
    new_block->free = 1;
    block->size = size;
    block->next = new_block;
    block->free = 0;
}

void* my_malloc(size_t size) {
    if (head == NULL) {
        initialize();
    }
    header_t* current = head;
    while (current) {
        if (current->free && current->size >= (size + sizeof(header_t))) {
            if (current->size > (size + sizeof(header_t))) {
                split(current, size);
            }
            current->free = 0;
            return (void*) (current + 1);
        }
        current = current->next;
    }
    void* block_start = sbrk(size + sizeof(header_t));
    if (block_start == (void*) -1) {
        printf("Failed to allocate memeory!\n");
        return NULL;
    }
    header_t* new_block = block_start;
    new_block->size = size;
    new_block->next = NULL;
    new_block->free = 0;
    if (head == NULL) {
        head = new_block;
    } else {
        current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = new_block;
    }
    return (void*) (new_block + 1);
}

void merge() {
    header_t* current = head;
    while (current && current->next) {
        if (current->free && current->next->free) {
            current->size += current->next->size + sizeof(header_t);
            current->next = current->next->next;
        }
        current = current->next;
    }
}

void my_free(void* pointer) {
    header_t* block = (header_t*) pointer - 1;
    block->free = 1;
    merge();
}

int main() {
    int* a = (int*) my_malloc(sizeof(int));
    int* b = (int*) my_malloc(sizeof(int));
    int* c = (int*) my_malloc(sizeof(int));
    *a = 1;
    *b = 2;
    *c = 3;
    my_free(b);
    b = (int*) my_malloc(sizeof(int));
    *b = 4;
    printf("%d %d %d\n", *a, *b, *c);
    my_free(a);
    my_free(b);
    my_free(c);
    return 0;
}