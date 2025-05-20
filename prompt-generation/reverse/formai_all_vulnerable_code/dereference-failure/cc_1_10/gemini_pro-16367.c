//GEMINI-pro DATASET v1.0 Category: Linked list operations ; Style: optimized
#include <stdio.h>
#include <stdlib.h>

// Define the node structure
typedef struct node {
    int data;
    struct node *next;
} node_t;

// Initialize the linked list
node_t *head = NULL;

// Insert a node at the beginning of the linked list
void insert_at_beginning(int data) {
    // Create a new node
    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    new_node->data = data;

    // Insert the new node at the beginning of the linked list
    new_node->next = head;
    head = new_node;
}

// Insert a node at the end of the linked list
void insert_at_end(int data) {
    // Create a new node
    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    new_node->data = data;

    // Insert the new node at the end of the linked list
    if (head == NULL) {
        head = new_node;
    } else {
        node_t *current_node = head;
        while (current_node->next != NULL) {
            current_node = current_node->next;
        }
        current_node->next = new_node;
    }
}

// Insert a node at a specific position in the linked list
void insert_at_position(int data, int position) {
    // Create a new node
    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    new_node->data = data;

    // Insert the new node at the specified position
    if (position == 0) {
        insert_at_beginning(data);
    } else {
        node_t *current_node = head;
        for (int i = 0; i < position - 1; i++) {
            current_node = current_node->next;
        }
        new_node->next = current_node->next;
        current_node->next = new_node;
    }
}

// Delete a node from the beginning of the linked list
void delete_from_beginning() {
    // Check if the linked list is empty
    if (head == NULL) {
        return;
    }

    // Delete the first node
    node_t *temp = head;
    head = head->next;
    free(temp);
}

// Delete a node from the end of the linked list
void delete_from_end() {
    // Check if the linked list is empty
    if (head == NULL) {
        return;
    }

    // Delete the last node
    if (head->next == NULL) {
        free(head);
        head = NULL;
    } else {
        node_t *current_node = head;
        while (current_node->next->next != NULL) {
            current_node = current_node->next;
        }
        free(current_node->next);
        current_node->next = NULL;
    }
}

// Delete a node from a specific position in the linked list
void delete_from_position(int position) {
    // Check if the linked list is empty
    if (head == NULL) {
        return;
    }

    // Delete the node at the specified position
    if (position == 0) {
        delete_from_beginning();
    } else {
        node_t *current_node = head;
        for (int i = 0; i < position - 1; i++) {
            current_node = current_node->next;
        }
        node_t *temp = current_node->next;
        current_node->next = temp->next;
        free(temp);
    }
}

// Print the linked list
void print_linked_list() {
    // Check if the linked list is empty
    if (head == NULL) {
        printf("The linked list is empty.\n");
        return;
    }

    // Print the data in each node
    node_t *current_node = head;
    while (current_node != NULL) {
        printf("%d ", current_node->data);
        current_node = current_node->next;
    }
    printf("\n");
}

// Main function
int main() {
    // Insert some data into the linked list
    insert_at_beginning(10);
    insert_at_end(20);
    insert_at_position(15, 1);
    insert_at_position(25, 3);

    // Print the linked list
    print_linked_list();

    // Delete some data from the linked list
    delete_from_beginning();
    delete_from_end();
    delete_from_position(1);

    // Print the linked list
    print_linked_list();

    return 0;
}