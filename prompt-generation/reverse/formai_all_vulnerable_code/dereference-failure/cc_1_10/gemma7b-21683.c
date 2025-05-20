//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INDEX_SIZE 100

typedef struct Node {
    char data[MAX_INDEX_SIZE];
    struct Node* next;
} Node;

typedef struct Index {
    char key[MAX_INDEX_SIZE];
    int index;
    struct Index* next;
} Index;

void insertNode(Node** head, char data) {
    Node* newNode = malloc(sizeof(Node));
    newNode->data[0] = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        (*head)->next = newNode;
    }
}

void insertIndex(Index** head, char key, int index) {
    Index* newIndex = malloc(sizeof(Index));
    newIndex->key[0] = key;
    newIndex->index = index;
    newIndex->next = NULL;

    if (*head == NULL) {
        *head = newIndex;
    } else {
        (*head)->next = newIndex;
    }
}

void searchIndex(Index* head, char key) {
    while (head) {
        if (strcmp(head->key, key) == 0) {
            printf("Index: %d\n", head->index);
        }
        head = head->next;
    }
}

int main() {
    Node* head = NULL;
    Index* indexHead = NULL;

    insertNode(&head, 'a');
    insertNode(&head, 'b');
    insertNode(&head, 'c');

    insertIndex(&indexHead, 'a', 10);
    insertIndex(&indexHead, 'b', 20);
    insertIndex(&indexHead, 'c', 30);

    searchIndex(indexHead, 'a');

    return 0;
}