//GEMINI-pro DATASET v1.0 Category: Data structures visualization ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a node for a linked list
typedef struct node {
    char *data;
    struct node *next;
} node;

// Create a new node
node *create_node(char *data) {
    node *new_node = malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Insert a new node at the beginning of a linked list
node *insert_at_beginning(node *head, char *data) {
    node *new_node = create_node(data);
    new_node->next = head;
    head = new_node;
    return head;
}

// Insert a new node at the end of a linked list
node *insert_at_end(node *head, char *data) {
    node *new_node = create_node(data);
    if (head == NULL) {
        head = new_node;
    } else {
        node *current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
    return head;
}

// Insert a new node after a given node
node *insert_after(node *head, node *prev_node, char *data) {
    if (prev_node == NULL) {
        return head;
    }
    node *new_node = create_node(data);
    new_node->next = prev_node->next;
    prev_node->next = new_node;
    return head;
}

// Delete a node from a linked list
node *delete_node(node *head, char *data) {
    if (head == NULL) {
        return head;
    }
    if (strcmp(head->data, data) == 0) {
        head = head->next;
        return head;
    }
    node *current = head;
    while (current->next != NULL) {
        if (strcmp(current->next->data, data) == 0) {
            current->next = current->next->next;
            return head;
        }
        current = current->next;
    }
    return head;
}

// Print a linked list
void print_linked_list(node *head) {
    node *current = head;
    while (current != NULL) {
        printf("%s ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Main function
int main() {
    // Create a linked list
    node *head = NULL;
    head = insert_at_beginning(head, "Hello");
    head = insert_at_end(head, "World");
    head = insert_after(head, head->next, "C");
    head = insert_after(head, head->next->next, "Programming");

    // Print the linked list
    print_linked_list(head);

    // Delete a node from the linked list
    head = delete_node(head, "C");

    // Print the linked list
    print_linked_list(head);

    return 0;
}