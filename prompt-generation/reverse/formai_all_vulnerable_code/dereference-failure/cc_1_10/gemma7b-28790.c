//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INDEX_SIZE 1024

typedef struct Node {
    char data[MAX_INDEX_SIZE];
    struct Node* next;
} Node;

typedef struct Index {
    struct Node* head;
    int size;
} Index;

Index* CreateIndex(int size) {
    Index* index = malloc(sizeof(Index));
    index->head = NULL;
    index->size = size;
    return index;
}

void InsertIndex(Index* index, char* data) {
    Node* newNode = malloc(sizeof(Node));
    newNode->next = index->head;
    strcpy(newNode->data, data);
    index->head = newNode;
    index->size++;
}

char* SearchIndex(Index* index, char* key) {
    Node* current = index->head;
    while (current) {
        if (strcmp(current->data, key) == 0) {
            return current->data;
        }
        current = current->next;
    }
    return NULL;
}

int main() {
    Index* myIndex = CreateIndex(10);
    InsertIndex(myIndex, "Alice");
    InsertIndex(myIndex, "Bob");
    InsertIndex(myIndex, "Charlie");
    InsertIndex(myIndex, "Dave");

    char* result = SearchIndex(myIndex, "Bob");

    if (result) {
        printf("Found data: %s", result);
    } else {
        printf("Data not found");
    }

    return 0;
}