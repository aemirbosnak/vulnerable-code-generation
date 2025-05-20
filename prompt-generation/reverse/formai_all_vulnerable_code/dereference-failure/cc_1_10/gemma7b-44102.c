//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INDEX_SIZE 10

typedef struct Node {
    char key[MAX_INDEX_SIZE];
    struct Node* next;
} Node;

typedef struct Index {
    Node* head;
    int size;
} Index;

void insertIndex(Index* index, char key) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->key, key);
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

int searchIndex(Index* index, char key) {
    Node* temp = index->head;
    while (temp) {
        if (strcmp(temp->key, key) == 0) {
            return 1;
        }
        temp = temp->next;
    }

    return 0;
}

int main() {
    Index* index = (Index*)malloc(sizeof(Index));
    index->head = NULL;
    index->size = 0;

    insertIndex(index, "a");
    insertIndex(index, "b");
    insertIndex(index, "c");
    insertIndex(index, "d");

    if (searchIndex(index, "b") == 1) {
        printf("Key b found.\n");
    }

    return 0;
}