//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

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
    }
}

void search(Node* head, char data) {
    while (head) {
        if (strcmp(head->data, data) == 0) {
            printf("Data found: %s\n", head->data);
            return;
        }
        head = head->next;
    }

    printf("Data not found.\n");
}

int main() {
    Node* head = NULL;

    insert(&head, 'a');
    insert(&head, 'b');
    insert(&head, 'c');
    insert(&head, 'd');
    insert(&head, 'e');

    search(head, 'c');
    search(head, 'f');

    return 0;
}