//GEMINI-pro DATASET v1.0 Category: Linked list operations ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

// A node in the linked list
typedef struct node {
    int data;
    struct node *next;
} node_t;

// The head of the linked list
node_t *head = NULL;

// Create a new node
node_t *create_node(int data) {
    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Insert a node at the beginning of the linked list
void insert_at_beginning(int data) {
    node_t *new_node = create_node(data);
    new_node->next = head;
    head = new_node;
}

// Insert a node at the end of the linked list
void insert_at_end(int data) {
    node_t *new_node = create_node(data);
    if (head == NULL) {
        head = new_node;
        return;
    }
    node_t *current_node = head;
    while (current_node->next != NULL) {
        current_node = current_node->next;
    }
    current_node->next = new_node;
}

// Insert a node at a specific position in the linked list
void insert_at_position(int data, int position) {
    if (position == 0) {
        insert_at_beginning(data);
        return;
    }
    node_t *new_node = create_node(data);
    node_t *current_node = head;
    int current_position = 0;
    while (current_node != NULL && current_position < position) {
        current_node = current_node->next;
        current_position++;
    }
    if (current_node == NULL) {
        printf("Invalid position\n");
        return;
    }
    new_node->next = current_node->next;
    current_node->next = new_node;
}

// Delete a node from the beginning of the linked list
void delete_from_beginning() {
    if (head == NULL) {
        printf("Linked list is empty\n");
        return;
    }
    node_t *temp = head;
    head = head->next;
    free(temp);
}

// Delete a node from the end of the linked list
void delete_from_end() {
    if (head == NULL) {
        printf("Linked list is empty\n");
        return;
    }
    node_t *current_node = head;
    node_t *previous_node = NULL;
    while (current_node->next != NULL) {
        previous_node = current_node;
        current_node = current_node->next;
    }
    if (previous_node == NULL) {
        head = NULL;
        free(current_node);
        return;
    }
    previous_node->next = NULL;
    free(current_node);
}

// Delete a node from a specific position in the linked list
void delete_from_position(int position) {
    if (position == 0) {
        delete_from_beginning();
        return;
    }
    node_t *current_node = head;
    node_t *previous_node = NULL;
    int current_position = 0;
    while (current_node != NULL && current_position < position) {
        previous_node = current_node;
        current_node = current_node->next;
        current_position++;
    }
    if (current_node == NULL) {
        printf("Invalid position\n");
        return;
    }
    if (previous_node == NULL) {
        head = head->next;
        free(current_node);
        return;
    }
    previous_node->next = current_node->next;
    free(current_node);
}

// Print the linked list
void print_linked_list() {
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
    insert_at_beginning(1);
    insert_at_end(2);
    insert_at_position(3, 1);

    // Print the linked list
    print_linked_list();

    // Delete a node from the beginning of the linked list
    delete_from_beginning();

    // Print the linked list
    print_linked_list();

    // Delete a node from the end of the linked list
    delete_from_end();

    // Print the linked list
    print_linked_list();

    // Delete a node from a specific position in the linked list
    delete_from_position(1);

    // Print the linked list
    print_linked_list();

    return 0;
}