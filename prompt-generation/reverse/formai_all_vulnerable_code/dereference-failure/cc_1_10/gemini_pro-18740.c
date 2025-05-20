//GEMINI-pro DATASET v1.0 Category: Linked list operations ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>

// Node structure
typedef struct node {
    int data;
    struct node *next;
} node;

// Insert a node at the beginning of the list
node *insert_at_beginning(node *head, int data) {
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = head;
    return new_node;
}

// Insert a node at the end of the list
node *insert_at_end(node *head, int data) {
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;

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

// Insert a node after a given node
node *insert_after_node(node *head, node *prev_node, int data) {
    if (prev_node == NULL) {
        return head;
    }

    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = prev_node->next;
    prev_node->next = new_node;
    return head;
}

// Delete a node from the beginning of the list
node *delete_from_beginning(node *head) {
    if (head == NULL) {
        return NULL;
    }

    node *new_head = head->next;
    free(head);
    return new_head;
}

// Delete a node from the end of the list
node *delete_from_end(node *head) {
    if (head == NULL) {
        return NULL;
    }

    if (head->next == NULL) {
        free(head);
        return NULL;
    }

    node *current = head;
    while (current->next->next != NULL) {
        current = current->next;
    }

    free(current->next);
    current->next = NULL;
    return head;
}

// Delete a node after a given node
node *delete_after_node(node *head, node *prev_node) {
    if (prev_node == NULL || prev_node->next == NULL) {
        return head;
    }

    node *node_to_delete = prev_node->next;
    prev_node->next = node_to_delete->next;
    free(node_to_delete);
    return head;
}

// Search for a node with a given value
node *search(node *head, int data) {
    node *current = head;
    while (current != NULL) {
        if (current->data == data) {
            return current;
        }
        current = current->next;
    }

    return NULL;
}

// Print the list
void print_list(node *head) {
    node *current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Main function
int main() {
    // Create an empty list
    node *head = NULL;

    // Insert some nodes into the list
    head = insert_at_beginning(head, 10);
    head = insert_at_end(head, 20);
    head = insert_at_end(head, 30);
    head = insert_after_node(head, head->next, 15);

    // Print the list
    print_list(head);

    // Delete a node from the beginning of the list
    head = delete_from_beginning(head);

    // Print the list
    print_list(head);

    // Delete a node from the end of the list
    head = delete_from_end(head);

    // Print the list
    print_list(head);

    // Delete a node after a given node
    head = delete_after_node(head, head->next);

    // Print the list
    print_list(head);

    // Search for a node with a given value
    node *found_node = search(head, 15);
    if (found_node != NULL) {
        printf("Found node with data %d\n", found_node->data);
    } else {
        printf("Node not found\n");
    }

    return 0;
}