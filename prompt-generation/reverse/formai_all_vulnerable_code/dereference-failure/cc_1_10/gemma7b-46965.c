//Gemma-7B DATASET v1.0 Category: Memory management ; Style: post-apocalyptic
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_HEAP_SIZE 1024

typedef struct HeapNode {
    void* data;
    struct HeapNode* next;
} HeapNode;

HeapNode* Heap_Insert(HeapNode* heap, void* data) {
    HeapNode* newNode = malloc(sizeof(HeapNode));
    newNode->data = data;
    newNode->next = NULL;

    if (heap == NULL) {
        heap = newNode;
    } else {
        HeapNode* lastNode = heap;
        while (lastNode->next) {
            lastNode = lastNode->next;
        }
        lastNode->next = newNode;
    }

    return heap;
}

void Heap_Traverse(HeapNode* heap) {
    HeapNode* current = heap;
    while (current) {
        printf("%p ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    HeapNode* heap = NULL;

    heap = Heap_Insert(heap, "a");
    heap = Heap_Insert(heap, "b");
    heap = Heap_Insert(heap, "c");
    heap = Heap_Insert(heap, "d");

    Heap_Traverse(heap);

    return 0;
}