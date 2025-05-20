//MISTRAL-7B DATASET v1.0 Category: RAM usage monitor ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

#define HEAP_SIZE (1024*1024)

typedef struct {
    char name[32];
    size_t size;
    char* ptr;
} heap_block;

heap_block* heap = 0;
size_t heap_size = 0;
size_t heap_capacity = 0;

void* my_malloc(size_t size) {
    if (heap_size + size > heap_capacity) {
        void* new_heap = mmap(0, HEAP_SIZE, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANON, -1, 0);
        if (new_heap == MAP_FAILED) {
            perror("mmap failed");
            exit(EXIT_FAILURE);
        }

        heap = (heap_block*)new_heap;
        heap_size = 0;
        heap_capacity = HEAP_SIZE;
    }

    heap_block* current = heap;
    while ((current + 1)->size != 0) {
        current++;
    }

    strcpy(current->name, "anonymous");
    current->size = size;
    current->ptr = (char*)((size_t)current + sizeof(heap_block));
    heap_size += sizeof(heap_block) + size;

    return current->ptr;
}

void my_free(void* ptr) {
    heap_block* current = heap;
    while (current < (heap_block*)ptr) {
        current++;
    }

    size_t block_size = current->size;
    memcpy(current, current + 1, block_size - sizeof(heap_block));
    current->size += sizeof(heap_block) + (size_t)(((heap_block*)ptr) - (heap_block*)current);
    heap_size -= sizeof(heap_block) + block_size;
}

void print_heap() {
    printf("===========\n");
    printf("HEAP DUMP:\n");
    printf("===========\n");

    heap_block* current = heap;
    while (current < heap + (heap_size / sizeof(heap_block))) {
        printf("%s: %p, %ld bytes\n", current->name, current->ptr, current->size);
        current++;
    }

    printf("===========\n");
}

int main(int argc, char* argv[]) {
    int* a = (int*)my_malloc(sizeof(int));
    int* b = (int*)my_malloc(sizeof(int));
    int* c = (int*)my_malloc(sizeof(int));
    int i;

    for (i = 0; i < 1000000; i++) {
        *a = i;
        *b = i * 2;
        *c = i * 3;
    }

    print_heap();

    for (i = 0; i < 3; i++) {
        my_free(a + i);
    }

    print_heap();

    return EXIT_SUCCESS;
}