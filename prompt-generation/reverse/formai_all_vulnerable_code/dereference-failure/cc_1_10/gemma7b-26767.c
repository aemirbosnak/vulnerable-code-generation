//Gemma-7B DATASET v1.0 Category: Performance-Critical Component ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Node {
    char data;
    struct Node* next;
} Node;

typedef struct Heap {
    Node* root;
    int size;
} Heap;

Heap* createHeap() {
    Heap* heap = malloc(sizeof(Heap));
    heap->root = NULL;
    heap->size = 0;
    return heap;
}

void insertHeap(Heap* heap, char data) {
    Node* newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (heap->root == NULL) {
        heap->root = newNode;
    } else {
        Node* current = heap->root;
        Node* previous = NULL;
        while (current) {
            if (newNode->data < current->data) {
                previous = current;
                current = current->next;
            } else {
                break;
            }
        }

        if (previous) {
            previous->next = newNode;
        } else {
            heap->root = newNode;
        }
    }

    heap->size++;
}

char extractHeap(Heap* heap) {
    if (heap->size == 0) {
        return -1;
    }

    char data = heap->root->data;
    Node* oldRoot = heap->root;
    heap->root = heap->root->next;
    free(oldRoot);

    heap->size--;
    return data;
}

int main() {
    Heap* heap = createHeap();

    insertHeap(heap, 'a');
    insertHeap(heap, 'c');
    insertHeap(heap, 'e');
    insertHeap(heap, 'g');
    insertHeap(heap, 'i');

    char extractedData = extractHeap(heap);

    if (extractedData != -1) {
        printf("Extracted data: %c\n", extractedData);
    }

    extractedData = extractHeap(heap);

    if (extractedData != -1) {
        printf("Extracted data: %c\n", extractedData);
    }

    return 0;
}