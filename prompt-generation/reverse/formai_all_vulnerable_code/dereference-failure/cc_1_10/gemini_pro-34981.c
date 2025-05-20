//GEMINI-pro DATASET v1.0 Category: Linked list operations ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>

// A node in the linked list
struct node {
    int data;
    struct node *next;
};

// The head of the linked list
struct node *head = NULL;

// Add a new node to the linked list
void add_node(int data) {
    // Create a new node
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;

    // If the linked list is empty, make the new node the head
    if (head == NULL) {
        head = new_node;
    } else {
        // Traverse the linked list until we find the last node
        struct node *current_node = head;
        while (current_node->next != NULL) {
            current_node = current_node->next;
        }

        // Make the new node the last node
        current_node->next = new_node;
    }
}

// Print the linked list
void print_list() {
    // Traverse the linked list and print each node's data
    struct node *current_node = head;
    while (current_node != NULL) {
        printf("%d ", current_node->data);
        current_node = current_node->next;
    }

    printf("\n");
}

// Free the linked list
void free_list() {
    // Traverse the linked list and free each node
    struct node *current_node = head;
    while (current_node != NULL) {
        struct node *next_node = current_node->next;
        free(current_node);
        current_node = next_node;
    }

    // Set the head to NULL
    head = NULL;
}

// Main function
int main() {
    // Add some nodes to the linked list
    add_node(1);
    add_node(2);
    add_node(3);
    add_node(4);
    add_node(5);

    // Print the linked list
    print_list();

    // Free the linked list
    free_list();

    return 0;
}