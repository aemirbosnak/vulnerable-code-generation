//GEMINI-pro DATASET v1.0 Category: Linked list operations ; Style: happy
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node_t;

// Create a new node
node_t *create_node(int data) {
    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    if (new_node == NULL) {
        printf("Error: Couldn't allocate memory for new node.\n");
        exit(1); // Normally, it's better to return an error code instead of exiting the program,
                 // but this is a simple example.
    }
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Insert a new node at the beginning of the list
node_t *insert_at_beginning(node_t *head, int data) {
    node_t *new_node = create_node(data);
    new_node->next = head;
    return new_node;
}

// Insert a new node at the end of the list
node_t *insert_at_end(node_t *head, int data) {
    if (head == NULL) {
        return create_node(data);
    }

    node_t *current = head;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = create_node(data);
    return head;
}

// Insert a new node after a given node
node_t *insert_after(node_t *head, int data, int after) {
    node_t *new_node = create_node(data);

    if (head == NULL) {
        printf("Error: List is empty. Nothing to insert after.\n");
        free(new_node); // Free the allocated memory for the new node since it won't be used
        return NULL;
    }

    node_t *current = head;
    while (current != NULL && current->data != after) {
        current = current->next;
    }

    if (current == NULL) {
        printf("Error: Couldn't find the node to insert after.\n");
        free(new_node); // Free the allocated memory for the new node since it won't be used
        return head;
    }

    new_node->next = current->next;
    current->next = new_node;
    return head;
}

// Delete a node from the beginning of the list
node_t *delete_from_beginning(node_t *head) {
    if (head == NULL) {
        printf("Error: List is empty. Nothing to delete.\n");
        return NULL;
    }

    node_t *new_head = head->next;
    free(head);
    return new_head;
}

// Delete a node from the end of the list
node_t *delete_from_end(node_t *head) {
    if (head == NULL) {
        printf("Error: List is empty. Nothing to delete.\n");
        return NULL;
    }

    if (head->next == NULL) {
        free(head);
        return NULL;
    }

    node_t *current = head;
    node_t *previous = NULL;
    while (current->next != NULL) {
        previous = current;
        current = current->next;
    }

    previous->next = NULL;
    free(current);
    return head;
}

// Delete a node from the list by its data
node_t *delete_by_data(node_t *head, int data) {
    if (head == NULL) {
        printf("Error: List is empty. Nothing to delete.\n");
        return NULL;
    }

    if (head->data == data) {
        return delete_from_beginning(head);
    }

    node_t *current = head;
    node_t *previous = NULL;
    while (current != NULL && current->data != data) {
        previous = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Error: Couldn't find the node to delete.\n");
        return head;
    }

    previous->next = current->next;
    free(current);
    return head;
}

// Print the list
void print_list(node_t *head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    node_t *current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }

    printf("\n");
}

int main() {
    // Create an empty list
    node_t *head = NULL;

    // Insert some nodes into the list
    head = insert_at_beginning(head, 10);
    head = insert_at_end(head, 20);
    head = insert_after(head, 30, 20);

    // Print the list
    printf("List: ");
    print_list(head);

    // Delete a node from the beginning of the list
    head = delete_from_beginning(head);

    // Print the list
    printf("List after deleting from the beginning: ");
    print_list(head);

    // Delete a node from the end of the list
    head = delete_from_end(head);

    // Print the list
    printf("List after deleting from the end: ");
    print_list(head);

    // Delete a node from the list by its data
    head = delete_by_data(head, 30);

    // Print the list
    printf("List after deleting by data: ");
    print_list(head);

    // Free the remaining nodes in the list
    while (head != NULL) {
        head = delete_from_beginning(head);
    }

    return 0;
}