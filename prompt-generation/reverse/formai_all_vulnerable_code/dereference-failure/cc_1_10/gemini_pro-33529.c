//GEMINI-pro DATASET v1.0 Category: Memory management ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

// Define a custom data structure to represent a node in a linked list
typedef struct node {
    int data;
    struct node *next;
} node_t;

// Function to create a new node with the given data and return it
node_t *create_node(int data) {
    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    if (new_node == NULL) {
        printf("Error: Unable to allocate memory for new node.\n");
        return NULL;
    }
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Function to insert a new node at the beginning of the linked list
void insert_at_beginning(node_t **head, int data) {
    node_t *new_node = create_node(data);
    if (new_node == NULL) {
        return;
    }
    new_node->next = *head;
    *head = new_node;
}

// Function to insert a new node at the end of the linked list
void insert_at_end(node_t **head, int data) {
    node_t *new_node = create_node(data);
    if (new_node == NULL) {
        return;
    }
    if (*head == NULL) {
        *head = new_node;
        return;
    }
    node_t *current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = new_node;
}

// Function to insert a new node after a given node in the linked list
void insert_after(node_t **head, node_t *prev_node, int data) {
    if (prev_node == NULL) {
        printf("Error: Previous node cannot be NULL.\n");
        return;
    }
    node_t *new_node = create_node(data);
    if (new_node == NULL) {
        return;
    }
    new_node->next = prev_node->next;
    prev_node->next = new_node;
}

// Function to delete a node from the linked list
void delete_node(node_t **head, node_t *node_to_delete) {
    if (*head == NULL || node_to_delete == NULL) {
        return;
    }
    if (*head == node_to_delete) {
        *head = node_to_delete->next;
    } else {
        node_t *current = *head;
        while (current->next != node_to_delete) {
            current = current->next;
        }
        current->next = node_to_delete->next;
    }
    free(node_to_delete);
}

// Function to print the linked list
void print_linked_list(node_t *head) {
    node_t *current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Main function to test the linked list operations
int main() {
    // Create an empty linked list
    node_t *head = NULL;

    // Insert some nodes into the linked list
    insert_at_beginning(&head, 10);
    insert_at_end(&head, 20);
    insert_after(head, head->next, 15);

    // Print the linked list
    printf("Initial linked list: ");
    print_linked_list(head);

    // Delete a node from the linked list
    delete_node(&head, head->next);

    // Print the linked list after deleting a node
    printf("Linked list after deleting a node: ");
    print_linked_list(head);

    // Free the linked list
    while (head != NULL) {
        node_t *next = head->next;
        free(head);
        head = next;
    }

    return 0;
}