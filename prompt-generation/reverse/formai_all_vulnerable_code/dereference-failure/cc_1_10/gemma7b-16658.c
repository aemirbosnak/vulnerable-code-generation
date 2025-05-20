//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>

// Define the indexing system structure
typedef struct IndexSystem {
    int size;
    int **data;
    struct IndexSystem **next;
} IndexSystem;

// Function to insert a key-value pair into the indexing system
void insert(IndexSystem **head, int key, int value) {
    IndexSystem *new_node = (IndexSystem *)malloc(sizeof(IndexSystem));
    new_node->size = 1;
    new_node->data = (int *)malloc(sizeof(int) * new_node->size);
    new_node->data[0] = value;
    new_node->next = NULL;

    if (*head == NULL) {
        *head = new_node;
    } else {
        (*head)->next = new_node;
    }
}

// Function to search for a key in the indexing system
int search(IndexSystem *head, int key) {
    while (head) {
        for (int i = 0; i < head->size; i++) {
            if (head->data[i] == key) {
                return i;
            }
        }
        head = head->next;
    }

    return -1;
}

int main() {
    IndexSystem *head = NULL;

    // Insert key-value pairs
    insert(&head, 10, 20);
    insert(&head, 20, 30);
    insert(&head, 30, 40);
    insert(&head, 40, 50);

    // Search for a key
    int result = search(head, 30);

    // Print the result
    if (result != -1) {
        printf("Key %d found at index %d\n", 30, result);
    } else {
        printf("Key %d not found\n", 30);
    }

    return 0;
}