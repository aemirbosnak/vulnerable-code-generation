//GEMINI-pro DATASET v1.0 Category: Memory management ; Style: interoperable
#include <stdlib.h>
#include <stdio.h>

// Define a custom memory allocation function
void *my_malloc(size_t size) {
    // Allocate memory using the standard malloc function
    void *ptr = malloc(size);

    // Check if the allocation was successful
    if (ptr == NULL) {
        // Allocation failed, print an error message and exit
        fprintf(stderr, "Error: Failed to allocate memory\n");
        exit(1);
    }

    // Return the allocated memory pointer
    return ptr;
}

// Define a custom memory deallocation function
void my_free(void *ptr) {
    // Deallocate memory using the standard free function
    free(ptr);
}

// Define a custom memory reallocation function
void *my_realloc(void *ptr, size_t size) {
    // Reallocate memory using the standard realloc function
    void *new_ptr = realloc(ptr, size);

    // Check if the reallocation was successful
    if (new_ptr == NULL) {
        // Reallocation failed, print an error message and exit
        fprintf(stderr, "Error: Failed to reallocate memory\n");
        exit(1);
    }

    // Return the reallocated memory pointer
    return new_ptr;
}

// Define a struct to represent a linked list node
typedef struct node {
    int data;
    struct node *next;
} node_t;

// Define a function to create a new linked list node
node_t *create_node(int data) {
    // Allocate memory for the new node
    node_t *node = (node_t *)my_malloc(sizeof(node_t));

    // Initialize the node's data and next pointer
    node->data = data;
    node->next = NULL;

    // Return the new node
    return node;
}

// Define a function to insert a new node into a linked list
void insert_node(node_t **head, int data) {
    // Create a new node
    node_t *new_node = create_node(data);

    // Insert the new node at the beginning of the list
    new_node->next = *head;
    *head = new_node;
}

// Define a function to delete a node from a linked list
void delete_node(node_t **head, int data) {
    // Find the node to be deleted
    node_t *current = *head;
    node_t *previous = NULL;
    while (current != NULL && current->data != data) {
        previous = current;
        current = current->next;
    }

    // If the node was found, delete it
    if (current != NULL) {
        if (previous == NULL) {
            // The node to be deleted is the head of the list
            *head = current->next;
        } else {
            // The node to be deleted is not the head of the list
            previous->next = current->next;
        }

        // Deallocate the memory for the deleted node
        my_free(current);
    }
}

// Define a function to print a linked list
void print_list(node_t *head) {
    // Traverse the linked list and print each node's data
    node_t *current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }

    // Print a newline character at the end
    printf("\n");
}

// Define a function to test the memory management and linked list functions
void test_functions() {
    // Create a linked list
    node_t *head = NULL;

    // Insert some nodes into the linked list
    insert_node(&head, 1);
    insert_node(&head, 2);
    insert_node(&head, 3);
    insert_node(&head, 4);
    insert_node(&head, 5);

    // Print the linked list
    printf("Linked list: ");
    print_list(head);

    // Delete a node from the linked list
    delete_node(&head, 3);

    // Print the linked list again
    printf("Linked list after deleting node 3: ");
    print_list(head);

    // Free the memory for the linked list
    while (head != NULL) {
        node_t *next = head->next;
        my_free(head);
        head = next;
    }
}

// Define the main function
int main() {
    // Test the memory management and linked list functions
    test_functions();

    return 0;
}