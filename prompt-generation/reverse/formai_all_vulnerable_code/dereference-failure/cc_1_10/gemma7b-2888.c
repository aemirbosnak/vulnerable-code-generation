//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INDEX_SIZE 1024

typedef struct Node {
    char data[MAX_INDEX_SIZE];
    struct Node* next;
} Node;

typedef struct Index {
    struct Node* head;
    struct Index* next;
} Index;

Index* insertIndex(Index* head, char* data) {
    Node* newNode = malloc(sizeof(Node));
    newNode->next = NULL;
    strcpy(newNode->data, data);

    if (head == NULL) {
        head = newNode;
    } else {
        head->next->next = newNode;
    }

    return head;
}

int searchIndex(Index* head, char* data) {
    Node* current = head->next;
    while (current) {
        if (strcmp(current->data, data) == 0) {
            return 1;
        }
        current = current->next;
    }

    return 0;
}

int main() {
    Index* index = NULL;
    insertIndex(index, "John Doe");
    insertIndex(index, "Jane Doe");
    insertIndex(index, "Bob Smith");

    if (searchIndex(index, "Jane Doe") == 1) {
        printf("Jane Doe is in the index.\n");
    }

    return 0;
}