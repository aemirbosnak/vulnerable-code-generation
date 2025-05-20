//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INDEX_SIZE 1024

typedef struct Node {
    char key[256];
    struct Node* next;
} Node;

void insert(Node** head, char key) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->key, key);
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* temp = *head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

int search(Node* head, char key) {
    Node* temp = head;
    while (temp) {
        if (strcmp(temp->key, key) == 0) {
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

int main() {
    Node* head = NULL;

    insert(&head, "John");
    insert(&head, "Alice");
    insert(&head, "Bob");

    if (search(head, "Alice") == 1) {
        printf("Alice is found.\n");
    }

    return 0;
}