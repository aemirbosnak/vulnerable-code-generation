//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_INDEX_SIZE 100

typedef struct Node {
    char key[MAX_INDEX_SIZE];
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

void insertIndex(Index* index, char key) {
    Node* newNode = malloc(sizeof(Node));
    newNode->key[0] = key;
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

char searchIndex(Index* index, char key) {
    Node* current = index->head;
    while (current) {
        if (strcmp(current->key, key) == 0) {
            return current->key[0];
        }
        current = current->next;
    }

    return '\0';
}

int main() {
    Index* index = createIndex();

    insertIndex(index, 'a');
    insertIndex(index, 'b');
    insertIndex(index, 'c');

    char result = searchIndex(index, 'b');

    if (result) {
        printf("Result: %c\n", result);
    } else {
        printf("Key not found.\n");
    }

    return 0;
}