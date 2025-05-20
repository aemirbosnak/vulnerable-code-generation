//Gemma-7B DATASET v1.0 Category: HTML beautifier ; Style: complex
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node {
    char data;
    struct Node* next;
} Node;

typedef struct Heap {
    Node** arr;
    int size;
    int capacity;
} Heap;

void insert(Heap* h, char data) {
    Node* newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (h->size == h->capacity) {
        h->arr = realloc(h->arr, (h->capacity * 2) * sizeof(Node*));
        h->capacity *= 2;
    }

    newNode->next = h->arr[h->size];
    h->arr[h->size++] = newNode;
}

void traverse(Heap* h) {
    for (int i = 0; i < h->size; i++) {
        printf("%c ", h->arr[i]->data);
    }
    printf("\n");
}

int main() {
    Heap* h = malloc(sizeof(Heap));
    h->arr = NULL;
    h->size = 0;
    h->capacity = 10;

    insert(h, 'a');
    insert(h, 'b');
    insert(h, 'c');
    insert(h, 'd');
    insert(h, 'e');

    traverse(h);

    free(h);
    return 0;
}