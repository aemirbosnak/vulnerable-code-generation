//Falcon2-11B DATASET v1.0 Category: Network Topology Mapper ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the network topology
typedef struct node {
    int id;
    struct node* next;
} Node;

// Function to add a node to the network topology
void add_node(Node** head, int id) {
    // Allocate memory for a new node
    Node* new_node = (Node*)malloc(sizeof(Node));
    
    // Initialize the node with the given id
    new_node->id = id;
    
    // Set the next pointer of the new node to NULL
    new_node->next = NULL;
    
    // If the head is NULL, set it to the new node
    if (*head == NULL) {
        *head = new_node;
    }
    // Otherwise, add the new node to the tail of the linked list
    else {
        Node* current = *head;
        while (current->next!= NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
}

// Function to remove a node from the network topology
void remove_node(Node** head, int id) {
    // Find the node with the given id
    Node* current = *head;
    Node* prev = NULL;
    while (current!= NULL && current->id!= id) {
        prev = current;
        current = current->next;
    }
    
    // If the node was not found, return
    if (current == NULL) {
        return;
    }
    
    // Unlink the node from the linked list
    prev->next = current->next;
    
    // Free the memory occupied by the node
    free(current);
}

// Function to find a node in the network topology
Node* find_node(Node* head, int id) {
    // Find the node with the given id
    Node* current = head;
    while (current!= NULL && current->id!= id) {
        current = current->next;
    }
    
    // If the node was not found, return NULL
    if (current == NULL) {
        return NULL;
    }
    
    // Otherwise, return the node
    return current;
}

int main() {
    // Create a new linked list
    Node* head = NULL;
    
    // Add some nodes to the linked list
    add_node(&head, 1);
    add_node(&head, 2);
    add_node(&head, 3);
    
    // Find and remove a node from the linked list
    Node* node_to_remove = find_node(&head, 2);
    if (node_to_remove!= NULL) {
        remove_node(&head, 2);
    }
    
    // Print the remaining nodes in the linked list
    Node* current = head;
    while (current!= NULL) {
        printf("Node ID: %d\n", current->id);
        current = current->next;
    }
    
    return 0;
}