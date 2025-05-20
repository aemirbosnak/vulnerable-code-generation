//Falcon2-11B DATASET v1.0 Category: Queue Implementation ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>

// Node structure for the decentralized queue
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function to add an element to the queue
void addToQueue(Node** head_ref, int data) {
    // Create a new node with the given data
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;

    // If the queue is empty, set the new node as the head
    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }

    // Otherwise, traverse the queue until the end and insert the new node
    Node* current = *head_ref;
    while (current->next!= NULL) {
        current = current->next;
    }
    current->next = new_node;
}

// Function to remove an element from the queue
int removeFromQueue(Node** head_ref) {
    // If the queue is empty, return -1
    if (*head_ref == NULL) {
        return -1;
    }

    // Otherwise, traverse the queue until the end and remove the first node
    Node* current = *head_ref;
    Node* next = current->next;
    free(current);
    *head_ref = next;
    return current->data;
}

int main() {
    // Create an array of nodes
    Node* nodes[5];

    // Initialize the nodes
    for (int i = 0; i < 5; i++) {
        nodes[i] = NULL;
    }

    // Add elements to the queues of the nodes
    addToQueue(&nodes[0], 1);
    addToQueue(&nodes[1], 2);
    addToQueue(&nodes[2], 3);
    addToQueue(&nodes[3], 4);
    addToQueue(&nodes[4], 5);

    // Remove elements from the queues of the nodes
    printf("Nodes: ");
    for (int i = 0; i < 5; i++) {
        if (removeFromQueue(&nodes[i]) == -1) {
            printf("Queue is empty\n");
        } else {
            printf("%d ", removeFromQueue(&nodes[i]));
        }
    }

    return 0;
}