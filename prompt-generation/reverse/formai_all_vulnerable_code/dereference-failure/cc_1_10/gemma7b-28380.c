//Gemma-7B DATASET v1.0 Category: Greedy Algorithms ; Style: interoperable
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
    Node* current = head;
    Node* previous = NULL;
    int sum = 0;

    while (current) {
        sum += current->data;
        previous = current;
        current = current->next;
    }

    printf("The total sum of the nodes is: %d\n", sum);

    if (previous) {
        printf("The previous node is: %d\n", previous->data);
    }
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