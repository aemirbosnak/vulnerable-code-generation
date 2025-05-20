//GEMINI-pro DATASET v1.0 Category: Memory management ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

// A simple linked list node
typedef struct node {
    int data;
    struct node *next;
} node_t;

// Create a new node with the given data
node_t *create_node(int data) {
    node_t *new_node = malloc(sizeof(node_t));
    if (new_node == NULL) {
        printf("Error allocating memory for new node\n");
        exit(1);
    }
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Insert a new node into the linked list after the given node
void insert_node(node_t *prev_node, node_t *new_node) {
    if (prev_node == NULL) {
        printf("Error: cannot insert node before NULL node\n");
        exit(1);
    }
    new_node->next = prev_node->next;
    prev_node->next = new_node;
}

// Delete the given node from the linked list
void delete_node(node_t *node) {
    if (node == NULL) {
        printf("Error: cannot delete NULL node\n");
        exit(1);
    }
    node_t *prev_node = node->next;
    free(node);
}

// Print the linked list
void print_list(node_t *head) {
    node_t *current_node = head;
    while (current_node != NULL) {
        printf("%d ", current_node->data);
        current_node = current_node->next;
    }
    printf("\n");
}

// Free the entire linked list
void free_list(node_t *head) {
    node_t *current_node = head;
    while (current_node != NULL) {
        node_t *next_node = current_node->next;
        free(current_node);
        current_node = next_node;
    }
}

// Main function
int main() {
    // Create a linked list
    node_t *head = create_node(10);
    insert_node(head, create_node(20));
    insert_node(head, create_node(30));
    insert_node(head, create_node(40));
    print_list(head); // Output: 10 20 30 40

    // Delete a node from the linked list
    delete_node(head->next->next);
    print_list(head); // Output: 10 20 40

    // Free the entire linked list
    free_list(head);

    return 0;
}