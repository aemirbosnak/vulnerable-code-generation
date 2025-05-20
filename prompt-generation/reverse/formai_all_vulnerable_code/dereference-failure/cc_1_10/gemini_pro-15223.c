//GEMINI-pro DATASET v1.0 Category: Memory management ; Style: complete
#include <stdio.h>
#include <stdlib.h>

// Define the size of the array
#define ARRAY_SIZE 10

// Define the structure of the node
typedef struct node {
    int data;
    struct node *next;
} node_t;

// Create a new node
node_t *create_node(int data) {
    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    if (new_node == NULL) {
        perror("Error allocating memory for new node");
        exit(1);
    }
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Insert a new node at the beginning of the linked list
node_t *insert_node_at_beginning(node_t *head, int data) {
    node_t *new_node = create_node(data);
    new_node->next = head;
    return new_node;
}

// Insert a new node at the end of the linked list
node_t *insert_node_at_end(node_t *head, int data) {
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

// Insert a new node at a specific position in the linked list
node_t *insert_node_at_position(node_t *head, int data, int position) {
    if (position == 0) {
        return insert_node_at_beginning(head, data);
    }
    node_t *new_node = create_node(data);
    node_t *current_node = head;
    int current_position = 0;
    while (current_node != NULL && current_position < position - 1) {
        current_node = current_node->next;
        current_position++;
    }
    if (current_node == NULL) {
        perror("Error: Invalid position");
        exit(1);
    }
    new_node->next = current_node->next;
    current_node->next = new_node;
    return head;
}

// Delete a node from the linked list
node_t *delete_node(node_t *head, int data) {
    node_t *current_node = head;
    node_t *previous_node = NULL;
    while (current_node != NULL && current_node->data != data) {
        previous_node = current_node;
        current_node = current_node->next;
    }
    if (current_node == NULL) {
        perror("Error: Node not found");
        exit(1);
    }
    if (previous_node == NULL) {
        head = current_node->next;
    } else {
        previous_node->next = current_node->next;
    }
    free(current_node);
    return head;
}

// Print the linked list
void print_linked_list(node_t *head) {
    node_t *current_node = head;
    while (current_node != NULL) {
        printf("%d ", current_node->data);
        current_node = current_node->next;
    }
    printf("\n");
}

// Free the linked list
void free_linked_list(node_t *head) {
    node_t *current_node = head;
    while (current_node != NULL) {
        node_t *next_node = current_node->next;
        free(current_node);
        current_node = next_node;
    }
}

int main() {
    // Create the linked list
    node_t *head = NULL;
    head = insert_node_at_beginning(head, 1);
    head = insert_node_at_end(head, 2);
    head = insert_node_at_position(head, 3, 1);
    head = insert_node_at_position(head, 4, 3);
    head = insert_node_at_position(head, 5, 5);

    // Print the linked list
    printf("Linked list: ");
    print_linked_list(head);

    // Delete a node from the linked list
    head = delete_node(head, 3);

    // Print the linked list
    printf("Linked list after deletion: ");
    print_linked_list(head);

    // Free the linked list
    free_linked_list(head);

    return 0;
}