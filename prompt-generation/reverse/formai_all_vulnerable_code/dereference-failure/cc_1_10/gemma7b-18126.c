//Gemma-7B DATASET v1.0 Category: Data structures visualization ; Style: funny
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void insert(Node** head, int data) {
    Node* newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        (*head)->next = newNode;
    }
}

int main() {
    Node* head = NULL;
    insert(&head, 5);
    insert(&head, 10);
    insert(&head, 15);
    insert(&head, 20);

    printf("The linked list is:");
    Node* current = head;
    while (current) {
        printf(" %d ", current->data);
        current = current->next;
    }

    printf("\n");

    // Let's insert a new node at the end
    insert(&head, 25);

    printf("The updated linked list is:");
    current = head;
    while (current) {
        printf(" %d ", current->data);
        current = current->next;
    }

    return 0;
}