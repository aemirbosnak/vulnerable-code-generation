//LLAMA2-13B DATASET v1.0 Category: Searching algorithm ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 100

// Define a struct to represent a node in the search graph
struct node {
    int data;
    struct node *next;
};

// Define a function to create a new node
struct node* new_node(int data) {
    struct node* node = malloc(sizeof(struct node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Define a function to search for a specific value in the graph
struct node* search(struct node* head, int target) {
    // Initialize a pointer to the head of the list
    struct node* current = head;

    // Search the list until we find the target or reach the end
    while (current != NULL && current->data != target) {
        // If we reach the end of the list, return NULL
        if (current->next == NULL) {
            return NULL;
        }

        // Move to the next node in the list
        current = current->next;
    }

    // If we found the target, return the current node
    return current;
}

int main() {
    // Create an array of integers to search
    int arr[ARRAY_SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    // Create a list of nodes representing the array
    struct node* head = NULL;
    for (int i = 0; i < ARRAY_SIZE; i++) {
        head = head->next = new_node(arr[i]);
    }

    // Search for the value 5 in the list
    struct node* five = search(head, 5);

    // Print the result of the search
    if (five != NULL) {
        printf("Found %d at index %d\n", five->data, five->next == NULL ? -1 : (int)((struct node*)five->next)->data);
    } else {
        printf("Not found\n");
    }

    return 0;
}