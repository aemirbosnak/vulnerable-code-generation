//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct Node {
    char data[MAX_SIZE];
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

void insertIndex(Index* index, char* data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->data, data);
    newNode->next = NULL;

    if (index->head == NULL) {
        index->head = newNode;
    } else {
        Node* temp = index->head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    index->size++;
}

char* searchIndex(Index* index, char* data) {
    Node* temp = index->head;
    while (temp) {
        if (strcmp(temp->data, data) == 0) {
            return temp->data;
        }
        temp = temp->next;
    }
    return NULL;
}

int main() {
    Index* index = createIndex();
    insertIndex(index, "John Doe");
    insertIndex(index, "Jane Doe");
    insertIndex(index, "Peter Pan");

    char* result = searchIndex(index, "Jane Doe");
    if (result) {
        printf("Found: %s\n", result);
    } else {
        printf("Not found.\n");
    }

    return 0;
}