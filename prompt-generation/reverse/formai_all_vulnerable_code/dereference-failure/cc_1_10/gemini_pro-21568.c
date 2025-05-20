//GEMINI-pro DATASET v1.0 Category: Data structures visualization ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define a node for a linked list
struct Node {
    int data;
    struct Node *next;
};

// Create a new node with the given data
struct Node *create_node(int data) {
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Insert a new node at the beginning of the linked list
void insert_at_beginning(struct Node **head, int data) {
    struct Node *new_node = create_node(data);
    new_node->next = *head;
    *head = new_node;
}

// Insert a new node at the end of the linked list
void insert_at_end(struct Node **head, int data) {
    struct Node *new_node = create_node(data);

    if (*head == NULL) {
        *head = new_node;
        return;
    }

    struct Node *current_node = *head;
    while (current_node->next != NULL) {
        current_node = current_node->next;
    }

    current_node->next = new_node;
}

// Insert a new node after a given node
void insert_after(struct Node *prev_node, int data) {
    if (prev_node == NULL) {
        printf("Previous node cannot be NULL");
        return;
    }

    struct Node *new_node = create_node(data);
    new_node->next = prev_node->next;
    prev_node->next = new_node;
}

// Delete a node from the linked list
void delete_node(struct Node **head, int data) {
    struct Node *current_node = *head;
    struct Node *prev_node = NULL;

    while (current_node != NULL) {
        if (current_node->data == data) {
            if (prev_node == NULL) {
                *head = current_node->next;
            } else {
                prev_node->next = current_node->next;
            }
            free(current_node);
            return;
        }

        prev_node = current_node;
        current_node = current_node->next;
    }

    printf("Node with data %d not found", data);
}

// Print the linked list
void print_linked_list(struct Node *head) {
    struct Node *current_node = head;

    while (current_node != NULL) {
        printf("%d  ", current_node->data);
        current_node = current_node->next;
    }

    printf("\n");
}

// Main function
int main() {
    // Create a linked list
    struct Node *head = NULL;

    // Insert some nodes into the linked list
    insert_at_beginning(&head, 10);
    insert_at_end(&head, 20);
    insert_after(head, 15);

    // Print the linked list
    printf("Initial linked list:\n");
    print_linked_list(head);

    // Delete a node from the linked list
    delete_node(&head, 15);

    // Print the linked list
    printf("Linked list after deleting node with data 15:\n");
    print_linked_list(head);

    return 0;
}