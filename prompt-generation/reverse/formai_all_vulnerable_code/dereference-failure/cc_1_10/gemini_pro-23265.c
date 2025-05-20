//GEMINI-pro DATASET v1.0 Category: Linked list operations ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

// Node of a linked list
typedef struct node {
    int data;
    struct node *next;
} node_t;

// Insert a node at the beginning of the linked list
node_t *insert_at_beginning(node_t *head, int data) {
    node_t *new_node = malloc(sizeof(node_t));
    new_node->data = data;
    new_node->next = head;
    return new_node;
}

// Insert a node at the end of the linked list
node_t *insert_at_end(node_t *head, int data) {
    node_t *new_node = malloc(sizeof(node_t));
    new_node->data = data;
    new_node->next = NULL;

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

// Insert a node at a given position in the linked list
node_t *insert_at_position(node_t *head, int data, int position) {
    node_t *new_node = malloc(sizeof(node_t));
    new_node->data = data;

    if (position == 0) {
        return insert_at_beginning(head, data);
    }

    node_t *current_node = head;
    for (int i = 0; i < position - 1; i++) {
        if (current_node == NULL) {
            return head;
        }
        current_node = current_node->next;
    }

    if (current_node == NULL) {
        return head;
    }

    new_node->next = current_node->next;
    current_node->next = new_node;
    return head;
}

// Delete a node from the beginning of the linked list
node_t *delete_from_beginning(node_t *head) {
    if (head == NULL) {
        return NULL;
    }

    node_t *new_head = head->next;
    free(head);
    return new_head;
}

// Delete a node from the end of the linked list
node_t *delete_from_end(node_t *head) {
    if (head == NULL) {
        return NULL;
    }

    if (head->next == NULL) {
        free(head);
        return NULL;
    }

    node_t *current_node = head;
    while (current_node->next->next != NULL) {
        current_node = current_node->next;
    }

    free(current_node->next);
    current_node->next = NULL;
    return head;
}

// Delete a node from a given position in the linked list
node_t *delete_from_position(node_t *head, int position) {
    if (position == 0) {
        return delete_from_beginning(head);
    }

    node_t *current_node = head;
    for (int i = 0; i < position - 1; i++) {
        if (current_node == NULL) {
            return head;
        }
        current_node = current_node->next;
    }

    if (current_node == NULL || current_node->next == NULL) {
        return head;
    }

    node_t *new_next = current_node->next->next;
    free(current_node->next);
    current_node->next = new_next;
    return head;
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

// Main function
int main() {
    // Create an empty linked list
    node_t *head = NULL;

    // Insert some nodes into the linked list
    head = insert_at_beginning(head, 1);
    head = insert_at_end(head, 2);
    head = insert_at_end(head, 3);
    head = insert_at_position(head, 4, 2);

    // Print the linked list
    print_list(head);

    // Delete some nodes from the linked list
    head = delete_from_beginning(head);
    head = delete_from_end(head);
    head = delete_from_position(head, 1);

    // Print the linked list
    print_list(head);

    // Free the linked list
    node_t *current_node = head;
    while (current_node != NULL) {
        node_t *next_node = current_node->next;
        free(current_node);
        current_node = next_node;
    }

    return 0;
}