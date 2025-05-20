//GEMINI-pro DATASET v1.0 Category: Linked list operations ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

// Donald Knuth's linked list operations

// A node in a linked list
typedef struct node {
    int data;
    struct node *next;
} node;

// Create a new node
node *create_node(int data) {
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Insert a new node at the beginning of a linked list
node *insert_at_beginning(node *head, int data) {
    node *new_node = create_node(data);
    new_node->next = head;
    return new_node;
}

// Insert a new node at the end of a linked list
node *insert_at_end(node *head, int data) {
    node *new_node = create_node(data);
    if (head == NULL) {
        return new_node;
    } else {
        node *current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
        return head;
    }
}

// Insert a new node after a given node in a linked list
node *insert_after(node *head, node *prev_node, int data) {
    if (prev_node == NULL) {
        return NULL;
    } else {
        node *new_node = create_node(data);
        new_node->next = prev_node->next;
        prev_node->next = new_node;
        return head;
    }
}

// Delete a node from a linked list
node *delete_node(node *head, node *node_to_delete) {
    if (node_to_delete == NULL) {
        return NULL;
    } else if (node_to_delete == head) {
        head = head->next;
        free(node_to_delete);
        return head;
    } else {
        node *current = head;
        while (current->next != node_to_delete) {
            current = current->next;
        }
        current->next = node_to_delete->next;
        free(node_to_delete);
        return head;
    }
}

// Print a linked list
void print_list(node *head) {
    node *current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Free a linked list
void free_list(node *head) {
    node *current = head;
    while (current != NULL) {
        node *next = current->next;
        free(current);
        current = next;
    }
}

// Main function
int main() {
    // Create a new linked list
    node *head = NULL;

    // Insert some nodes into the linked list
    head = insert_at_beginning(head, 1);
    head = insert_at_end(head, 2);
    head = insert_at_end(head, 3);
    head = insert_after(head, head->next, 4);

    // Print the linked list
    print_list(head);

    // Delete a node from the linked list
    head = delete_node(head, head->next);

    // Print the linked list
    print_list(head);

    // Free the linked list
    free_list(head);

    return 0;
}