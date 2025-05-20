//Gemma-7B DATASET v1.0 Category: Greedy Algorithms ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

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

    Node* current = head;
    while (current) {
        printf("%d ", current->data);
        current = current->next;
    }

    printf("\n");

    // Greedy Algorithm - Sort the linked list in descending order

    current = head;
    while (current) {
        Node* previous = NULL;
        Node* current2 = current;
        while (current2) {
            if (current2->data > current->data) {
                int temp = current->data;
                current->data = current2->data;
                current2->data = temp;

                if (previous) {
                    previous->next = current;
                } else {
                    head = current;
                }
                previous = current;
            }
            current2 = current2->next;
        }
        current = current->next;
    }

    current = head;
    while (current) {
        printf("%d ", current->data);
        current = current->next;
    }

    printf("\n");

    return 0;
}