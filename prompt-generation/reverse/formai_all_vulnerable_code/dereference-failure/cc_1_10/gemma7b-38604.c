//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>

#define MAX_INDEX_SIZE 100

typedef struct Node {
    int key;
    struct Node* next;
} Node;

typedef struct Index {
    Node** buckets;
    int size;
    int capacity;
} Index;

Index* createIndex(int capacity) {
    Index* index = (Index*)malloc(sizeof(Index));
    index->buckets = (Node**)malloc(sizeof(Node*) * capacity);
    index->size = 0;
    index->capacity = capacity;
    return index;
}

void insertIndex(Index* index, int key) {
    int bucketIndex = key % index->capacity;
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->next = NULL;

    if (index->buckets[bucketIndex] == NULL) {
        index->buckets[bucketIndex] = newNode;
    } else {
        Node* current = index->buckets[bucketIndex];
        while (current->next) {
            current = current->next;
        }
        current->next = newNode;
    }

    index->size++;
}

void searchIndex(Index* index, int key) {
    int bucketIndex = key % index->capacity;
    Node* current = index->buckets[bucketIndex];

    while (current) {
        if (current->key == key) {
            printf("Key found: %d\n", key);
            return;
        }
        current = current->next;
    }

    printf("Key not found: %d\n", key);
}

int main() {
    Index* index = createIndex(MAX_INDEX_SIZE);
    insertIndex(index, 10);
    insertIndex(index, 20);
    insertIndex(index, 30);
    insertIndex(index, 40);
    insertIndex(index, 50);

    searchIndex(index, 20);
    searchIndex(index, 40);
    searchIndex(index, 60);

    return 0;
}