//LLAMA2-13B DATASET v1.0 Category: Searching algorithm ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Structure to store the data
typedef struct node {
    int key;
    int value;
    struct node* next;
} Node;

// Function to create a new node
Node* newNode(int key, int value) {
    Node* node = malloc(sizeof(Node));
    node->key = key;
    node->value = value;
    node->next = NULL;
    return node;
}

// Function to search an element in the list
Node* search(Node* head, int key) {
    // Start at the beginning of the list
    Node* current = head;

    // Loop until we find the element or reach the end of the list
    while (current != NULL && current->key != key) {
        // If we reach the end of the list, return NULL
        if (current->next == NULL) {
            return NULL;
        }

        // Move to the next node
        current = current->next;
    }

    // If we found the element, return the node
    return current;
}

// Example usage
int main() {
    // Create a list of integers
    Node* head = NULL;
    head = newNode(1, 1);
    head = newNode(2, 2);
    head = newNode(3, 3);
    head = newNode(4, 4);
    head = newNode(5, 5);

    // Search for an element
    Node* result = search(head, 3);

    // Print the result
    if (result != NULL) {
        printf("Element found at index %d with value %d\n", result->key, result->value);
    } else {
        printf("Element not found\n");
    }

    return 0;
}