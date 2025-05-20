//GEMINI-pro DATASET v1.0 Category: Linked list operations ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>

// Define the node structure
typedef struct node {
    int data;
    struct node *next;
} node_t;

// Create a new node
node_t *create_node(int data) {
    node_t *new_node = malloc(sizeof(node_t));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Insert a node at the beginning of the list
node_t *insert_at_beginning(node_t *head, int data) {
    node_t *new_node = create_node(data);
    new_node->next = head;
    return new_node;
}

// Insert a node at the end of the list
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

// Insert a node at a specific position in the list
node_t *insert_at_position(node_t *head, int data, int position) {
    if (position == 0) {
        return insert_at_beginning(head, data);
    }

    node_t *new_node = create_node(data);

    node_t *current_node = head;
    for (int i = 0; i < position - 1; i++) {
        if (current_node->next == NULL) {
            return head;
        }
        current_node = current_node->next;
    }

    new_node->next = current_node->next;
    current_node->next = new_node;
    return head;
}

// Delete a node from the beginning of the list
node_t *delete_from_beginning(node_t *head) {
    if (head == NULL) {
        return NULL;
    }

    node_t *new_head = head->next;
    free(head);
    return new_head;
}

// Delete a node from the end of the list
node_t *delete_from_end(node_t *head) {
    if (head == NULL) {
        return NULL;
    }

    node_t *current_node = head;
    node_t *previous_node = NULL;

    while (current_node->next != NULL) {
        previous_node = current_node;
        current_node = current_node->next;
    }

    if (previous_node == NULL) {
        return NULL;
    }

    previous_node->next = NULL;
    free(current_node);
    return head;
}

// Delete a node from a specific position in the list
node_t *delete_from_position(node_t *head, int position) {
    if (position == 0) {
        return delete_from_beginning(head);
    }

    node_t *current_node = head;
    node_t *previous_node = NULL;

    for (int i = 0; i < position; i++) {
        if (current_node->next == NULL) {
            return head;
        }
        previous_node = current_node;
        current_node = current_node->next;
    }

    previous_node->next = current_node->next;
    free(current_node);
    return head;
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

// Free the list
void free_list(node_t *head) {
    node_t *current_node = head;
    while (current_node != NULL) {
        node_t *next_node = current_node->next;
        free(current_node);
        current_node = next_node;
    }
}

int main() {
    // Create the head of the list
    node_t *head = NULL;

    // Insert some data into the list
    head = insert_at_beginning(head, 1);
    head = insert_at_end(head, 2);
    head = insert_at_position(head, 3, 1);

    // Print the list
    printf("The list is: ");
    print_list(head);

    // Delete a node from the beginning of the list
    head = delete_from_beginning(head);

    // Delete a node from the end of the list
    head = delete_from_end(head);

    // Delete a node from a specific position in the list
    head = delete_from_position(head, 1);

    // Print the list
    printf("The list is now: ");
    print_list(head);

    // Free the list
    free_list(head);

    return 0;
}