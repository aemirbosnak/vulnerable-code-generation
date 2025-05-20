//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INDEX_SIZE 100

typedef struct Node {
    char name[MAX_INDEX_SIZE];
    struct Node* next;
} Node;

typedef struct Index {
    Node* head;
    int size;
} Index;

Index* CreateIndex() {
    Index* index = (Index*)malloc(sizeof(Index));
    index->head = NULL;
    index->size = 0;
    return index;
}

void InsertIntoIndex(Index* index, char* name) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->name, name);
    newNode->next = NULL;

    if (index->head == NULL) {
        index->head = newNode;
    } else {
        Node* current = index->head;
        while (current->next) {
            current = current->next;
        }
        current->next = newNode;
    }

    index->size++;
}

int SearchIndex(Index* index, char* name) {
    Node* current = index->head;
    while (current) {
        if (strcmp(current->name, name) == 0) {
            return 1;
        }
        current = current->next;
    }
    return 0;
}

int main() {
    Index* index = CreateIndex();
    InsertIntoIndex(index, "John");
    InsertIntoIndex(index, "Mary");
    InsertIntoIndex(index, "Bob");
    InsertIntoIndex(index, "Alice");

    if (SearchIndex(index, "Mary") == 1) {
        printf("Mary is in the index.\n");
    }

    return 0;
}