//Falcon-180B DATASET v1.0 Category: RAM usage monitor ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    char *name;
    size_t size;
    int allocated;
} Block;

Block *heap = (void *)0;
size_t heap_size = 0;

void init() {
    heap = (Block *)malloc(MAX_SIZE * sizeof(Block));
    memset(heap, 0, MAX_SIZE * sizeof(Block));
    heap_size = MAX_SIZE;
}

void *my_malloc(size_t size) {
    if (heap_size == 0) {
        fprintf(stderr, "Out of memory!\n");
        exit(1);
    }

    Block *block = heap;
    while (block->allocated && block->size < size) {
        block++;
    }

    if (block->allocated && block->size == size) {
        block->allocated = 0;
        return (void *)((char *)heap + block->size);
    } else if (block->size > size) {
        block->size = size;
        block->allocated = 1;
        return (void *)((char *)heap + block->size);
    } else {
        return NULL;
    }
}

void my_free(void *ptr) {
    if (ptr < (void *)heap || ptr >= (void *)(heap + heap_size)) {
        fprintf(stderr, "Invalid pointer!\n");
        exit(1);
    }

    Block *block = (Block *)ptr;
    --block;
    block->allocated = 0;
}

void print_heap() {
    Block *block = heap;
    while (block->size) {
        printf("%p - %p: %s (%zu bytes)\n", block, block->name, block->allocated? "allocated" : "free", block->size);
        ++block;
    }
}

int main() {
    init();

    char *str1 = my_malloc(10);
    char *str2 = my_malloc(20);
    char *str3 = my_malloc(30);

    strcpy(str1, "Hello");
    strcpy(str2, "World");
    strcpy(str3, "How are you?");

    print_heap();

    my_free(str2);

    strcpy(str2, "Beautiful");

    print_heap();

    my_free(str1);
    my_free(str2);
    my_free(str3);

    return 0;
}