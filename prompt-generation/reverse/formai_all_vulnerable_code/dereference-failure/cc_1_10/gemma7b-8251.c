//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INDEX_SIZE 10

typedef struct Node {
    char data[MAX_INDEX_SIZE];
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

void addToIndex(Index* index, char data[]) {
    Node* newNode = malloc(sizeof(Node));
    strcpy(newNode->data, data);
    newNode->next = NULL;

    if (index->head == NULL) {
        index->head = newNode;
    } else {
        index->head->next = newNode;
    }

    index->size++;
}

char searchIndex(Index* index, char query[]) {
    Node* current = index->head;
    while (current) {
        if (strcmp(current->data, query) == 0) {
            return current->data[0];
        }
        current = current->next;
    }

    return '\0';
}

int main() {
    Index* index = createIndex();
    addToIndex(index, "John");
    addToIndex(index, "Mary");
    addToIndex(index, "Bob");

    char result = searchIndex(index, "Mary");

    if (result) {
        printf("Found data: %c\n", result);
    } else {
        printf("Data not found.\n");
    }

    return 0;
}