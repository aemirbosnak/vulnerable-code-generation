//LLAMA2-13B DATASET v1.0 Category: Memory management ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_HEAP_SIZE 1024
#define MAX_OBJECT_SIZE 1024

typedef struct {
    void* data;
    size_t size;
} Object;

typedef struct {
    Object* heap[MAX_HEAP_SIZE];
    size_t capacity;
    size_t size;
} Heap;

void initHeap(Heap* heap) {
    heap->capacity = MAX_HEAP_SIZE;
    heap->size = 0;
    for (size_t i = 0; i < MAX_HEAP_SIZE; i++) {
        heap->heap[i] = NULL;
    }
}

void insertObject(Heap* heap, Object* object) {
    if (heap->size == MAX_HEAP_SIZE) {
        printf("Memory overflow! Heap cannot hold any more objects.\n");
        return;
    }
    heap->heap[heap->size] = object;
    heap->size++;
    perror("Inserted object");
}

void deleteObject(Heap* heap, size_t index) {
    if (index >= heap->size) {
        printf("Invalid index! Heap has %zu elements.\n", heap->size);
        return;
    }
    Object* object = heap->heap[index];
    heap->heap[index] = heap->heap[heap->size - 1];
    heap->heap[heap->size - 1] = object;
    heap->size--;
    perror("Deleted object");
}

void printHeap(Heap* heap) {
    for (size_t i = 0; i < heap->size; i++) {
        printf("%p (%zu bytes)\n", heap->heap[i]->data, heap->heap[i]->size);
    }
}

int main() {
    Heap* heap = malloc(sizeof(Heap));
    initHeap(heap);

    Object* object1 = malloc(sizeof(Object));
    object1->data = "Hello, world!";
    object1->size = strlen("Hello, world!");
    insertObject(heap, object1);

    Object* object2 = malloc(sizeof(Object));
    object2->data = "Another object";
    object2->size = strlen("Another object");
    insertObject(heap, object2);

    Object* object3 = malloc(sizeof(Object));
    object3->data = "Yet another object";
    object3->size = strlen("Yet another object");
    insertObject(heap, object3);

    deleteObject(heap, 1);

    printHeap(heap);

    return 0;
}