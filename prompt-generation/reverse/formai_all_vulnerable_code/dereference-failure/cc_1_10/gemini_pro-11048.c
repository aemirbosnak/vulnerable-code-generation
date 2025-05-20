//GEMINI-pro DATASET v1.0 Category: Data structures visualization ; Style: curious
#include <stdio.h>
#include <stdlib.h>

// Data structure to represent a node in a linked list
typedef struct node {
    int data;
    struct node *next;
} node_t;

// Function to create a new node
node_t *create_node(int data) {
    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Function to insert a new node at the beginning of a linked list
node_t *insert_at_beginning(node_t *head, int data) {
    node_t *new_node = create_node(data);
    new_node->next = head;
    return new_node;
}

// Function to insert a new node at the end of a linked list
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

// Function to delete a node from the beginning of a linked list
node_t *delete_at_beginning(node_t *head) {
    if (head == NULL) {
        return NULL;
    }
    node_t *new_head = head->next;
    free(head);
    return new_head;
}

// Function to delete a node from the end of a linked list
node_t *delete_at_end(node_t *head) {
    if (head == NULL) {
        return NULL;
    }
    if (head->next == NULL) {
        free(head);
        return NULL;
    }
    node_t *current_node = head;
    node_t *previous_node = NULL;
    while (current_node->next != NULL) {
        previous_node = current_node;
        current_node = current_node->next;
    }
    previous_node->next = NULL;
    free(current_node);
    return head;
}

// Function to print a linked list
void print_list(node_t *head) {
    node_t *current_node = head;
    while (current_node != NULL) {
        printf("%d -> ", current_node->data);
        current_node = current_node->next;
    }
    printf("NULL\n");
}

// Main function
int main() {
    // Create an empty linked list
    node_t *head = NULL;

    // Insert some data into the linked list
    head = insert_at_beginning(head, 10);
    head = insert_at_beginning(head, 20);
    head = insert_at_beginning(head, 30);
    head = insert_at_end(head, 40);
    head = insert_at_end(head, 50);

    // Print the linked list
    printf("Initial linked list: ");
    print_list(head);

    // Delete a node from the beginning of the linked list
    head = delete_at_beginning(head);

    // Print the linked list
    printf("Linked list after deleting a node from the beginning: ");
    print_list(head);

    // Delete a node from the end of the linked list
    head = delete_at_end(head);

    // Print the linked list
    printf("Linked list after deleting a node from the end: ");
    print_list(head);

    return 0;
}