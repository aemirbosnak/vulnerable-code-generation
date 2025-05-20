//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INDEX_SIZE 1024

typedef struct Node {
    char data[256];
    struct Node* next;
} Node;

typedef struct Index {
    Node* head;
    int size;
    int capacity;
} Index;

Index* createIndex(int capacity) {
    Index* index = (Index*)malloc(sizeof(Index));
    index->head = NULL;
    index->size = 0;
    index->capacity = capacity;
    return index;
}

void insertIndex(Index* index, char* data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->data, data);
    newNode->next = index->head;
    index->head = newNode;
    index->size++;
}

char* searchIndex(Index* index, char* data) {
    Node* current = index->head;
    while (current) {
        if (strcmp(current->data, data) == 0) {
            return current->data;
        }
        current = current->next;
    }
    return NULL;
}

int main() {
    Index* index = createIndex(MAX_INDEX_SIZE);
    insertIndex(index, "John Doe");
    insertIndex(index, "Jane Doe");
    insertIndex(index, "Peter Pan");

    char* result = searchIndex(index, "Jane Doe");

    if (result) {
        printf("Found: %s", result);
    } else {
        printf("Not found");
    }

    return 0;
}