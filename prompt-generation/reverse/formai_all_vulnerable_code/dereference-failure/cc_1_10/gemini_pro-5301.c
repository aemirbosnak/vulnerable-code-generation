//GEMINI-pro DATASET v1.0 Category: Data structures visualization ; Style: realistic
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

// Define the node structure for the linked list.
typedef struct node {
    int data;
    struct node *next;
} node_t;

// Create a new node with the given data.
node_t *create_node(int data) {
    node_t *new_node = malloc(sizeof(node_t));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Insert a new node at the beginning of the linked list.
node_t *insert_at_beginning(node_t *head, int data) {
    node_t *new_node = create_node(data);
    new_node->next = head;
    return new_node;
}

// Insert a new node at the end of the linked list.
node_t *insert_at_end(node_t *head, int data) {
    node_t *new_node = create_node(data);
    if (head == NULL) {
        return new_node;
    }
    node_t *current_node = head;
    while (current_node->next != NULL) {
        current_node = current_node->next;
    }
    current_node->next = new_node;
    return head;
}

// Insert a new node after the given node.
node_t *insert_after(node_t *head, node_t *node, int data) {
    if (node == NULL) {
        return NULL;
    }
    node_t *new_node = create_node(data);
    new_node->next = node->next;
    node->next = new_node;
    return head;
}

// Delete the given node from the linked list.
node_t *delete_node(node_t *head, node_t *node) {
    if (node == NULL) {
        return NULL;
    }
    if (node == head) {
        head = node->next;
    } else {
        node_t *current_node = head;
        while (current_node->next != node) {
            current_node = current_node->next;
        }
        current_node->next = node->next;
    }
    free(node);
    return head;
}

// Print the linked list.
void print_list(node_t *head) {
    node_t *current_node = head;
    while (current_node != NULL) {
        printf("%d ", current_node->data);
        current_node = current_node->next;
    }
    printf("\n");
}

// Main function.
int main() {
    // Create a linked list.
    node_t *head = NULL;
    head = insert_at_beginning(head, 1);
    head = insert_at_beginning(head, 2);
    head = insert_at_end(head, 3);
    head = insert_after(head, head->next, 4);

    // Print the linked list.
    print_list(head);

    // Delete a node from the linked list.
    head = delete_node(head, head->next);

    // Print the linked list.
    print_list(head);

    // Free the linked list.
    while (head != NULL) {
        node_t *next_node = head->next;
        free(head);
        head = next_node;
    }

    return 0;
}