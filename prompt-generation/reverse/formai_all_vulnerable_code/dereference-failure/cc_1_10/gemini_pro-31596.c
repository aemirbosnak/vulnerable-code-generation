//GEMINI-pro DATASET v1.0 Category: Memory management ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

// Define a custom data structure to hold a linked list of nodes
typedef struct node {
    int data;
    struct node *next;
} node_t;

// Function to create a new node and initialize its fields
node_t *create_node(int data) {
    // Allocate memory for the new node
    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    
    // Initialize the fields of the new node
    new_node->data = data;
    new_node->next = NULL;
    
    // Return the pointer to the new node
    return new_node;
}

// Function to insert a new node at the beginning of a linked list
node_t *insert_at_beginning(node_t **head, int data) {
    // Create a new node
    node_t *new_node = create_node(data);
    
    // Insert the new node at the beginning of the list
    new_node->next = *head;
    *head = new_node;
    
    // Return the pointer to the new head of the list
    return new_node;
}

// Function to insert a new node at the end of a linked list
node_t *insert_at_end(node_t **head, int data) {
    // Create a new node
    node_t *new_node = create_node(data);
    
    // Traverse the list to find the last node
    node_t *current_node = *head;
    while (current_node->next != NULL) {
        current_node = current_node->next;
    }
    
    // Insert the new node at the end of the list
    current_node->next = new_node;
    
    // Return the pointer to the new last node of the list
    return new_node;
}

// Function to delete a node from a linked list
void delete_node(node_t **head, int data) {
    // Traverse the list to find the node to be deleted
    node_t *current_node = *head;
    node_t *previous_node = NULL;
    while (current_node != NULL && current_node->data != data) {
        previous_node = current_node;
        current_node = current_node->next;
    }
    
    // If the node to be deleted was found
    if (current_node != NULL) {
        // If the node to be deleted is the first node in the list
        if (previous_node == NULL) {
            *head = current_node->next;
        } else {
            // Otherwise, bypass the node to be deleted
            previous_node->next = current_node->next;
        }
        
        // Free the memory allocated for the node to be deleted
        free(current_node);
    }
}

// Function to print a linked list
void print_list(node_t *head) {
    // Traverse the list and print the data in each node
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    
    // Print a newline at the end of the list
    printf("\n");
}

// Function to free the memory allocated for a linked list
void free_list(node_t **head) {
    // Traverse the list and free the memory allocated for each node
    while (*head != NULL) {
        node_t *current_node = *head;
        *head = (*head)->next;
        free(current_node);
    }
    
    // Set the head pointer to NULL
    *head = NULL;
}

// Main function
int main() {
    // Create an empty linked list
    node_t *head = NULL;
    
    // Insert some nodes into the linked list
    head = insert_at_beginning(&head, 10);
    head = insert_at_end(&head, 20);
    head = insert_at_beginning(&head, 30);
    head = insert_at_end(&head, 40);
    
    // Print the linked list
    printf("Linked list: ");
    print_list(head);
    
    // Delete a node from the linked list
    delete_node(&head, 20);
    
    // Print the linked list again
    printf("Linked list after deleting a node: ");
    print_list(head);
    
    // Free the memory allocated for the linked list
    free_list(&head);
    
    return 0;
}