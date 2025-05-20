//Gemma-7B DATASET v1.0 Category: Data structures visualization ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

typedef struct Node {
    int data;
    struct Node* next;
} Node;

int main() {
    Node* head = NULL;
    int i = 0;

    // Allocate memory for the head node
    head = (Node*)malloc(sizeof(Node));

    // Initialize the head node
    head->data = 10;
    head->next = NULL;

    // Create a linked list
    for (i = 1; i < MAX_SIZE; i++) {
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->data = i;
        newNode->next = NULL;

        if (head->next != NULL) {
            head->next->next = newNode;
        } else {
            head->next = newNode;
        }
    }

    // Traverse the linked list
    Node* current = head;
    while (current) {
        printf("%d ", current->data);
        current = current->next;
    }

    // Free the memory allocated for the linked list
    current = head;
    while (current) {
        free(current);
        current = current->next;
    }

    return 0;
}