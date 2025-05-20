//Gemma-7B DATASET v1.0 Category: Searching algorithm ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

// Define a structure to store a node
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function to search for a node in a linked list
Node* search(Node* head, int key) {
    // Iterate over the list until the end is reached or the key is found
    while (head) {
        // Check if the key is equal to the node's data
        if (head->data == key) {
            // Return the node
            return head;
        }

        // Move to the next node in the list
        head = head->next;
    }

    // Return null if the key is not found
    return NULL;
}

int main() {
    // Create a linked list
    Node* head = NULL;
    head = malloc(sizeof(Node));
    head->data = 10;
    head->next = malloc(sizeof(Node));
    head->next->data = 20;
    head->next->next = malloc(sizeof(Node));
    head->next->next->data = 30;
    head->next->next->next = NULL;

    // Search for a node in the list
    Node* node = search(head, 20);

    // Print the node's data
    if (node) {
        printf("Node found: %d\n", node->data);
    } else {
        printf("Node not found.\n");
    }

    return 0;
}