//Gemma-7B DATASET v1.0 Category: Compression algorithms ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1024

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

int compress(Node** head) {
    int count = 0;
    Node* current = *head;

    while (current) {
        int runLength = 1;
        Node* previous = NULL;

        while (current->next && current->data == previous->data) {
            runLength++;
            previous = current;
            current = current->next;
        }

        if (runLength > 1) {
            insertAtTail(head, runLength);
            count++;
        }

        previous = current;
        current = current->next;
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

    int count = compress(&head);

    printf("Number of nodes reduced: %d\n", count);

    return 0;
}