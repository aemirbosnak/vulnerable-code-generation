//MISTRAL-7B DATASET v1.0 Category: Memory management ; Style: scalable
#include <stdio.h>
#include <stdlib.h>

#define BLOCK_SIZE 1024
#define HEAP_SIZE 65536

typedef struct block {
    size_t size;
    struct block* next;
} Block;

Block* heap = 0;
size_t heap_size = HEAP_SIZE;

void* my_malloc(size_t size) {
    if (size == 0) {
        return 0;
    }

    if (heap_size <= HEAP_SIZE - sizeof(Block)) {
        Block* new_block = (Block*)(heap + heap_size);
        heap_size += sizeof(Block) + size;
        new_block->size = size;
        new_block->next = heap;
        heap = new_block;
        return (void*)(new_block + 1);
    }

    Block* current = heap;
    while (current->next != 0) {
        if (current->next->size >= size + sizeof(Block)) {
            Block* new_block = (Block*)((char*)current->next + size + sizeof(Block));
            new_block->size = current->next->size - size - sizeof(Block);
            current->next->size = size;
            new_block->next = current->next->next;
            current->next = new_block;
            return (void*)(current->next + 1);
        }
        current = current->next;
    }

    printf("Out of memory\n");
    return 0;
}

void my_free(void* ptr) {
    if (ptr == 0) {
        return;
    }

    Block* current = heap;
    Block* previous = 0;

    while (current != 0) {
        if (current + sizeof(Block) == ptr) {
            if (previous == 0) {
                heap = current->next;
            } else {
                previous->next = current->next;
            }
            size_t block_size = current->size;
            heap_size -= block_size;
            break;
        }
        previous = current;
        current = current->next;
    }
}

int main() {
    int* arr1 = (int*)my_malloc(10 * sizeof(int));
    int* arr2 = (int*)my_malloc(5 * sizeof(int));

    for (int i = 0; i < 10; i++) {
        arr1[i] = i;
    }

    for (int j = 0; j < 5; j++) {
        arr2[j] = j * 2;
    }

    int sum = 0;
    for (int i = 0; i < 10; i++) {
        sum += arr1[i];
    }

    printf("Sum of first array elements: %d\n", sum);

    for (int i = 0; i < 5; i++) {
        sum += arr2[i];
    }

    printf("Sum of second array elements: %d\n", sum);

    my_free(arr1);
    my_free(arr2);

    return 0;
}