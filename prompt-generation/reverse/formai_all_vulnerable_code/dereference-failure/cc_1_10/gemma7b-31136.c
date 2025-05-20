//Gemma-7B DATASET v1.0 Category: Classical Circuit Simulator ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

// Define a structure to represent a circuit node
typedef struct Node {
    int value;
    struct Node* next;
} Node;

// Function to insert a node into a circuit
void insertNode(Node** head, int value) {
    Node* newNode = malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        (*head)->next = newNode;
    }
}

// Function to simulate a circuit
void simulateCircuit(Node* head) {
    Node* current = head;
    while (current) {
        // Calculate the output value of the node
        int output = current->value * 2;

        // Print the output value
        printf("Node value: %d, Output value: %d\n", current->value, output);

        // Move to the next node
        current = current->next;
    }
}

int main() {
    // Create a circuit node
    Node* head = NULL;

    // Insert nodes into the circuit
    insertNode(&head, 5);
    insertNode(&head, 10);
    insertNode(&head, 15);

    // Simulate the circuit
    simulateCircuit(head);

    return 0;
}