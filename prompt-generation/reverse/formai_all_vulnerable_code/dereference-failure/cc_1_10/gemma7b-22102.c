//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INDEX_SIZE 10

typedef struct Node {
    char data[MAX_INDEX_SIZE];
    struct Node* next;
} Node;

struct Index {
    Node* head;
    int size;
};

void insertIndex(struct Index* index, char data) {
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

void searchIndex(struct Index* index, char data) {
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
    struct Index* index = malloc(sizeof(struct Index));
    index->head = NULL;
    index->size = 0;

    insertIndex(index, "John");
    insertIndex(index, "Mary");
    insertIndex(index, "Bob");

    searchIndex(index, "Mary");
    searchIndex(index, "Bob");

    return 0;
}