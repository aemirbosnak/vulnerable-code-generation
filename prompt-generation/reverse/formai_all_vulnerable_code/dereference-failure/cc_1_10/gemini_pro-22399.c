//GEMINI-pro DATASET v1.0 Category: Data structures visualization ; Style: scientific
#include <stdio.h>
#include <stdlib.h>

// Define the node structure
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

// Insert a new node at the beginning of the list
node *insert_at_beginning(node *head, int data) {
    node *new_node = create_node(data);
    new_node->next = head;
    head = new_node;
    return head;
}

// Insert a new node at the end of the list
node *insert_at_end(node *head, int data) {
    node *new_node = create_node(data);
    node *current_node = head;
    while (current_node->next != NULL) {
        current_node = current_node->next;
    }
    current_node->next = new_node;
    return head;
}

// Insert a new node after a given node
node *insert_after_node(node *head, int data, int after_data) {
    node *new_node = create_node(data);
    node *current_node = head;

    while (current_node != NULL && current_node->data != after_data) {
        current_node = current_node->next;
    }

    if (current_node == NULL) {
        printf("Node not found\n");
        return head;
    } else {
        new_node->next = current_node->next;
        current_node->next = new_node;
        return head;
    }
}

// Delete a node from the beginning of the list
node *delete_from_beginning(node *head) {
    if (head == NULL) {
        printf("List is empty\n");
        return head;
    } else {
        node *new_head = head->next;
        free(head);
        return new_head;
    }
}

// Delete a node from the end of the list
node *delete_from_end(node *head) {
    if (head == NULL) {
        printf("List is empty\n");
        return head;
    } else if (head->next == NULL) {
        free(head);
        return NULL;
    } else {
        node *current_node = head;
        node *previous_node = NULL;
        while (current_node->next != NULL) {
            previous_node = current_node;
            current_node = current_node->next;
        }
        previous_node->next = NULL;
        free(current_node);
        return head;
    }
}

// Delete a node after a given node
node *delete_after_node(node *head, int after_data) {
    node *current_node = head;
    node *previous_node = NULL;

    while (current_node != NULL && current_node->data != after_data) {
        previous_node = current_node;
        current_node = current_node->next;
    }

    if (current_node == NULL) {
        printf("Node not found\n");
        return head;
    } else if (current_node->next == NULL) {
        printf("Cannot delete the last node\n");
        return head;
    } else {
        previous_node->next = current_node->next;
        free(current_node);
        return head;
    }
}

// Print the list
void print_list(node *head) {
    node *current_node = head;
    while (current_node != NULL) {
        printf("%d ", current_node->data);
        current_node = current_node->next;
    }
    printf("\n");
}

// Main function
int main() {
    // Create a new head node
    node *head = NULL;

    // Insert some nodes into the list
    head = insert_at_beginning(head, 1);
    head = insert_at_end(head, 2);
    head = insert_at_end(head, 3);
    head = insert_after_node(head, 4, 2);

    // Print the list
    printf("Original list: ");
    print_list(head);

    // Delete a node from the beginning of the list
    head = delete_from_beginning(head);

    // Print the list
    printf("List after deleting from beginning: ");
    print_list(head);

    // Delete a node from the end of the list
    head = delete_from_end(head);

    // Print the list
    printf("List after deleting from end: ");
    print_list(head);

    // Delete a node after a given node
    head = delete_after_node(head, 2);

    // Print the list
    printf("List after deleting after a node: ");
    print_list(head);

    return 0;
}