//GEMINI-pro DATASET v1.0 Category: Linked list operations ; Style: intelligent
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
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Insert a new node at the beginning of the list
void insert_at_beginning(node_t **head, int data) {
    node_t *new_node = create_node(data);
    new_node->next = *head;
    *head = new_node;
}

// Insert a new node at the end of the list
void insert_at_end(node_t **head, int data) {
    node_t *new_node = create_node(data);
    node_t *current_node = *head;

    if (*head == NULL) {
        *head = new_node;
        return;
    }

    while (current_node->next != NULL) {
        current_node = current_node->next;
    }

    current_node->next = new_node;
}

// Insert a new node after a given node
void insert_after_node(node_t *prev_node, int data) {
    if (prev_node == NULL) {
        printf("Previous node cannot be NULL\n");
        return;
    }

    node_t *new_node = create_node(data);
    new_node->next = prev_node->next;
    prev_node->next = new_node;
}

// Delete a node from the beginning of the list
void delete_from_beginning(node_t **head) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }

    node_t *temp = *head;
    *head = (*head)->next;
    free(temp);
}

// Delete a node from the end of the list
void delete_from_end(node_t **head) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }

    node_t *current_node = *head;
    node_t *prev_node = NULL;

    while (current_node->next != NULL) {
        prev_node = current_node;
        current_node = current_node->next;
    }

    if (prev_node == NULL) {
        *head = NULL;
    } else {
        prev_node->next = NULL;
    }

    free(current_node);
}

// Delete a node from the middle of the list
void delete_node(node_t **head, node_t *node_to_delete) {
    if (*head == NULL || node_to_delete == NULL) {
        printf("Invalid input\n");
        return;
    }

    node_t *current_node = *head;
    node_t *prev_node = NULL;

    while (current_node != node_to_delete) {
        prev_node = current_node;
        current_node = current_node->next;
    }

    if (prev_node == NULL) {
        *head = (*head)->next;
    } else {
        prev_node->next = current_node->next;
    }

    free(current_node);
}

// Print the list
void print_list(node_t *head) {
    node_t *current_node = head;

    while (current_node != NULL) {
        printf("%d ", current_node->data);
        current_node = current_node->next;
    }

    printf("\n");
}

// Main function
int main() {
    node_t *head = NULL;

    // Insert some nodes into the list
    insert_at_beginning(&head, 10);
    insert_at_end(&head, 20);
    insert_after_node(head, 30);
    insert_at_end(&head, 40);
    insert_at_beginning(&head, 50);

    // Print the list
    printf("List before deletion:\n");
    print_list(head);

    // Delete a node from the beginning of the list
    delete_from_beginning(&head);

    // Delete a node from the end of the list
    delete_from_end(&head);

    // Delete a node from the middle of the list
    delete_node(&head, head->next);

    // Print the list
    printf("List after deletion:\n");
    print_list(head);

    return 0;
}