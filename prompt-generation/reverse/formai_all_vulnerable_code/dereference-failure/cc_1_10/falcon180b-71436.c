//Falcon-180B DATASET v1.0 Category: Memory management ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

#define HEAP_SIZE 1000

typedef struct {
    int size;
    int free;
    char *heap;
} Heap;

void init_heap(Heap *heap) {
    heap->size = HEAP_SIZE;
    heap->free = HEAP_SIZE;
    heap->heap = (char *) malloc(HEAP_SIZE);
    if (heap->heap == NULL) {
        printf("Heap initialization failed\n");
        exit(1);
    }
    printf("Heap initialized\n");
}

void *my_malloc(Heap *heap, int size) {
    void *ptr;
    if (heap->free >= size) {
        heap->free -= size;
        ptr = heap->heap + heap->free;
        heap->free = (heap->free + 7) & ~7; // Align to 8 bytes
        return ptr;
    } else {
        printf("Out of memory\n");
        return NULL;
    }
}

void my_free(Heap *heap, void *ptr) {
    heap->free += ((char *) ptr - heap->heap) + 7;
    heap->free = (heap->free + 7) & ~7;
}

int main() {
    Heap heap;
    init_heap(&heap);

    int *a = (int *) my_malloc(&heap, sizeof(int));
    int *b = (int *) my_malloc(&heap, sizeof(int));
    int *c = (int *) my_malloc(&heap, sizeof(int));

    if (a == NULL || b == NULL || c == NULL) {
        printf("Not enough memory\n");
        return 1;
    }

    *a = 1;
    *b = 2;
    *c = 3;

    my_free(&heap, a);
    my_free(&heap, b);

    int *d = (int *) my_malloc(&heap, sizeof(int));
    if (d == NULL) {
        printf("Not enough memory\n");
        return 1;
    }

    *d = 4;

    my_free(&heap, c);
    my_free(&heap, d);

    return 0;
}