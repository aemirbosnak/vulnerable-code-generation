//FormAI DATASET v1.0 Category: Linked list operations ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>

// Define the linked list node struct
typedef struct node {
    int data;
    struct node *next;
} node_t;

// Function to create a new node with the given data and next pointer
node_t *create_node(int data, node_t *next) {
    node_t *new_node = malloc(sizeof(node_t));
    new_node->data = data;
    new_node->next = next;
    return new_node;
}

// Function to insert a new node at the beginning of the list
node_t *insert_at_beginning(node_t *head, int data) {
    node_t *new_node = create_node(data, head);
    return new_node;
}

// Function to insert a new node at the end of the list
node_t *insert_at_end(node_t *head, int data) {
    if (head == NULL) {
        return create_node(data, NULL);
    }

    node_t *current_node = head;
    while (current_node->next != NULL) {
        current_node = current_node->next;
    }

    current_node->next = create_node(data, NULL);
    return head;
}

// Function to insert a new node at the given position in the list
node_t *insert_at_position(node_t *head, int data, int position) {
    if (position == 0) {
        return insert_at_beginning(head, data);
    }

    node_t *current_node = head;
    int i;
    for (i = 1; i < position; i++) {
        if (current_node == NULL) {
            printf("Error: invalid position %d for insertion\n", position);
            return head;
        }
        current_node = current_node->next;
    }

    if (current_node == NULL) {
        printf("Error: invalid position %d for insertion\n", position);
        return head;
    }

    node_t *new_node = create_node(data, current_node->next);
    current_node->next = new_node;
    return head;
}

// Function to delete the node at the beginning of the list
node_t *delete_at_beginning(node_t *head) {
    if (head == NULL) {
        printf("Error: empty list\n");
        return head;
    }

    node_t *new_head = head->next;
    free(head);
    return new_head;
}

// Function to delete the node at the end of the list
node_t *delete_at_end(node_t *head) {
    if (head == NULL) {
        printf("Error: empty list\n");
        return head;
    }

    node_t *current_node = head;
    node_t *previous_node = NULL;
    while (current_node->next != NULL) {
        previous_node = current_node;
        current_node = current_node->next;
    }

    if (previous_node == NULL) {
        return delete_at_beginning(head);
    }

    previous_node->next = NULL;
    free(current_node);
    return head;
}

// Function to delete the node at the given position in the list
node_t *delete_at_position(node_t *head, int position) {
    if (head == NULL) {
        printf("Error: empty list\n");
        return head;
    }

    if (position == 0) {
        return delete_at_beginning(head);
    }

    node_t *current_node = head;
    node_t *previous_node = NULL;
    int i;
    for (i = 0; i < position; i++) {
        if (current_node == NULL) {
            printf("Error: invalid position %d for deletion\n", position);
            return head;
        }
        previous_node = current_node;
        current_node = current_node->next;
    }

    if (current_node == NULL) {
        printf("Error: invalid position %d for deletion\n", position);
        return head;
    }

    if (previous_node == NULL) {
        return delete_at_beginning(head);
    }

    previous_node->next = current_node->next;
    free(current_node);
    return head;
}

// Function to print the linked list
void print_list(node_t *head) {
    node_t *current_node = head;
    while (current_node != NULL) {
        printf("%d -> ", current_node->data);
        current_node = current_node->next;
    }
    printf("NULL\n");
}

int main() {
    // Create an empty linked list
    node_t *head = NULL;

    // Insert some nodes at the beginning
    head = insert_at_beginning(head, 1);
    head = insert_at_beginning(head, 2);
    head = insert_at_beginning(head, 3);
    printf("Linked list after inserting at beginning:\n");
    print_list(head);

    // Insert some nodes at the end
    head = insert_at_end(head, 4);
    head = insert_at_end(head, 5);
    head = insert_at_end(head, 6);
    printf("Linked list after inserting at end:\n");
    print_list(head);

    // Insert a node at a specific position
    head = insert_at_position(head, 7, 0);
    head = insert_at_position(head, 8, 2);
    head = insert_at_position(head, 9, 7);
    printf("Linked list after inserting at positions:\n");
    print_list(head);

    // Delete some nodes from the beginning
    head = delete_at_beginning(head);
    head = delete_at_beginning(head);
    head = delete_at_beginning(head);
    printf("Linked list after deleting from beginning:\n");
    print_list(head);

    // Delete some nodes from the end
    head = delete_at_end(head);
    head = delete_at_end(head);
    head = delete_at_end(head);
    printf("Linked list after deleting from end:\n");
    print_list(head);

    // Delete a node at a specific position
    head = delete_at_position(head, 0);
    head = delete_at_position(head, 2);
    head = delete_at_position(head, 5);
    printf("Linked list after deleting from positions:\n");
    print_list(head);

    return 0;
}