//Gemma-7B DATASET v1.0 Category: Greedy Algorithms ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

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

void Greedy(Node* head) {
    Node* current = head;
    Node* previous = NULL;

    while (current) {
        if (previous && current->data < previous->data) {
            insertAtTail(previous, current->data);
            current = previous;
        } else {
            previous = current;
        }
    }

    printf("The rearranged list is:");
    while (previous) {
        printf(" %d ", previous->data);
        previous = previous->next;
    }
    printf("\n");
}

int main() {
    Node* head = NULL;
    insertAtTail(&head, 4);
    insertAtTail(&head, 3);
    insertAtTail(&head, 5);
    insertAtTail(&head, 2);
    insertAtTail(&head, 6);

    Greedy(head);

    return 0;
}