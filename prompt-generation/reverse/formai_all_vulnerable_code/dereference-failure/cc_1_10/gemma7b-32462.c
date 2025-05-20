//Gemma-7B DATASET v1.0 Category: Greedy Algorithms ; Style: imaginative
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

void GreedyAlgorithm(Node** head) {
    Node* current = *head;
    Node* previous = NULL;
    int total = 0;

    while (current) {
        if (previous && current->data < previous->data) {
            insertAtTail(head, previous->data);
            previous->next = current;
            total++;
        }
        previous = current;
        current = current->next;
    }

    printf("Total number of operations: %d\n", total);
}

int main() {
    Node* head = NULL;
    insertAtTail(&head, 10);
    insertAtTail(&head, 20);
    insertAtTail(&head, 30);
    insertAtTail(&head, 40);
    insertAtTail(&head, 50);

    GreedyAlgorithm(&head);

    return 0;
}