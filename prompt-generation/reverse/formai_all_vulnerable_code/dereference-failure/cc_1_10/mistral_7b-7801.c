//MISTRAL-7B DATASET v1.0 Category: Searching algorithm ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Custom malloc and free functions for debugging purposes
#define debug_malloc(size) printf("Allocating %ld bytes\n", size), malloc(size)
#define debug_free(ptr) (printf("Freeing %p\n", ptr), free(ptr))

typedef struct node {
    int key;
    struct node* next;
} node;

// Function to print the linked list for debugging purposes
void print_list(node* head) {
    node* current = head;
    while (current != NULL) {
        printf("Key: %d, Next: %p\n", current->key, current->next);
        current = current->next;
    }
}

// Function to search for a key in the linked list using the C Searching algorithm
node* c_search(node* head, int key) {
    node* current = head;
    node* previous = NULL;

    // Search loop
    while (current != NULL) {
        // Compare keys
        if (current->key == key) {
            // Found the key, return the node
            printf("Found key %d at position %ld\n", key, (long)previous + 1);
            return current;
        }

        // Move to the next node
        previous = current;
        current = current->next;
    }

    // Key not found
    printf("Key %d not found\n", key);
    return NULL;
}

int main() {
    // Create an empty linked list
    node* head = NULL;

    // Allocate and add nodes to the linked list
    head = debug_malloc(sizeof(node));
    head->key = 5;
    head->next = debug_malloc(sizeof(node));
    head->next->key = 10;
    head->next->next = debug_malloc(sizeof(node));
    head->next->next->key = 15;
    head->next->next->next = NULL;

    // Print the linked list for debugging purposes
    print_list(head);

    // Search for a key in the linked list using the C Searching algorithm
    c_search(head, 10);

    // Free the allocated memory
    node* current = head;
    while (current != NULL) {
        node* next = current->next;
        debug_free(current);
        current = next;
    }

    return 0;
}