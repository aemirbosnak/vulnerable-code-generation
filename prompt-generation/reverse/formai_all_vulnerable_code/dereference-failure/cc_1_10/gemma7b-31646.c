//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

#define MAX_SIZE 100

typedef struct Node {
    char name[MAX_SIZE];
    struct Node* next;
} Node;

typedef struct Index {
    char key[MAX_SIZE];
    struct Index* next;
} Index;

void insertNode(Node** head, char* name) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->name, name);
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        (*head)->next = newNode;
    }
}

void insertIndex(Index** head, char* key) {
    Index* newIndex = (Index*)malloc(sizeof(Index));
    strcpy(newIndex->key, key);
    newIndex->next = NULL;

    if (*head == NULL) {
        *head = newIndex;
    } else {
        (*head)->next = newIndex;
    }
}

void searchNode(Node* head, char* name) {
    while (head) {
        if (strcmp(head->name, name) == 0) {
            printf("Node found: %s\n", head->name);
            return;
        }
        head = head->next;
    }

    printf("Node not found.\n");
}

void searchIndex(Index* head, char* key) {
    while (head) {
        if (strcmp(head->key, key) == 0) {
            searchNode(head->next, key);
            return;
        }
        head = head->next;
    }

    printf("Node not found.\n");
}

int main() {
    Node* head = NULL;
    Index* indexHead = NULL;

    insertNode(&head, "John Doe");
    insertNode(&head, "Jane Doe");
    insertNode(&head, "Peter Pan");

    insertIndex(&indexHead, "John Doe");
    insertIndex(&indexHead, "Jane Doe");

    searchIndex(indexHead, "John Doe");
    searchNode(head, "Peter Pan");

    return 0;
}