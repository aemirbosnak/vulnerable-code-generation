//Gemma-7B DATASET v1.0 Category: Sorting ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
        *head = newNode;
    }
}

void sortByData(Node* head) {
    Node* current = head;
    Node* previous = NULL;

    while (current) {
        Node* next = current->next;

        if (previous && current->data < previous->data) {
            int temp = current->data;
            current->data = previous->data;
            previous->data = temp;
        }

        previous = current;
        current = next;
    }

    head = previous;
}

int main() {
    Node* head = NULL;
    insertAtTail(&head, 4);
    insertAtTail(&head, 2);
    insertAtTail(&head, 8);
    insertAtTail(&head, 6);
    insertAtTail(&head, 3);

    sortByData(head);

    printf("Sorted list:");
    while (head) {
        printf(" %d", head->data);
        head = head->next;
    }

    printf("\n");

    return 0;
}