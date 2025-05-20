//FormAI DATASET v1.0 Category: Data structures visualization ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the linked list
struct node {
    int data;
    struct node* next;
};

// Function to insert a new node at the beginning of the linked list
void insert(struct node** head_ref, int new_data) {
    // Allocate memory for new node
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    // Assign data to new node
    new_node->data = new_data;
    // Set next of new node to be the current head node
    new_node->next = (*head_ref);
    // Set the head reference to the new node
    (*head_ref) = new_node;
}

// Function to print the linked list
void print_list(struct node* node) {
    // Loop through the linked list
    while (node != NULL) {
        // Print the data of the current node
        printf("%d -> ", node->data);
        // Move to the next node
        node = node->next;
    }
    // Print NULL to indicate the end of the linked list
    printf("NULL\n");
}

int main() {
    // Initialize the head node to NULL to indicate an empty linked list
    struct node* head = NULL;
    
    // Insert nodes at the beginning of the linked list
    insert(&head, 5);
    insert(&head, 7);
    insert(&head, 9);
    insert(&head, 11);
    
    // Print the linked list
    printf("Linked List: ");
    print_list(head);
    
    return 0;
}