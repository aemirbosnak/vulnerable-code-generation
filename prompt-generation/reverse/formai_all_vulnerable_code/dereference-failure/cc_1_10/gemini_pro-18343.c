//GEMINI-pro DATASET v1.0 Category: Educational ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of a node in a linked list.
struct node {
    int data;
    struct node *next;
};

// Create a new node with the given data.
struct node *create_node(int data) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Insert a new node at the head of the linked list.
void insert_at_head(struct node **head, struct node *new_node) {
    new_node->next = *head;
    *head = new_node;
}

// Insert a new node at the tail of the linked list.
void insert_at_tail(struct node **head, struct node *new_node) {
    if (*head == NULL) {
        *head = new_node;
        return;
    }
    struct node *current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = new_node;
}

// Delete a node from the linked list.
void delete_node(struct node **head, struct node *node_to_delete) {
    if (*head == node_to_delete) {
        *head = (*head)->next;
        free(node_to_delete);
        return;
    }
    struct node *current = *head;
    while (current->next != node_to_delete) {
        current = current->next;
    }
    current->next = node_to_delete->next;
    free(node_to_delete);
}

// Print the linked list.
void print_linked_list(struct node *head) {
    struct node *current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Free the linked list.
void free_linked_list(struct node *head) {
    struct node *current = head;
    while (current != NULL) {
        struct node *next = current->next;
        free(current);
        current = next;
    }
}

int main() {
    // Create a linked list.
    struct node *head = NULL;

    // Insert some nodes into the linked list.
    insert_at_head(&head, create_node(1));
    insert_at_head(&head, create_node(2));
    insert_at_head(&head, create_node(3));
    insert_at_tail(&head, create_node(4));
    insert_at_tail(&head, create_node(5));

    // Print the linked list.
    print_linked_list(head);

    // Delete a node from the linked list.
    delete_node(&head, head->next);

    // Print the linked list.
    print_linked_list(head);

    // Free the linked list.
    free_linked_list(head);

    return 0;
}