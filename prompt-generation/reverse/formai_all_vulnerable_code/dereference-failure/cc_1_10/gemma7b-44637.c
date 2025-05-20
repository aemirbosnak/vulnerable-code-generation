//Gemma-7B DATASET v1.0 Category: Linked list operations ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void insertAtTail(Node** head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        (*head)->next = newNode;
    }
}

void deleteFromTail(Node** head) {
    Node* prev = NULL;
    Node* current = *head;

    while (current->next) {
        prev = current;
        current = current->next;
    }

    if (prev) {
        prev->next = NULL;
    } else {
        *head = NULL;
    }
}

int main() {
    Node* head = NULL;

    insertAtTail(&head, 10);
    insertAtTail(&head, 20);
    insertAtTail(&head, 30);

    deleteFromTail(&head);

    printf("Head: %d", head->data);
    printf("\nTail: %d", (head->next)->data);

    return 0;
}