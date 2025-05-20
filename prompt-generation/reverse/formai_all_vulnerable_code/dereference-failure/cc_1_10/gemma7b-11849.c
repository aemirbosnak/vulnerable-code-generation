//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct Node {
    char data[MAX];
    struct Node* next;
} Node;

void insert(Node** head, char data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->data, data);
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        (*head)->next = newNode;
        *head = newNode;
    }
}

void search(Node* head, char data) {
    if (head == NULL) {
        return;
    }

    if (strcmp(head->data, data) == 0) {
        printf("Data found: %s\n", head->data);
    } else if (strcmp(head->data, data) > 0) {
        search(head->next, data);
    } else {
        search(head->next, data);
    }
}

int main() {
    Node* head = NULL;

    insert(&head, 'a');
    insert(&head, 'b');
    insert(&head, 'c');
    insert(&head, 'd');
    insert(&head, 'e');

    search(head, 'c');

    return 0;
}