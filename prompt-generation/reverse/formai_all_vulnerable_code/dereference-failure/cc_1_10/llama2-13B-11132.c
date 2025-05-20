//LLAMA2-13B DATASET v1.0 Category: Searching algorithm ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

// Structure to hold the elements of the array
typedef struct node {
    int data;
    struct node* next;
} node_t;

// Function to search an element in the array
node_t* search(node_t* head, int target) {
    // Create a pointer to the current node
    node_t* current = head;

    // Loop through the array until the target is found or the end of the array is reached
    while (current != NULL && current->data != target) {
        // If the current node has no next node, return NULL
        if (current->next == NULL) {
            return NULL;
        }

        // Move to the next node
        current = current->next;
    }

    // If the current node has the target data, return the current node
    return current;
}

int main() {
    // Create an array of integers
    node_t* head = NULL;
    int arr[5] = {1, 2, 3, 4, 5};

    // Loop through the array and add each element to the list
    for (int i = 0; i < 5; i++) {
        node_t* new_node = (node_t*)malloc(sizeof(node_t));
        new_node->data = arr[i];
        new_node->next = head;
        head = new_node;
    }

    // Search for the element 3 in the list
    node_t* search_node = search(head, 3);

    // Print the search result
    if (search_node != NULL) {
        printf("Element %d found at index %d\n", search_node->data, search_node->next == NULL ? 0 : 1);
    } else {
        printf("Element 3 not found\n");
    }

    return 0;
}