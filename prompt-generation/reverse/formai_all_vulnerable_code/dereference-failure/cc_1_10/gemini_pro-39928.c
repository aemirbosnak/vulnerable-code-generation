//GEMINI-pro DATASET v1.0 Category: Linked list operations ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

// Define a node in the linked list
typedef struct node {
    int data;
    struct node *next;
} node;

// Define the head of the linked list
node *head = NULL;

// Function to insert a new node at the beginning of the linked list
void insert_at_beginning(int data) {
    // Create a new node
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = data;

    // Insert the new node at the beginning of the linked list
    new_node->next = head;
    head = new_node;
}

// Function to insert a new node after a given node
void insert_after_node(node *prev_node, int data) {
    // Create a new node
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = data;

    // Insert the new node after the given node
    new_node->next = prev_node->next;
    prev_node->next = new_node;
}

// Function to insert a new node at the end of the linked list
void insert_at_end(int data) {
    // Create a new node
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;

    // Traverse the linked list to find the last node
    node *last_node = head;
    while (last_node->next != NULL) {
        last_node = last_node->next;
    }

    // Insert the new node at the end of the linked list
    last_node->next = new_node;
}

// Function to delete a node from the linked list
void delete_node(int data) {
    // Traverse the linked list to find the node to be deleted
    node *current_node = head;
    node *prev_node = NULL;
    while (current_node != NULL && current_node->data != data) {
        prev_node = current_node;
        current_node = current_node->next;
    }

    // If the node to be deleted is not found, return
    if (current_node == NULL) {
        return;
    }

    // Delete the node from the linked list
    if (prev_node == NULL) {
        head = current_node->next;
    } else {
        prev_node->next = current_node->next;
    }
    free(current_node);
}

// Function to print the linked list
void print_linked_list() {
    // Traverse the linked list and print each node's data
    node *current_node = head;
    while (current_node != NULL) {
        printf("%d ", current_node->data);
        current_node = current_node->next;
    }
    printf("\n");
}

// Main function
int main() {
    // Insert some data into the linked list
    insert_at_beginning(1);
    insert_at_end(2);
    insert_at_end(3);
    insert_after_node(head, 4);

    // Print the linked list
    printf("Linked list: ");
    print_linked_list();

    // Delete a node from the linked list
    delete_node(2);

    // Print the linked list again
    printf("Linked list after deleting a node: ");
    print_linked_list();

    return 0;
}