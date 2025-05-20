//MISTRAL-7B DATASET v1.0 Category: Recursive ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void reverseListRecursive(Node** head_ref, Node* prev, Node* current) {
    if (current == NULL) {
        *head_ref = prev;
        return;
    }

    reverseListRecursive(head_ref, current, current->next);
    current->next->next = prev;
    current->next = NULL;

    if (prev == NULL) {
        prev = current;
    }
}

void push(Node** head_ref, int newData) {
    Node* newNode = (Node*) malloc(sizeof(Node));

    newNode->data  = newData;
    newNode->next = (*head_ref);
    (*head_ref) = newNode;
}

void printList(Node *node) {
    while (node != NULL) {
        printf(" %d ", node->data);
        node = node->next;
    }
}

int main() {
    Node* head = NULL;

    push(&head, 7);
    push(&head, 1);
    push(&head, 3);
    push(&head, 2);

    printf("Given linked list: ");
    printList(head);

    reverseListRecursive(&head, NULL, head);

    printf("\nReversed linked list: ");
    printList(head);

    return 0;
}