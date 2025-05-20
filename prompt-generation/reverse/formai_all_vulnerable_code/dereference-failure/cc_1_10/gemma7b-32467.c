//Gemma-7B DATASET v1.0 Category: HTML beautifier ; Style: visionary
#include <stdio.h>
#include <string.h>

typedef struct Node {
    char data;
    struct Node* next;
} Node;

typedef struct Heap {
    Node* root;
    int size;
} Heap;

Heap* createHeap(int size) {
    Heap* h = malloc(sizeof(Heap));
    h->root = NULL;
    h->size = size;
    return h;
}

void insertHeap(Heap* h, char data) {
    Node* newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (h->root == NULL) {
        h->root = newNode;
    } else {
        Node* current = h->root;
        Node* parent = NULL;
        while (current) {
            if (newNode->data > current->data) {
                parent = current;
            }
            current = current->next;
        }

        if (parent) {
            parent->next = newNode;
        } else {
            h->root = newNode;
        }
    }

    h->size++;
}

void traverseHeap(Heap* h) {
    Node* current = h->root;
    while (current) {
        printf("%c ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    Heap* h = createHeap(5);
    insertHeap(h, 10);
    insertHeap(h, 20);
    insertHeap(h, 30);
    insertHeap(h, 40);
    insertHeap(h, 50);

    traverseHeap(h);

    return 0;
}