//Gemma-7B DATASET v1.0 Category: Image Steganography ; Style: modular
#include <stdio.h>
#include <stdlib.h>

#define MAX_DATA 1024

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

int main() {
    Node* head = NULL;
    insertAtTail(&head, 10);
    insertAtTail(&head, 20);
    insertAtTail(&head, 30);

    int data = 40;
    insertAtTail(&head, data);

    printf("Data in the linked list:");
    for (Node* current = head; current; current = current->next) {
        printf(" %d ", current->data);
    }

    printf("\n");

    // Steganography: Hide data in the middle of the list
    int index = 2;
    Node* middle = head;
    for (int i = 0; i < index; i++) {
        middle = middle->next;
    }

    data = 50;
    insertAtTail(&middle, data);

    printf("Updated data in the linked list:");
    for (Node* current = head; current; current = current->next) {
        printf(" %d ", current->data);
    }

    return 0;
}