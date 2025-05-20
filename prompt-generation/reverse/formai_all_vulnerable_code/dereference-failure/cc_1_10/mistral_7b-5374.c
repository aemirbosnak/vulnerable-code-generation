//MISTRAL-7B DATASET v1.0 Category: Memory management ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100
#define BLOCK_SIZE 512

typedef struct Block {
    size_t size;
    struct Block *next;
} Block;

typedef struct Heap {
    Block *start;
    Block *end;
} Heap;

Heap *createHeap(void) {
    Heap *heap = (Heap *) malloc(sizeof(Heap));
    heap->start = NULL;
    heap->end = NULL;
    return heap;
}

void printHeap(Heap *heap) {
    Block *current = heap->start;
    printf("Current Heap State:\n");
    printf("--------------------\n");
    while (current != NULL) {
        printf("Block size: %ld, Block address: %p, Prev Block: %p, Next Block: %p\n", current->size, current, current->next, current->next);
        current = current->next;
    }
    printf("--------------------\n");
}

void *myMalloc(Heap *heap, size_t size) {
    Block *newBlock = (Block *) malloc(sizeof(Block) + size);

    if (newBlock == NULL) {
        fprintf(stderr, "Error: Could not allocate memory for malloc\n");
        return NULL;
    }

    newBlock->size = size;

    if (heap->start == NULL) {
        heap->start = newBlock;
        heap->end = newBlock;
    } else {
        newBlock->next = heap->end;
        heap->end = newBlock;
    }

    return (void *) (newBlock + 1);
}

void myFree(Heap *heap, void *ptr) {
    Block *current = heap->start;
    Block *previous = NULL;

    if (current == NULL) {
        fprintf(stderr, "Error: Heap is empty\n");
        return;
    }

    while (current != NULL) {
        if (((char *) current + sizeof(Block) == (char *) ptr)) {
            if (previous == NULL) {
                heap->start = current->next;
            } else {
                previous->next = current->next;
            }
            free(current);
            break;
        }
        previous = current;
        current = current->next;
    }
}

int main() {
    Heap *heap = createHeap();

    char *str1 = (char *) myMalloc(heap, 15);
    strcpy(str1, "First String");

    char *str2 = (char *) myMalloc(heap, 30);
    strcpy(str2, "Second String");

    printHeap(heap);

    myFree(heap, str1);
    myFree(heap, str2);

    printHeap(heap);

    myMalloc(heap, 1000);

    printHeap(heap);

    return 0;
}