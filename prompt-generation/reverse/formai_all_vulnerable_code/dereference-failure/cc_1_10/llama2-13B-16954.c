//LLAMA2-13B DATASET v1.0 Category: Searching algorithm ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 100

// Structure to represent a node in the search graph
typedef struct node {
    int data; // data stored in the node
    struct node* next; // pointer to the next node in the list
} Node;

// Function to create a new node
Node* newNode(int data) {
    Node* node = (Node*) malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Function to search for a specific value in a linked list
Node* search(Node* head, int target) {
    // Start at the beginning of the list
    Node* current = head;

    // Keep searching until we find the target or reach the end of the list
    while (current != NULL && current->data != target) {
        // If we reach a node with the target data, return it
        if (current->data == target) {
            return current;
        }

        // Move to the next node in the list
        current = current->next;
    }

    // If we reach the end of the list without finding the target, return NULL
    return NULL;
}

int main() {
    // Create an array of integers to search
    int arr[ARRAY_SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    // Create a linked list from the array
    Node* head = NULL;
    for (int i = 0; i < ARRAY_SIZE; i++) {
        head = head->next = newNode(arr[i]);
    }

    // Search for the value 7 in the list
    Node* result = search(head, 7);

    // Print the result
    if (result != NULL) {
        printf("Found value 7 at index %d\n", result->data);
    } else {
        printf("Value 7 not found in the list\n");
    }

    return 0;
}