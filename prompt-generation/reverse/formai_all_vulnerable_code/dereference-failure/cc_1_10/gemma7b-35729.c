//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INDEX_SIZE 100

typedef struct Node {
    char data[MAX_INDEX_SIZE];
    struct Node* next;
} Node;

typedef struct Index {
    char index[MAX_INDEX_SIZE];
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

void insertIndex(Index** head, char index) {
    Index* newIndex = malloc(sizeof(Index));
    newIndex->index[0] = index;
    newIndex->next = NULL;

    if (*head == NULL) {
        *head = newIndex;
    } else {
        (*head)->next = newIndex;
    }
}

void search(Node* head, Index* headIndex, char query) {
    while (head) {
        if (strcmp(head->data, query) == 0) {
            printf("Data found: %s\n", head->data);
            break;
        }
        head = head->next;
    }

    while (headIndex) {
        if (headIndex->index[0] == query) {
            printf("Index found: %c\n", headIndex->index[0]);
            break;
        }
        headIndex = headIndex->next;
    }
}

int main() {
    Node* head = NULL;
    Index* headIndex = NULL;

    insertNode(&head, 'a');
    insertNode(&head, 'b');
    insertNode(&head, 'c');
    insertIndex(&headIndex, 'a');
    insertIndex(&headIndex, 'b');
    insertIndex(&headIndex, 'c');

    search(head, headIndex, 'b');

    return 0;
}