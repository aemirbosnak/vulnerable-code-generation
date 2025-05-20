//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct Node {
    char data[MAX_SIZE];
    struct Node* next;
} Node;

typedef struct Index {
    Node* head;
    struct Index* next;
} Index;

Index* insertIndex(Index* index, char data[]) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->data, data);
    newNode->next = NULL;

    if (index == NULL) {
        index = (Index*)malloc(sizeof(Index));
        index->head = newNode;
        index->next = NULL;
    } else {
        index->head->next = newNode;
        index->head = newNode;
    }

    return index;
}

void searchIndex(Index* index, char data[]) {
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
    Index* index = NULL;

    insertIndex(index, "John Doe");
    insertIndex(index, "Jane Doe");
    insertIndex(index, "Peter Pan");

    searchIndex(index, "Jane Doe");

    return 0;
}