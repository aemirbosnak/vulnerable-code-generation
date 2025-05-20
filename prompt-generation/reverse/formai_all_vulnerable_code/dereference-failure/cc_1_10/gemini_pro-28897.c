//GEMINI-pro DATASET v1.0 Category: Memory management ; Style: invasive
#include <stdio.h>
#include <stdlib.h>

// A simple linked list node
typedef struct node {
    int data;
    struct node *next;
} node_t;

// Create a new node
node_t *create_node(int data) {
    node_t *new_node = malloc(sizeof(node_t));
    if (new_node == NULL) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    new_node->data = data;
    new_node->next = NULL;

    return new_node;
}

// Insert a new node at the beginning of the list
node_t *insert_at_beginning(node_t *head, int data) {
    node_t *new_node = create_node(data);
    if (head == NULL) {
        head = new_node;
        return head;
    }

    new_node->next = head;
    head = new_node;
    return head;
}

// Insert a new node at the end of the list
node_t *insert_at_end(node_t *head, int data) {
    node_t *new_node = create_node(data);
    if (head == NULL) {
        head = new_node;
        return head;
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
        return insert_at_beginning(head, data);
    }

    node_t *new_node = create_node(data);
    new_node->next = prev_node->next;
    prev_node->next = new_node;
    return head;
}

// Delete a node from the list
node_t *delete_node(node_t *head, node_t *node_to_delete) {
    if (node_to_delete == NULL) {
        return head;
    }

    if (node_to_delete == head) {
        head = head->next;
        free(node_to_delete);
        return head;
    }

    node_t *current = head;
    while (current->next != node_to_delete) {
        current = current->next;
    }

    current->next = node_to_delete->next;
    free(node_to_delete);
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

// Free the linked list
void free_list(node_t *head) {
    node_t *current = head;
    while (current != NULL) {
        node_t *next = current->next;
        free(current);
        current = next;
    }
}

int main(void) {
    // Create an empty linked list
    node_t *head = NULL;

    // Insert some nodes into the list
    head = insert_at_beginning(head, 1);
    head = insert_at_end(head, 2);
    head = insert_at_end(head, 3);
    head = insert_after(head, head->next, 4);

    // Print the linked list
    print_list(head);

    // Delete a node from the list
    head = delete_node(head, head->next);

    // Print the linked list again
    print_list(head);

    // Free the linked list
    free_list(head);

    return 0;
}