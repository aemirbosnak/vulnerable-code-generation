//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DATA_SIZE 1024

typedef struct Node {
    char data[MAX_DATA_SIZE];
    struct Node* next;
} Node;

typedef struct IndexNode {
    char key[MAX_DATA_SIZE];
    struct IndexNode* next;
} IndexNode;

void insertData(Node** head, char* data) {
    Node* newNode = malloc(sizeof(Node));
    newNode->next = NULL;
    strcpy(newNode->data, data);

    if (*head == NULL) {
        *head = newNode;
    } else {
        (*head)->next = newNode;
    }
}

void insertIndex(IndexNode** head, char* key) {
    IndexNode* newNode = malloc(sizeof(IndexNode));
    newNode->next = NULL;
    strcpy(newNode->key, key);

    if (*head == NULL) {
        *head = newNode;
    } else {
        (*head)->next = newNode;
    }
}

void searchData(Node* head, char* key) {
    while (head) {
        if (strcmp(head->data, key) == 0) {
            printf("Data: %s\n", head->data);
            return;
        }
        head = head->next;
    }

    printf("Data not found\n");
}

int main() {
    Node* head = NULL;
    IndexNode* indexHead = NULL;

    insertData(&head, "John Doe");
    insertData(&head, "Jane Doe");
    insertData(&head, "Peter Pan");

    insertIndex(&indexHead, "John Doe");
    insertIndex(&indexHead, "Jane Doe");

    searchData(head, "Peter Pan");
    searchData(head, "John Doe");

    return 0;
}