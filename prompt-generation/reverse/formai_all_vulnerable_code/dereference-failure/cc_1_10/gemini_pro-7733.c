//GEMINI-pro DATASET v1.0 Category: Linked list operations ; Style: genius
#include <stdio.h>
#include <stdlib.h>

// A node in the linked list
typedef struct node {
    int data;
    struct node *next;
} node_t;

// The head of the linked list
node_t *head = NULL;

// Create a new node with the given data
node_t *create_node(int data) {
    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Insert a new node at the beginning of the linked list
void insert_at_beginning(int data) {
    node_t *new_node = create_node(data);
    new_node->next = head;
    head = new_node;
}

// Insert a new node at the end of the linked list
void insert_at_end(int data) {
    node_t *new_node = create_node(data);
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

// Insert a new node after a given node
void insert_after(int data, int after_data) {
    node_t *new_node = create_node(data);
    node_t *current_node = head;
    while (current_node != NULL && current_node->data != after_data) {
        current_node = current_node->next;
    }
    if (current_node == NULL) {
        printf("Node not found\n");
    } else {
        new_node->next = current_node->next;
        current_node->next = new_node;
    }
}

// Delete a node from the beginning of the linked list
void delete_at_beginning() {
    if (head == NULL) {
        printf("List is empty\n");
    } else {
        node_t *temp_node = head;
        head = head->next;
        free(temp_node);
    }
}

// Delete a node from the end of the linked list
void delete_at_end() {
    if (head == NULL) {
        printf("List is empty\n");
    } else if (head->next == NULL) {
        free(head);
        head = NULL;
    } else {
        node_t *current_node = head;
        node_t *previous_node = NULL;
        while (current_node->next != NULL) {
            previous_node = current_node;
            current_node = current_node->next;
        }
        previous_node->next = NULL;
        free(current_node);
    }
}

// Delete a node from the middle of the linked list
void delete_after(int data) {
    node_t *current_node = head;
    node_t *previous_node = NULL;
    while (current_node != NULL && current_node->data != data) {
        previous_node = current_node;
        current_node = current_node->next;
    }
    if (current_node == NULL) {
        printf("Node not found\n");
    } else if (current_node->next == NULL) {
        previous_node->next = NULL;
        free(current_node);
    } else {
        previous_node->next = current_node->next;
        free(current_node);
    }
}

// Print the linked list
void print_list() {
    node_t *current_node = head;
    while (current_node != NULL) {
        printf("%d ", current_node->data);
        current_node = current_node->next;
    }
    printf("\n");
}

// Free the linked list
void free_list() {
    node_t *current_node = head;
    while (current_node != NULL) {
        node_t *temp_node = current_node;
        current_node = current_node->next;
        free(temp_node);
    }
    head = NULL;
}

// Main function
int main() {
    // Insert some nodes into the linked list
    insert_at_beginning(1);
    insert_at_end(2);
    insert_after(3, 2);
    insert_at_beginning(4);
    insert_at_end(5);

    // Print the linked list
    printf("Linked list: ");
    print_list();

    // Delete some nodes from the linked list
    delete_at_beginning();
    delete_at_end();
    delete_after(2);

    // Print the linked list
    printf("Linked list: ");
    print_list();

    // Free the linked list
    free_list();

    return 0;
}