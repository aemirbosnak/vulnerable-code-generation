//GEMINI-pro DATASET v1.0 Category: Memory management ; Style: intelligent
#include <stdlib.h>
#include <stdio.h>

// Define a custom memory management function
void* my_malloc(size_t size) {
    // Allocate memory using the standard malloc function
    void* ptr = malloc(size);
    
    // Check if the allocation was successful
    if (ptr == NULL) {
        // If the allocation failed, print an error message and exit the program
        fprintf(stderr, "Error: malloc failed to allocate %zu bytes.\n", size);
        exit(EXIT_FAILURE);
    }
    
    // Return the pointer to the allocated memory
    return ptr;
}

// Define a custom memory deallocation function
void my_free(void* ptr) {
    // Deallocate memory using the standard free function
    free(ptr);
}

// Define a structure to represent a linked list node
typedef struct node {
    int data;
    struct node* next;
} node_t;

// Create a linked list using the custom memory management functions
node_t* create_linked_list() {
    // Allocate memory for the head of the linked list
    node_t* head = my_malloc(sizeof(node_t));
    
    // Set the data field of the head node
    head->data = 1;
    
    // Set the next field of the head node to NULL
    head->next = NULL;
    
    // Return the head of the linked list
    return head;
}

// Insert a new node into the linked list
void insert_node(node_t** head, int data) {
    // Allocate memory for the new node
    node_t* new_node = my_malloc(sizeof(node_t));
    
    // Set the data field of the new node
    new_node->data = data;
    
    // Set the next field of the new node to the head of the linked list
    new_node->next = *head;
    
    // Update the head of the linked list to point to the new node
    *head = new_node;
}

// Print the linked list
void print_linked_list(node_t* head) {
    // Iterate over the linked list and print the data field of each node
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    
    // Print a newline character at the end of the linked list
    printf("\n");
}

// Free the linked list
void free_linked_list(node_t* head) {
    // Iterate over the linked list and free each node
    while (head != NULL) {
        node_t* next_node = head->next;
        my_free(head);
        head = next_node;
    }
}

// Main function
int main() {
    // Create a linked list using the custom memory management functions
    node_t* head = create_linked_list();
    
    // Insert some nodes into the linked list
    insert_node(&head, 2);
    insert_node(&head, 3);
    insert_node(&head, 4);
    
    // Print the linked list
    print_linked_list(head);
    
    // Free the linked list
    free_linked_list(head);
    
    return 0;
}