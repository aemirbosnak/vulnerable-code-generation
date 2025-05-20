//Gemma-7B DATASET v1.0 Category: Compression algorithms ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Compress {
    Node* head;
    int size;
} Compress;

Compress* compress(int data) {
    Compress* comp = malloc(sizeof(Compress));
    comp->head = NULL;
    comp->size = 0;

    Node* newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (comp->head == NULL) {
        comp->head = newNode;
    } else {
        comp->head->next = newNode;
    }

    comp->size++;

    return comp;
}

int main() {
    Compress* comp = compress(10);
    compress(20);
    compress(30);

    int i = 0;
    for (Node* node = comp->head; node; node = node->next) {
        printf("%d ", node->data);
    }

    printf("\n");
    printf("Size: %d", comp->size);

    return 0;
}