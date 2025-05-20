//GEMINI-pro DATASET v1.0 Category: Data structures visualization ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in a linked list
typedef struct node {
    int data;
    struct node *next;
} node;

// Function to create a new node with the given data
node *create_node(int data) {
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Function to insert a new node at the beginning of the linked list
node *insert_at_beginning(node *head, int data) {
    node *new_node = create_node(data);
    new_node->next = head;
    return new_node;
}

// Function to insert a new node at the end of the linked list
node *insert_at_end(node *head, int data) {
    node *new_node = create_node(data);
    if (head == NULL) {
        return new_node;
    }
    node *current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = new_node;
    return head;
}

// Function to insert a new node after a given node
node *insert_after_node(node *head, int data, int after_node) {
    node *new_node = create_node(data);
    if (head == NULL) {
        return new_node;
    }
    node *current = head;
    while (current->data != after_node) {
        current = current->next;
        if (current == NULL) {
            return head;
        }
    }
    new_node->next = current->next;
    current->next = new_node;
    return head;
}

// Function to delete a node from the linked list
node *delete_node(node *head, int data) {
    if (head == NULL) {
        return head;
    }
    node *current = head;
    node *previous = NULL;
    while (current->data != data) {
        previous = current;
        current = current->next;
        if (current == NULL) {
            return head;
        }
    }
    if (previous == NULL) {
        head = head->next;
    } else {
        previous->next = current->next;
    }
    free(current);
    return head;
}

// Function to print the linked list
void print_linked_list(node *head) {
    node *current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Main function
int main() {
    // Create a linked list
    node *head = NULL;
    head = insert_at_beginning(head, 1);
    head = insert_at_end(head, 2);
    head = insert_at_end(head, 3);
    head = insert_after_node(head, 4, 2);

    // Print the linked list
    printf("Original linked list:\n");
    print_linked_list(head);

    // Delete a node from the linked list
    head = delete_node(head, 2);

    // Print the linked list after deletion
    printf("Linked list after deletion:\n");
    print_linked_list(head);

    return 0;
}