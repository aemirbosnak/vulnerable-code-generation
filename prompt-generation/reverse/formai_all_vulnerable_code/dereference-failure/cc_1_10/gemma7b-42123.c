//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

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
    newNode->data[0] = data;
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

void searchIndex(Index* index, char data) {
    Node* currentNode = index->head;
    while (currentNode) {
        if (currentNode->data[0] == data) {
            printf("Data found: %c\n", data);
            return;
        }
        currentNode = currentNode->next;
    }

    printf("Data not found.\n");
}

int main() {
    Index* index = createIndex();

    insertIndex(index, 'a');
    insertIndex(index, 'b');
    insertIndex(index, 'c');

    searchIndex(index, 'b');

    return 0;
}