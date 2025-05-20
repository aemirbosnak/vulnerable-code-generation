//Gemma-7B DATASET v1.0 Category: Compression algorithms ; Style: standalone
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 1024

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

int compress(Node* head) {
    int count = 0;
    Node* current = head;
    Node* previous = NULL;

    while (current) {
        int runs = 1;
        while (previous && current && previous->data == current->data) {
            runs++;
            previous = previous->next;
        }

        if (runs > 1) {
            insertAtTail(&head, runs - 1);
            insertAtTail(&head, current->data);
        } else {
            insertAtTail(&head, current->data);
        }

        previous = current;
        current = current->next;
        count++;
    }

    return count;
}

int main() {
    Node* head = NULL;
    insertAtTail(&head, 1);
    insertAtTail(&head, 1);
    insertAtTail(&head, 2);
    insertAtTail(&head, 2);
    insertAtTail(&head, 2);
    insertAtTail(&head, 3);
    insertAtTail(&head, 3);

    int count = compress(head);

    printf("Number of nodes after compression: %d\n", count);

    return 0;
}