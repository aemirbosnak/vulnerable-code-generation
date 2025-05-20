//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: innovative
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_INDEX_SIZE 100

typedef struct Node {
    char data[MAX_INDEX_SIZE];
    struct Node* next;
} Node;

typedef struct Index {
    Node* head;
    int size;
    time_t timestamp;
} Index;

Index* createIndex() {
    Index* index = malloc(sizeof(Index));
    index->head = NULL;
    index->size = 0;
    index->timestamp = time(NULL);
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

void searchIndex(Index* index, char query[]) {
    Node* current = index->head;
    while (current) {
        if (strcmp(current->data, query) == 0) {
            printf("Data found: %s\n", current->data);
        }
        current = current->next;
    }
}

int main() {
    Index* index = createIndex();
    addToIndex(index, "John Doe");
    addToIndex(index, "Jane Doe");
    addToIndex(index, "Peter Pan");

    searchIndex(index, "Jane Doe");

    return 0;
}