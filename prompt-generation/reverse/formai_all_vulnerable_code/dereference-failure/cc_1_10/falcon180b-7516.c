//Falcon-180B DATASET v1.0 Category: Memory management ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

#define HEAP_SIZE 1000 // size of heap

typedef struct {
    int size;
    int *heap;
} Heap;

Heap createHeap() {
    Heap heap;
    heap.size = 0;
    heap.heap = (int *)malloc(HEAP_SIZE * sizeof(int));
    return heap;
}

int isEmpty(Heap heap) {
    return heap.size == 0;
}

int isFull(Heap heap) {
    return heap.size == HEAP_SIZE;
}

void push(Heap *heap, int value) {
    if (isFull(*heap)) {
        printf("Heap is full.\n");
        return;
    }
    (*heap).heap[(*heap).size++] = value;
}

int pop(Heap *heap) {
    if (isEmpty(*heap)) {
        printf("Heap is empty.\n");
        return -1;
    }
    return (*heap).heap[--(*heap).size];
}

int main() {
    Heap heap = createHeap();
    push(&heap, 10);
    push(&heap, 20);
    push(&heap, 30);
    push(&heap, 40);
    push(&heap, 50);
    printf("%d popped from heap: %d\n", pop(&heap), pop(&heap));
    printf("%d popped from heap: %d\n", pop(&heap), pop(&heap));
    printf("%d popped from heap: %d\n", pop(&heap), pop(&heap));
    printf("%d popped from heap: %d\n", pop(&heap), pop(&heap));
    printf("%d popped from heap: %d\n", pop(&heap), pop(&heap));
    return 0;
}