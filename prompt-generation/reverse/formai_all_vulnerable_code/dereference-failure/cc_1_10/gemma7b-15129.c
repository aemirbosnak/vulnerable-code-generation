//Gemma-7B DATASET v1.0 Category: Greedy Algorithms ; Style: lively
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

int main() {
    Node* head = NULL;
    insertAtTail(&head, 10);
    insertAtTail(&head, 20);
    insertAtTail(&head, 30);
    insertAtTail(&head, 40);
    insertAtTail(&head, 50);

    // Greedy Algorithm
    Node* current = head;
    Node* previous = NULL;
    while (current) {
        if (previous && current->data > previous->data) {
            printf("Swapping nodes %d and %d\n", previous->data, current->data);
            int temp = previous->data;
            previous->data = current->data;
            current->data = temp;
        }
        previous = current;
        current = current->next;
    }

    // Print the updated linked list
    current = head;
    while (current) {
        printf("%d ", current->data);
        current = current->next;
    }

    return 0;
}