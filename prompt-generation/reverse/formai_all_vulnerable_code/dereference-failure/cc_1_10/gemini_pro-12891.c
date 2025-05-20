//GEMINI-pro DATASET v1.0 Category: Linked list operations ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>

// Node structure
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

// Insert a node at the beginning of the list
void insert_at_beginning(node_t **head, int data) {
    node_t *new_node = create_node(data);
    new_node->next = *head;
    *head = new_node;
}

// Insert a node at the end of the list
void insert_at_end(node_t **head, int data) {
    node_t *new_node = create_node(data);

    if (*head == NULL) {
        *head = new_node;
        return;
    }

    node_t *current_node = *head;
    while (current_node->next != NULL) {
        current_node = current_node->next;
    }

    current_node->next = new_node;
}

// Insert a node after a given node
void insert_after(node_t *prev_node, int data) {
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

    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }

    node_t *current_node = *head;
    node_t *prev_node = NULL;
    while (current_node->next != NULL) {
        prev_node = current_node;
        current_node = current_node->next;
    }

    prev_node->next = NULL;
    free(current_node);
}

// Delete a node after a given node
void delete_after(node_t *prev_node) {
    if (prev_node == NULL) {
        printf("Previous node cannot be NULL\n");
        return;
    }

    if (prev_node->next == NULL) {
        printf("No node after the given node\n");
        return;
    }

    node_t *temp = prev_node->next;
    prev_node->next = temp->next;
    free(temp);
}

// Reverse the linked list
void reverse_list(node_t **head) {
    node_t *prev_node = NULL;
    node_t *current_node = *head;
    node_t *next_node = NULL;

    while (current_node != NULL) {
        next_node = current_node->next;
        current_node->next = prev_node;
        prev_node = current_node;
        current_node = next_node;
    }

    *head = prev_node;
}

// Print the linked list
void print_list(node_t *head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }

    printf("\n");
}

// Main function
int main() {
    // Create a linked list
    node_t *head = NULL;

    // Insert some nodes
    insert_at_beginning(&head, 1);
    insert_at_end(&head, 2);
    insert_at_end(&head, 3);
    insert_after(head, 4);

    // Print the linked list
    printf("Original linked list: ");
    print_list(head);

    // Delete a node from the beginning
    delete_from_beginning(&head);

    // Delete a node from the end
    delete_from_end(&head);

    // Delete a node after a given node
    delete_after(head);

    // Reverse the linked list
    reverse_list(&head);

    // Print the linked list
    printf("Reversed linked list: ");
    print_list(head);

    // Free the linked list
    while (head != NULL) {
        node_t *temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}