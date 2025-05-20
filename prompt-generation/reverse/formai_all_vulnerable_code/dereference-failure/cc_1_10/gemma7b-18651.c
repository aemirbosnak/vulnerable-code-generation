//Gemma-7B DATASET v1.0 Category: Greedy Algorithms ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

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

void greedyAlgorithm(Node* head) {
    int i = 0;
    Node* current = head;
    Node* previous = NULL;

    while (current) {
        int currentData = current->data;
        int previousData = previous ? previous->data : 0;

        if (currentData - previousData > 1) {
            printf("Data difference is greater than 1: %d - %d = %d\n", currentData, previousData, currentData - previousData);
        }

        previous = current;
        current = current->next;
    }
}

int main() {
    Node* head = NULL;
    insertAtTail(&head, 1);
    insertAtTail(&head, 2);
    insertAtTail(&head, 4);
    insertAtTail(&head, 3);

    greedyAlgorithm(head);

    return 0;
}