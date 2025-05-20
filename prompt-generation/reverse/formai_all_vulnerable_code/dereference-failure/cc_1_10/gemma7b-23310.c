//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INDEX_SIZE 100

typedef struct Node {
    char data[MAX_INDEX_SIZE];
    struct Node* next;
} Node;

typedef struct Index {
    struct Node* head;
    int size;
} Index;

Index* createIndex() {
    Index* index = (Index*)malloc(sizeof(Index));
    index->head = NULL;
    index->size = 0;
    return index;
}

void insertIndex(Index* index, char data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->data, data);
    newNode->next = NULL;

    if (index->head == NULL) {
        index->head = newNode;
    } else {
        index->head->next = newNode;
    }

    index->size++;
}

void searchIndex(Index* index, char data) {
    Node* current = index->head;
    while (current) {
        if (strcmp(current->data, data) == 0) {
            printf("Data found: %s\n", current->data);
            return;
        }
        current = current->next;
    }

    printf("Data not found.\n");
}

int main() {
    Index* index = createIndex();
    insertIndex(index, "a");
    insertIndex(index, "b");
    insertIndex(index, "c");
    insertIndex(index, "d");
    insertIndex(index, "e");

    searchIndex(index, "b");
    searchIndex(index, "f");

    return 0;
}