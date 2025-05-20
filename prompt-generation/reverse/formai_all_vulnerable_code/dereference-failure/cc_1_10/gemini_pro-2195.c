//GEMINI-pro DATASET v1.0 Category: Linked list operations ; Style: safe
#include <stdio.h>
#include <stdlib.h>

// Define the linked list node
typedef struct node {
    int data;
    struct node *next;
} node_t;

// Function to create a new node
node_t *create_node(int data) {
    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    if (new_node == NULL) {
        perror("Error: malloc failed");
        exit(1);
    }
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Function to insert a node at the beginning of the linked list
void insert_at_beginning(node_t **head, int data) {
    node_t *new_node = create_node(data);
    new_node->next = *head;
    *head = new_node;
}

// Function to insert a node at the end of the linked list
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

// Function to insert a node after a given node
void insert_after(node_t **head, node_t *prev_node, int data) {
    if (prev_node == NULL) {
        printf("Error: The given previous node is NULL\n");
        return;
    }
    node_t *new_node = create_node(data);
    new_node->next = prev_node->next;
    prev_node->next = new_node;
}

// Function to delete a node from the linked list
void delete_node(node_t **head, node_t *node) {
    if (*head == node) {
        *head = node->next;
    } else {
        node_t *current_node = *head;
        while (current_node->next != node) {
            current_node = current_node->next;
        }
        current_node->next = node->next;
    }
    free(node);
}

// Function to print the linked list
void print_linked_list(node_t *head) {
    node_t *current_node = head;
    while (current_node != NULL) {
        printf("%d ", current_node->data);
        current_node = current_node->next;
    }
    printf("\n");
}

// Function to free the linked list
void free_linked_list(node_t *head) {
    node_t *current_node = head;
    while (current_node != NULL) {
        node_t *next_node = current_node->next;
        free(current_node);
        current_node = next_node;
    }
}

int main() {
    // Create an empty linked list
    node_t *head = NULL;

    // Insert some nodes into the linked list
    insert_at_beginning(&head, 10);
    insert_at_end(&head, 20);
    insert_after(head, head->next, 30);

    // Print the linked list
    printf("The linked list is: ");
    print_linked_list(head);

    // Delete the node with data 20
    delete_node(&head, head->next);

    // Print the linked list again
    printf("The linked list after deleting node with data 20 is: ");
    print_linked_list(head);

    // Free the linked list
    free_linked_list(head);

    return 0;
}