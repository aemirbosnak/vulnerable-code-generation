//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INDEX_SIZE 10

typedef struct Node {
    char data[20];
    struct Node* next;
} Node;

struct Index {
    int size;
    Node** buckets;
};

void insertIndex(struct Index* index, char* data) {
    Node* newNode = malloc(sizeof(Node));
    strcpy(newNode->data, data);
    newNode->next = NULL;

    if (index->size == MAX_INDEX_SIZE) {
        index->buckets = realloc(index->buckets, (index->size + 1) * sizeof(Node*));
        index->size++;
    }

    index->buckets[index->size] = newNode;
    index->size++;
}

int searchIndex(struct Index* index, char* data) {
    for (int i = 0; i < index->size; i++) {
        if (strcmp(index->buckets[i]->data, data) == 0) {
            return i;
        }
    }

    return -1;
}

int main() {
    struct Index* index = malloc(sizeof(struct Index));
    index->size = 0;
    index->buckets = NULL;

    insertIndex(index, "John Doe");
    insertIndex(index, "Jane Doe");
    insertIndex(index, "Peter Pan");

    int result = searchIndex(index, "Jane Doe");

    if (result != -1) {
        printf("Found index of Jane Doe: %d\n", result);
    } else {
        printf("Jane Doe not found.\n");
    }

    return 0;
}