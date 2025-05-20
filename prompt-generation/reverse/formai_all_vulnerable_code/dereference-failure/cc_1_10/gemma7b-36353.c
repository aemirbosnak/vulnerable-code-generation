//Gemma-7B DATASET v1.0 Category: Matrix operations ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

int main() {
    Node* head = NULL;

    // Decentralized Matrix Operations
    int matrixSize = MAX_SIZE;
    for (int i = 0; i < matrixSize; i++) {
        insertAtTail(&head, rand() % 10);
    }

    // Transpose the matrix
    Node* current = head;
    while (current) {
        int data = current->data;
        insertAtTail(&head, data);
        free(current);
        current = NULL;
    }

    // Print the transposed matrix
    current = head;
    while (current) {
        printf("%d ", current->data);
        current = current->next;
    }

    printf("\n");

    return 0;
}