//GEMINI-pro DATASET v1.0 Category: Linked list operations ; Style: multivariable
#include <stdlib.h>
#include <stdio.h>

// Define the node structure
typedef struct node {
    int data;
    struct node *next;
} node_t;

// Initialize the linked list
node_t *head = NULL;

// Insert a node at the beginning of the linked list
void insert_at_beginning(int data) {
    // Create a new node
    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    new_node->data = data;
    new_node->next = head;

    // Update the head pointer
    head = new_node;
}

// Insert a node at the end of the linked list
void insert_at_end(int data) {
    // Create a new node
    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    new_node->data = data;
    new_node->next = NULL;

    // If the linked list is empty, set the head pointer to the new node
    if (head == NULL) {
        head = new_node;
        return;
    }

    // Otherwise, traverse the linked list until we reach the last node
    node_t *current_node = head;
    while (current_node->next != NULL) {
        current_node = current_node->next;
    }

    // Insert the new node at the end of the linked list
    current_node->next = new_node;
}

// Insert a node after a given node
void insert_after(node_t *prev_node, int data) {
    // Check if the given node is NULL
    if (prev_node == NULL) {
        printf("The given node is NULL\n");
        return;
    }

    // Create a new node
    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    new_node->data = data;

    // Insert the new node after the given node
    new_node->next = prev_node->next;
    prev_node->next = new_node;
}

// Delete a node from the linked list
void delete_node(node_t *node) {
    // Check if the given node is NULL
    if (node == NULL) {
        printf("The given node is NULL\n");
        return;
    }

    // If the node is the head node, update the head pointer
    if (node == head) {
        head = node->next;
    } else {
        // Otherwise, traverse the linked list until we find the node before the given node
        node_t *current_node = head;
        while (current_node->next != node) {
            current_node = current_node->next;
        }

        // Update the next pointer of the node before the given node
        current_node->next = node->next;
    }

    // Free the given node
    free(node);
}

// Print the linked list
void print_linked_list() {
    // If the linked list is empty, print "Empty linked list"
    if (head == NULL) {
        printf("Empty linked list\n");
        return;
    }

    // Otherwise, traverse the linked list and print the data of each node
    node_t *current_node = head;
    while (current_node != NULL) {
        printf("%d ", current_node->data);
        current_node = current_node->next;
    }

    printf("\n");
}

// Main function
int main() {
    // Insert some nodes into the linked list
    insert_at_beginning(1);
    insert_at_end(2);
    insert_after(head, 3);

    // Print the linked list
    printf("Linked list: ");
    print_linked_list();

    // Delete a node from the linked list
    delete_node(head->next);

    // Print the linked list again
    printf("Linked list after deletion: ");
    print_linked_list();

    return 0;
}