//Gemma-7B DATASET v1.0 Category: Greedy Algorithms ; Style: irregular
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

void greedyAlgorithm(Node* head) {
    int i = 0;
    Node* current = head;
    Node* previous = NULL;

    while (current) {
        int currentData = current->data;
        int previousData = previous ? previous->data : 0;

        if (currentData - previousData > MAX) {
            printf("Data gap too large: %d - %d\n", currentData, previousData);
            return;
        }

        previous = current;
        current = current->next;
        i++;
    }

    printf("Number of nodes processed: %d\n", i);
}

int main() {
    Node* head = NULL;
    insertAtTail(&head, 10);
    insertAtTail(&head, 20);
    insertAtTail(&head, 30);
    insertAtTail(&head, 40);
    insertAtTail(&head, 50);

    greedyAlgorithm(head);

    return 0;
}