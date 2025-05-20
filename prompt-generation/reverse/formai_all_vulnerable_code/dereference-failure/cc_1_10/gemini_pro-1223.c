//GEMINI-pro DATASET v1.0 Category: Data structures visualization ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the node structure
typedef struct node {
    char *data;
    struct node *next;
} node_t;

// Create a new node
node_t *create_node(char *data) {
    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    new_node->data = strdup(data);
    new_node->next = NULL;
    return new_node;
}

// Insert a node at the beginning of the list
node_t *insert_at_beginning(node_t *head, node_t *new_node) {
    new_node->next = head;
    return new_node;
}

// Insert a node at the end of the list
node_t *insert_at_end(node_t *head, node_t *new_node) {
    if (head == NULL) {
        return new_node;
    }

    node_t *current = head;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = new_node;
    return head;
}

// Insert a node after a given node
node_t *insert_after(node_t *head, node_t *new_node, node_t *existing_node) {
    if (existing_node == NULL) {
        return head;
    }

    new_node->next = existing_node->next;
    existing_node->next = new_node;
    return head;
}

// Delete a node from the list
node_t *delete_node(node_t *head, node_t *node_to_delete) {
    if (node_to_delete == head) {
        return head->next;
    }

    node_t *current = head;
    while (current->next != node_to_delete) {
        current = current->next;
    }

    current->next = node_to_delete->next;
    free(node_to_delete);
    return head;
}

// Print the list
void print_list(node_t *head) {
    node_t *current = head;
    while (current != NULL) {
        printf("%s ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Free the list
void free_list(node_t *head) {
    node_t *current = head;
    while (current != NULL) {
        node_t *next = current->next;
        free(current->data);
        free(current);
        current = next;
    }
}

// Main function
int main() {
    // Create a list of strings
    node_t *head = create_node("Hello");
    head = insert_at_end(head, create_node("World"));
    head = insert_at_beginning(head, create_node("This"));
    head = insert_after(head, create_node("is"), head->next);

    // Print the list
    print_list(head);

    // Delete a node from the list
    head = delete_node(head, head->next);

    // Print the list again
    print_list(head);

    // Free the list
    free_list(head);

    return 0;
}