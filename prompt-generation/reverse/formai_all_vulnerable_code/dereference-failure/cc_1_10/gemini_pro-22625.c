//GEMINI-pro DATASET v1.0 Category: Data structures visualization ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Node structure for a singly linked list
typedef struct node {
    int data;
    struct node *next;
} node_t;

// Create a new node with the given data and next pointer
node_t *create_node(int data, node_t *next) {
    node_t *new_node = malloc(sizeof(node_t));
    if (new_node == NULL) {
        perror("Error allocating memory for new node");
        exit(EXIT_FAILURE);
    }
    new_node->data = data;
    new_node->next = next;
    return new_node;
}

// Insert a new node at the beginning of the list
node_t *insert_at_beginning(int data, node_t *head) {
    return create_node(data, head);
}

// Insert a new node at the end of the list
node_t *insert_at_end(int data, node_t *head) {
    if (head == NULL) {
        return create_node(data, NULL);
    }
    node_t *current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = create_node(data, NULL);
    return head;
}

// Print the list
void print_list(node_t *head) {
    printf("List: ");
    node_t *current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Free the list memory
void free_list(node_t *head) {
    node_t *current = head;
    while (current != NULL) {
        node_t *next = current->next;
        free(current);
        current = next;
    }
}

// Main function
int main() {
    // Create a singly linked list
    node_t *head = NULL;
    head = insert_at_beginning(1, head);
    head = insert_at_end(2, head);
    head = insert_at_end(3, head);
    head = insert_at_end(4, head);
    head = insert_at_end(5, head);

    // Print the list
    print_list(head);

    // Free the list memory
    free_list(head);

    return 0;
}