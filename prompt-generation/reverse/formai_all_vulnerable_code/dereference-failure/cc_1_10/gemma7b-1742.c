//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INDEX_SIZE 100

typedef struct Node {
    char name[20];
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

void insertIndex(Index* index, char* name) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->name, name);
    newNode->next = NULL;

    if (index->head == NULL) {
        index->head = newNode;
    } else {
        Node* tempNode = index->head;
        while (tempNode->next) {
            tempNode = tempNode->next;
        }
        tempNode->next = newNode;
    }

    index->size++;
}

int searchIndex(Index* index, char* name) {
    Node* tempNode = index->head;
    while (tempNode) {
        if (strcmp(tempNode->name, name) == 0) {
            return 1;
        }
        tempNode = tempNode->next;
    }
    return 0;
}

int main() {
    Index* index = createIndex();

    insertIndex(index, "John Doe");
    insertIndex(index, "Jane Doe");
    insertIndex(index, "Jack Doe");

    if (searchIndex(index, "Jane Doe") == 1) {
        printf("Jane Doe is in the index.\n");
    }

    return 0;
}