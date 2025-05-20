//Gemma-7B DATASET v1.0 Category: Data structures visualization ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct HashTable {
    Node** buckets;
    int size;
} HashTable;

void insert(HashTable* h, int data) {
    int hash = data % h->size;
    Node* newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (h->buckets[hash] == NULL) {
        h->buckets[hash] = newNode;
    } else {
        Node* current = h->buckets[hash];
        while (current->next) {
            current = current->next;
        }
        current->next = newNode;
    }
}

void traverse(HashTable* h) {
    for (int i = 0; i < h->size; i++) {
        if (h->buckets[i] != NULL) {
            Node* current = h->buckets[i];
            while (current) {
                printf("%d ", current->data);
                current = current->next;
            }
            printf("\n");
        }
    }
}

int main() {
    HashTable* h = malloc(sizeof(HashTable));
    h->size = 10;
    h->buckets = malloc(h->size * sizeof(Node*));

    insert(h, 5);
    insert(h, 10);
    insert(h, 15);
    insert(h, 20);
    insert(h, 25);

    traverse(h);

    free(h->buckets);
    free(h);

    return 0;
}