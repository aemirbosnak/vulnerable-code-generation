//Gemma-7B DATASET v1.0 Category: Performance-Critical Component ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Heap {
    Node* head;
    int size;
} Heap;

Heap* createHeap() {
    Heap* heap = malloc(sizeof(Heap));
    heap->head = NULL;
    heap->size = 0;
    return heap;
}

void insertHeap(Heap* heap, int data) {
    Node* newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (heap->head == NULL) {
        heap->head = newNode;
    } else {
        Node* traverse = heap->head;
        while (traverse->next) {
            traverse = traverse->next;
        }
        traverse->next = newNode;
    }

    heap->size++;
}

int peekHeap(Heap* heap) {
    if (heap->head == NULL) {
        return -1;
    } else {
        return heap->head->data;
    }
}

void deleteHeap(Heap* heap) {
    free(heap->head);
    free(heap);
    heap = NULL;
}

int main() {
    Heap* myHeap = createHeap();
    insertHeap(myHeap, 5);
    insertHeap(myHeap, 3);
    insertHeap(myHeap, 8);
    insertHeap(myHeap, 2);

    printf("The top element of the heap is: %d\n", peekHeap(myHeap));

    deleteHeap(myHeap);

    return 0;
}