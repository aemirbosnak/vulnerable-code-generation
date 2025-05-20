//GEMINI-pro DATASET v1.0 Category: Linked list operations ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>

// Define a node structure
typedef struct node {
    int data;
    struct node *next;
} node;

// Function to create a new node
node *create_node(int data) {
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Function to insert a node at the beginning of the linked list
void insert_at_beginning(node **head, int data) {
    node *new_node = create_node(data);
    new_node->next = *head;
    *head = new_node;
}

// Function to insert a node at the end of the linked list
void insert_at_end(node **head, int data) {
    node *new_node = create_node(data);
    if (*head == NULL) {
        *head = new_node;
    } else {
        node *current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
}

// Function to insert a node after a given node
void insert_after_node(node *prev_node, int data) {
    if (prev_node == NULL) {
        printf("Previous node cannot be NULL");
        return;
    }
    node *new_node = create_node(data);
    new_node->next = prev_node->next;
    prev_node->next = new_node;
}

// Function to delete a node from the linked list
void delete_node(node **head, int data) {
    node *current = *head;
    node *prev = NULL;
    while (current != NULL) {
        if (current->data == data) {
            if (prev == NULL) {
                *head = current->next;
            } else {
                prev->next = current->next;
            }
            free(current);
            return;
        }
        prev = current;
        current = current->next;
    }
    printf("Node with data %d not found", data);
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
    insert_at_beginning(&head, 10);
    insert_at_end(&head, 20);
    insert_after_node(head, 15);
    print_linked_list(head); // Output: 10 15 20

    // Delete a node from the linked list
    delete_node(&head, 15);
    print_linked_list(head); // Output: 10 20

    // Insert a node at the end of the linked list
    insert_at_end(&head, 30);
    print_linked_list(head); // Output: 10 20 30

    return 0;
}