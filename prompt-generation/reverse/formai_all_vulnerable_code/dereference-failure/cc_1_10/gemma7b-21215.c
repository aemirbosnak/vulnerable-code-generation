//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INDEX_SIZE 1024

typedef struct Node {
    char key[MAX_INDEX_SIZE];
    struct Node* next;
} Node;

typedef struct Index {
    struct Node** buckets;
    int size;
    int capacity;
} Index;

Index* createIndex(int size, int capacity) {
    Index* index = (Index*)malloc(sizeof(Index));
    index->buckets = (struct Node**)malloc(sizeof(struct Node*) * size);
    index->size = 0;
    index->capacity = capacity;

    return index;
}

void insertIndex(Index* index, char key) {
    int bucketIndex = key % index->capacity;

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->key[0] = key;
    newNode->next = NULL;

    if (index->buckets[bucketIndex] == NULL) {
        index->buckets[bucketIndex] = newNode;
    } else {
        struct Node* tail = index->buckets[bucketIndex];
        tail->next = newNode;
    }

    index->size++;
}

char searchIndex(Index* index, char key) {
    int bucketIndex = key % index->capacity;

    struct Node* node = index->buckets[bucketIndex];

    while (node) {
        if (strcmp(node->key, key) == 0) {
            return 1;
        }

        node = node->next;
    }

    return 0;
}

int main() {
    Index* index = createIndex(10, MAX_INDEX_SIZE);

    insertIndex(index, "a");
    insertIndex(index, "b");
    insertIndex(index, "c");
    insertIndex(index, "d");

    if (searchIndex(index, "a") == 1) {
        printf("a found");
    }

    return 0;
}