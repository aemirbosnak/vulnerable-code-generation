//GEMINI-pro DATASET v1.0 Category: Linked list operations ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>

// Define the linked list node
typedef struct node {
    int data;
    struct node *next;
} node_t;

// Create a new linked list
node_t *create_list() {
    return NULL;
}

// Insert an element at the beginning of the linked list
node_t *insert_at_beginning(node_t *head, int data) {
    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    new_node->data = data;
    new_node->next = head;
    return new_node;
}

// Insert an element at the end of the linked list
node_t *insert_at_end(node_t *head, int data) {
    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    new_node->data = data;
    new_node->next = NULL;

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

// Insert an element at a specific position in the linked list
node_t *insert_at_position(node_t *head, int data, int position) {
    if (position == 0) {
        return insert_at_beginning(head, data);
    }

    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    new_node->data = data;

    node_t *current = head;
    for (int i = 0; i < position - 1; i++) {
        current = current->next;
    }

    new_node->next = current->next;
    current->next = new_node;
    return head;
}

// Delete an element from the beginning of the linked list
node_t *delete_from_beginning(node_t *head) {
    if (head == NULL) {
        return NULL;
    }

    node_t *new_head = head->next;
    free(head);
    return new_head;
}

// Delete an element from the end of the linked list
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

// Delete an element from a specific position in the linked list
node_t *delete_from_position(node_t *head, int position) {
    if (position == 0) {
        return delete_from_beginning(head);
    }

    node_t *current = head;
    for (int i = 0; i < position - 1; i++) {
        current = current->next;
    }

    node_t *next_node = current->next->next;
    free(current->next);
    current->next = next_node;
    return head;
}

// Print the linked list
void print_list(node_t *head) {
    node_t *current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Main function
int main() {
    // Create a linked list
    node_t *head = create_list();

    // Insert elements into the linked list
    head = insert_at_beginning(head, 10);
    head = insert_at_end(head, 20);
    head = insert_at_position(head, 15, 1);

    // Print the linked list
    printf("Original linked list: ");
    print_list(head);

    // Delete an element from the beginning of the linked list
    head = delete_from_beginning(head);

    // Print the linked list
    printf("Linked list after deleting from beginning: ");
    print_list(head);

    // Delete an element from the end of the linked list
    head = delete_from_end(head);

    // Print the linked list
    printf("Linked list after deleting from end: ");
    print_list(head);

    // Delete an element from a specific position in the linked list
    head = delete_from_position(head, 1);

    // Print the linked list
    printf("Linked list after deleting from position 1: ");
    print_list(head);

    return 0;
}