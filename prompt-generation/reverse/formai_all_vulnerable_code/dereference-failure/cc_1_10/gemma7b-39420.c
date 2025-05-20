//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INDEX_SIZE 100

typedef struct Node {
    char name[MAX_INDEX_SIZE];
    struct Node* next;
} Node;

struct Index {
    Node* head;
    int size;
};

void insertIndex(struct Index* index, char* name) {
    Node* newNode = malloc(sizeof(Node));
    strcpy(newNode->name, name);
    newNode->next = NULL;

    if (index->head == NULL) {
        index->head = newNode;
    } else {
        index->head->next = newNode;
    }
    index->size++;
}

char* findIndex(struct Index* index, char* name) {
    Node* current = index->head;
    while (current) {
        if (strcmp(current->name, name) == 0) {
            return current->name;
        }
        current = current->next;
    }
    return NULL;
}

int main() {
    struct Index* myIndex = malloc(sizeof(struct Index));
    myIndex->head = NULL;
    myIndex->size = 0;

    insertIndex(myIndex, "Bob");
    insertIndex(myIndex, "Alice");
    insertIndex(myIndex, "Charlie");
    insertIndex(myIndex, "Dave");

    char* result = findIndex(myIndex, "Alice");

    if (result) {
        printf("Found: %s\n", result);
    } else {
        printf("Not found\n");
    }

    return 0;
}