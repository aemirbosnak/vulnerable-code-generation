//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct Node {
    char name[MAX_SIZE];
    struct Node* next;
} Node;

typedef struct Index {
    char keyword[MAX_SIZE];
    int count;
    struct Index* next;
} Index;

void insertNode(Node** head, char* name) {
    Node* newNode = malloc(sizeof(Node));
    strcpy(newNode->name, name);
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        (*head)->next = newNode;
    }
}

void insertIndex(Index** head, char* keyword, int count) {
    Index* newIndex = malloc(sizeof(Index));
    strcpy(newIndex->keyword, keyword);
    newIndex->count = count;
    newIndex->next = NULL;

    if (*head == NULL) {
        *head = newIndex;
    } else {
        (*head)->next = newIndex;
    }
}

int searchIndex(Index* head, char* keyword) {
    while (head) {
        if (strcmp(head->keyword, keyword) == 0) {
            return head->count;
        }
        head = head->next;
    }

    return -1;
}

int main() {
    Node* head = NULL;
    Index* indexHead = NULL;

    insertNode(&head, "John Doe");
    insertNode(&head, "Jane Doe");
    insertNode(&head, "Bill Smith");

    insertIndex(&indexHead, "John", 10);
    insertIndex(&indexHead, "Jane", 20);
    insertIndex(&indexHead, "Bill", 30);

    int result = searchIndex(indexHead, "John");

    if (result != -1) {
        printf("The count for John is: %d", result);
    } else {
        printf("John not found");
    }

    return 0;
}