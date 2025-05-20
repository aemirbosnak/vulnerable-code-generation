//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INDEX_SIZE 1024

typedef struct Node {
    char key[MAX_INDEX_SIZE];
    struct Node* next;
} Node;

typedef struct Index {
    Node* head;
    int size;
} Index;

Index* createIndex() {
    Index* index = malloc(sizeof(Index));
    index->head = NULL;
    index->size = 0;
    return index;
}

void insertIndex(Index* index, char key) {
    Node* newNode = malloc(sizeof(Node));
    strcpy(newNode->key, key);
    newNode->next = NULL;

    if (index->head == NULL) {
        index->head = newNode;
    } else {
        Node* lastNode = index->head;
        while (lastNode->next) {
            lastNode = lastNode->next;
        }
        lastNode->next = newNode;
    }

    index->size++;
}

int searchIndex(Index* index, char key) {
    Node* currentNode = index->head;
    while (currentNode) {
        if (strcmp(currentNode->key, key) == 0) {
            return 1;
        }
        currentNode = currentNode->next;
    }

    return 0;
}

int main() {
    Index* index = createIndex();

    insertIndex(index, "John Doe");
    insertIndex(index, "Jane Doe");
    insertIndex(index, "Peter Pan");

    if (searchIndex(index, "Jane Doe") == 1) {
        printf("Jane Doe is in the index.\n");
    }

    if (searchIndex(index, "Jack Sparrow") == 0) {
        printf("Jack Sparrow is not in the index.\n");
    }

    return 0;
}