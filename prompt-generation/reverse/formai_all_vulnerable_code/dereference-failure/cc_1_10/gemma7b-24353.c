//Gemma-7B DATASET v1.0 Category: Greedy Algorithms ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void insertAtTail(Node** head, int data) {
    Node* newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        (*head)->next = newNode;
    }
}

void GreedyAlgos(Node** head) {
    int i = 0;
    int size = 0;
    Node* current = *head;

    while (current) {
        size++;
        current = current->next;
    }

    printf("Total number of nodes: %d\n", size);

    current = *head;
    while (i < size) {
        printf("Node %d: %d\n", i, current->data);
        i++;
        current = current->next;
    }
}

int main() {
    Node* head = NULL;
    insertAtTail(&head, 10);
    insertAtTail(&head, 20);
    insertAtTail(&head, 30);
    insertAtTail(&head, 40);

    GreedyAlgos(&head);

    return 0;
}