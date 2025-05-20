//LLAMA2-13B DATASET v1.0 Category: Searching algorithm ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the structure to hold the data
struct node {
    int key;
    int value;
    struct node* next;
};

// Define the function to search the linked list
int search(struct node** head_ref, int key) {
    // Set the start and end pointers to the list
    struct node* start = *head_ref;
    struct node* end = start;

    // Loop until the end of the list is reached
    while (end != NULL) {
        // Check if the current node's key matches the search key
        if (end->key == key) {
            // Found the matching node, return its value
            return end->value;
        }

        // Move to the next node
        end = end->next;
    }

    // If the end of the list is reached and no match was found, return -1
    return -1;
}

// Example usage of the search function
int main() {
    // Create a linked list with some data
    struct node* head = NULL;
    head = malloc(sizeof(struct node));
    head->key = 10;
    head->value = 100;
    head->next = malloc(sizeof(struct node));
    head->next->key = 20;
    head->next->value = 200;
    head->next->next = malloc(sizeof(struct node));
    head->next->next->key = 30;
    head->next->next->value = 300;

    // Search the list for a key
    int result = search(&head, 25);

    // Print the result
    if (result != -1) {
        printf("Value found at key %d: %d\n", result, head->next->value);
    } else {
        printf("Key not found\n");
    }

    return 0;
}