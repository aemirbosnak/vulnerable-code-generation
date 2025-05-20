//LLAMA2-13B DATASET v1.0 Category: Sorting ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100

// Structure to hold a list of integers
typedef struct node {
    int data;
    struct node* next;
} node_t;

// Function to sort a list of integers
void sort_list(node_t** head_ref) {
    // Step 1: Partition the list into two halves
    node_t* head = *head_ref;
    node_t* mid = head;
    node_t* tail = head;
    while (mid->next != NULL) {
        tail = mid->next;
        mid = mid->next->next;
    }
    mid->next = NULL;

    // Step 2: Recursively sort the two halves
    sort_list(&head);
    sort_list(&tail);

    // Step 3: Combine the two sorted halves
    head->next = tail;
    tail->next = NULL;
}

int main() {
    // Create a list of integers
    node_t* head = NULL;
    for (int i = 0; i < MAX_SIZE; i++) {
        node_t* new_node = malloc(sizeof(node_t));
        new_node->data = i % 2 == 0 ? -i : i;
        new_node->next = head;
        head = new_node;
    }

    // Sort the list
    sort_list(&head);

    // Print the sorted list
    for (node_t* current = head; current != NULL; current = current->next) {
        printf("%d ", current->data);
    }
    printf("\n");

    return 0;
}