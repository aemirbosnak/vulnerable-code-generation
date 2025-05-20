//Gemma-7B DATASET v1.0 Category: Performance-Critical Component ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    struct Node* next;
    int data;
} Node;

typedef struct Heap {
    struct Node* root;
} Heap;

Heap* createHeap() {
    Heap* heap = malloc(sizeof(Heap));
    heap->root = NULL;
    return heap;
}

void insertHeap(Heap* heap, int data) {
    Node* newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (heap->root == NULL) {
        heap->root = newNode;
    } else {
        Node* current = heap->root;
        Node* parent = NULL;

        while (current) {
            if (data < current->data) {
                parent = current;
                current = current->next;
            } else {
                break;
            }
        }

        if (parent) {
            parent->next = newNode;
        } else {
            heap->root = newNode;
        }
    }
}

void traverseHeap(Heap* heap) {
    Node* current = heap->root;

    while (current) {
        printf("%d ", current->data);
        current = current->next;
    }

    printf("\n");
}

int main() {
    Heap* heap = createHeap();
    insertHeap(heap, 5);
    insertHeap(heap, 3);
    insertHeap(heap, 8);
    insertHeap(heap, 2);
    insertHeap(heap, 4);
    insertHeap(heap, 9);

    traverseHeap(heap);

    return 0;
}