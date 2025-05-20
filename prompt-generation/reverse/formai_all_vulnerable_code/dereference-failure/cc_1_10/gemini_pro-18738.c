//GEMINI-pro DATASET v1.0 Category: Educational ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a custom data type for a linked list node
typedef struct Node {
    int data;
    struct Node *next;
} Node;

// Function to create a new linked list
Node *create_list(int *arr, int size) {
    Node *head = NULL;
    Node *current = NULL;

    for (int i = 0; i < size; i++) {
        // Create a new node
        Node *new_node = (Node *)malloc(sizeof(Node));

        // Set the data field of the new node
        new_node->data = arr[i];

        // Set the next field of the new node to point to the current node
        new_node->next = current;

        // Update the current node to point to the new node
        current = new_node;
    }

    // Return the head of the linked list
    return head;
}

// Function to print a linked list
void print_list(Node *head) {
    Node *current = head;

    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }

    printf("\n");
}

// Function to reverse a linked list
Node *reverse_list(Node *head) {
    Node *prev = NULL;
    Node *current = head;
    Node *next = NULL;

    while (current != NULL) {
        // Store the next node
        next = current->next;

        // Point the current node to the previous node
        current->next = prev;

        // Update the previous node to the current node
        prev = current;

        // Update the current node to the next node
        current = next;
    }

    // Return the new head of the linked list
    return prev;
}

// Function to main
int main() {
    // Create an array of integers
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    // Create a linked list from the array
    Node *head = create_list(arr, size);

    // Print the original linked list
    printf("Original linked list: ");
    print_list(head);

    // Reverse the linked list
    head = reverse_list(head);

    // Print the reversed linked list
    printf("Reversed linked list: ");
    print_list(head);

    return 0;
}