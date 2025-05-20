//GEMINI-pro DATASET v1.0 Category: Linked list operations ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>

// Define the node structure
typedef struct node {
    int data;
    struct node *next;
} node_t;

// Create a new node
node_t *create_node(int data) {
    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    if (new_node == NULL) {
        printf("Error: malloc failed\n");
        return NULL;
    }
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Insert a new node at the beginning of the list
node_t *insert_at_beginning(node_t *head, int data) {
    node_t *new_node = create_node(data);
    if (new_node == NULL) {
        return head;
    }
    new_node->next = head;
    return new_node;
}

// Insert a new node at the end of the list
node_t *insert_at_end(node_t *head, int data) {
    node_t *new_node = create_node(data);
    if (new_node == NULL) {
        return head;
    }
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

// Insert a new node after a given node
node_t *insert_after(node_t *head, node_t *prev_node, int data) {
    if (prev_node == NULL) {
        return head;
    }
    node_t *new_node = create_node(data);
    if (new_node == NULL) {
        return head;
    }
    new_node->next = prev_node->next;
    prev_node->next = new_node;
    return head;
}

// Delete a node from the beginning of the list
node_t *delete_from_beginning(node_t *head) {
    if (head == NULL) {
        return NULL;
    }
    node_t *next_node = head->next;
    free(head);
    return next_node;
}

// Delete a node from the end of the list
node_t *delete_from_end(node_t *head) {
    if (head == NULL) {
        return NULL;
    }
    if (head->next == NULL) {
        free(head);
        return NULL;
    }
    node_t *current = head;
    while (current->next->next != NULL) {
        current = current->next;
    }
    free(current->next);
    current->next = NULL;
    return head;
}

// Delete a node from the middle of the list
node_t *delete_from_middle(node_t *head, node_t *node_to_delete) {
    if (head == NULL || node_to_delete == NULL) {
        return head;
    }
    if (node_to_delete == head) {
        return delete_from_beginning(head);
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
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Free the list
void free_list(node_t *head) {
    node_t *current = head;
    while (current != NULL) {
        node_t *next_node = current->next;
        free(current);
        current = next_node;
    }
}

// Main function
int main() {
    // Create a linked list
    node_t *head = NULL;
    head = insert_at_beginning(head, 10);
    head = insert_at_end(head, 20);
    head = insert_at_end(head, 30);
    head = insert_at_end(head, 40);

    // Print the list
    printf("Original list: ");
    print_list(head);

    // Insert a new node at the beginning of the list
    head = insert_at_beginning(head, 5);

    // Print the list
    printf("List after inserting a new node at the beginning: ");
    print_list(head);

    // Insert a new node at the end of the list
    head = insert_at_end(head, 50);

    // Print the list
    printf("List after inserting a new node at the end: ");
    print_list(head);

    // Insert a new node after a given node
    head = insert_after(head, head->next, 15);

    // Print the list
    printf("List after inserting a new node after a given node: ");
    print_list(head);

    // Delete a node from the beginning of the list
    head = delete_from_beginning(head);

    // Print the list
    printf("List after deleting a node from the beginning: ");
    print_list(head);

    // Delete a node from the end of the list
    head = delete_from_end(head);

    // Print the list
    printf("List after deleting a node from the end: ");
    print_list(head);

    // Delete a node from the middle of the list
    head = delete_from_middle(head, head->next->next);

    // Print the list
    printf("List after deleting a node from the middle: ");
    print_list(head);

    // Free the list
    free_list(head);

    return 0;
}