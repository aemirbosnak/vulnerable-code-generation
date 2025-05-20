//GEMINI-pro DATASET v1.0 Category: Linked list operations ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the node structure
typedef struct node {
    int data;
    struct node *next;
} node;

// Initialize the head of the linked list
node *head = NULL;

// Function to create a new node
node *create_node(int data) {
    // Allocate memory for the new node
    node *new_node = (node *)malloc(sizeof(node));

    // Check if memory was allocated successfully
    if (new_node == NULL) {
        printf("Error: Could not allocate memory for new node.\n");
        exit(1);
    }

    // Set the data and next fields of the new node
    new_node->data = data;
    new_node->next = NULL;

    // Return the new node
    return new_node;
}

// Function to insert a node at the beginning of the linked list
void insert_at_beginning(int data) {
    // Create a new node
    node *new_node = create_node(data);

    // Set the next field of the new node to the current head of the linked list
    new_node->next = head;

    // Set the head of the linked list to the new node
    head = new_node;
}

// Function to insert a node at the end of the linked list
void insert_at_end(int data) {
    // Create a new node
    node *new_node = create_node(data);

    // If the linked list is empty, set the head of the linked list to the new node
    if (head == NULL) {
        head = new_node;
        return;
    }

    // Traverse the linked list until we reach the last node
    node *current_node = head;
    while (current_node->next != NULL) {
        current_node = current_node->next;
    }

    // Set the next field of the last node to the new node
    current_node->next = new_node;
}

// Function to insert a node after a given node
void insert_after(int data, int after_data) {
    // Traverse the linked list until we find the node after which we want to insert the new node
    node *current_node = head;
    while (current_node != NULL && current_node->data != after_data) {
        current_node = current_node->next;
    }

    // Check if the node after which we want to insert the new node was found
    if (current_node == NULL) {
        printf("Error: Could not find the node after which to insert the new node.\n");
        return;
    }

    // Create a new node
    node *new_node = create_node(data);

    // Set the next field of the new node to the next field of the node after which we want to insert the new node
    new_node->next = current_node->next;

    // Set the next field of the node after which we want to insert the new node to the new node
    current_node->next = new_node;
}

// Function to delete a node from the beginning of the linked list
void delete_from_beginning() {
    // Check if the linked list is empty
    if (head == NULL) {
        printf("Error: Linked list is empty.\n");
        return;
    }

    // Store the head of the linked list in a temporary variable
    node *temp = head;

    // Set the head of the linked list to the next node
    head = head->next;

    // Free the memory allocated for the temporary variable
    free(temp);
}

// Function to delete a node from the end of the linked list
void delete_from_end() {
    // Check if the linked list is empty
    if (head == NULL) {
        printf("Error: Linked list is empty.\n");
        return;
    }

    // If the linked list has only one node, set the head of the linked list to NULL
    if (head->next == NULL) {
        head = NULL;
        return;
    }

    // Traverse the linked list until we reach the last node
    node *current_node = head;
    while (current_node->next->next != NULL) {
        current_node = current_node->next;
    }

    // Store the last node in a temporary variable
    node *temp = current_node->next;

    // Set the next field of the second to last node to NULL
    current_node->next = NULL;

    // Free the memory allocated for the temporary variable
    free(temp);
}

// Function to delete a node from the linked list
void delete_node(int data) {
    // Check if the linked list is empty
    if (head == NULL) {
        printf("Error: Linked list is empty.\n");
        return;
    }

    // If the node to be deleted is the first node in the linked list, call the delete_from_beginning() function
    if (head->data == data) {
        delete_from_beginning();
        return;
    }

    // Traverse the linked list until we find the node to be deleted
    node *current_node = head;
    while (current_node->next != NULL && current_node->next->data != data) {
        current_node = current_node->next;
    }

    // Check if the node to be deleted was found
    if (current_node->next == NULL) {
        printf("Error: Could not find the node to be deleted.\n");
        return;
    }

    // Store the node to be deleted in a temporary variable
    node *temp = current_node->next;

    // Set the next field of the previous node to the next field of the node to be deleted
    current_node->next = current_node->next->next;

    // Free the memory allocated for the temporary variable
    free(temp);
}

// Function to search for a node in the linked list
node *search_node(int data) {
    // Traverse the linked list until we find the node with the given data
    node *current_node = head;
    while (current_node != NULL && current_node->data != data) {
        current_node = current_node->next;
    }

    // Return the node with the given data, or NULL if the node was not found
    return current_node;
}

// Function to print the linked list
void print_list() {
    // Traverse the linked list and print the data of each node
    node *current_node = head;
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
    insert_at_end(3);
    insert_at_end(4);
    insert_at_end(5);

    // Print the linked list
    printf("Linked list: ");
    print_list();

    // Search for a node in the linked list
    node *found_node = search_node(3);
    if (found_node != NULL) {
        printf("Node with data %d found.\n", found_node->data);
    } else {
        printf("Node with data 3 not found.\n");
    }

    // Delete a node from the linked list
    delete_node(2);

    // Print the linked list
    printf("Linked list after deleting node with data 2: ");
    print_list();

    // Free the memory allocated for the linked list
    node *current_node = head;
    while (current_node != NULL) {
        node *next_node = current_node->next;
        free(current_node);
        current_node = next_node;
    }

    return 0;
}