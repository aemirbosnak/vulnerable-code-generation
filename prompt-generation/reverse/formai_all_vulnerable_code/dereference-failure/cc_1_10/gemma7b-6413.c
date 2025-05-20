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
        ((*head)->next = newNode);
    }
}

int main() {
    Node* head = NULL;
    insertAtTail(&head, 10);
    insertAtTail(&head, 20);
    insertAtTail(&head, 30);
    insertAtTail(&head, 40);

    // Greedy Algorithm - Sort the linked list in ascending order based on data
    Node* current = head;
    Node* previous = NULL;
    while (current) {
        Node* next = current->next;
        if (previous && current->data < previous->data) {
            insertAtTail(&head, current->data);
            previous->next = next;
            current = next;
        } else {
            previous = current;
            current = next;
        }
    }

    // Print the sorted list
    current = head;
    while (current) {
        printf("%d ", current->data);
        current = current->next;
    }

    return 0;
}