//GEMINI-pro DATASET v1.0 Category: Memory management ; Style: modular
#include <stdio.h>
#include <stdlib.h>

// Define a custom memory allocation function
void *my_malloc(size_t size) {
    // Allocate memory using the standard malloc function
    void *ptr = malloc(size);

    // Check if the allocation was successful
    if (ptr == NULL) {
        // If the allocation failed, print an error message and exit the program
        fprintf(stderr, "Error: memory allocation failed.\n");
        exit(1);
    }

    // Return the allocated memory address
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
        // If the reallocation failed, print an error message and exit the program
        fprintf(stderr, "Error: memory reallocation failed.\n");
        exit(1);
    }

    // Return the reallocated memory address
    return new_ptr;
}

// Define a struct to store a linked list of integers
typedef struct node {
    int data;
    struct node *next;
} node;

// Define a function to create a new linked list node
node *create_node(int data) {
    // Allocate memory for the new node
    node *new_node = my_malloc(sizeof(node));

    // Set the data field of the new node
    new_node->data = data;

    // Set the next field of the new node to NULL
    new_node->next = NULL;

    // Return the new node
    return new_node;
}

// Define a function to insert a new node into a linked list
void insert_node(node **head, int data) {
    // Create a new node
    node *new_node = create_node(data);

    // If the head of the linked list is NULL, set the head to the new node
    if (*head == NULL) {
        *head = new_node;
    } else {
        // Otherwise, traverse the linked list until we reach the end
        node *current_node = *head;
        while (current_node->next != NULL) {
            current_node = current_node->next;
        }

        // Insert the new node at the end of the linked list
        current_node->next = new_node;
    }
}

// Define a function to print a linked list
void print_list(node *head) {
    // Traverse the linked list and print the data field of each node
    node *current_node = head;
    while (current_node != NULL) {
        printf("%d ", current_node->data);
        current_node = current_node->next;
    }

    // Print a newline character at the end of the list
    printf("\n");
}

// Define a function to free a linked list
void free_list(node *head) {
    // Traverse the linked list and free each node
    node *current_node = head;
    while (current_node != NULL) {
        node *next_node = current_node->next;
        my_free(current_node);
        current_node = next_node;
    }
}

// Define a function to test the memory management functions
void test_memory_management() {
    // Create a linked list
    node *head = NULL;

    // Insert some nodes into the linked list
    insert_node(&head, 1);
    insert_node(&head, 2);
    insert_node(&head, 3);

    // Print the linked list
    print_list(head);

    // Free the linked list
    free_list(head);
}

// Define the main function
int main() {
    // Test the memory management functions
    test_memory_management();

    return 0;
}