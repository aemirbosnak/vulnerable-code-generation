//GEMINI-pro DATASET v1.0 Category: Linked list operations ; Style: modular
#include <stdio.h>
#include <stdlib.h>

// Node structure
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

// Function to insert a node at the beginning of the list
node *insert_at_beginning(node *head, int data) {
    node *new_node = create_node(data);
    new_node->next = head;
    head = new_node;
    return head;
}

// Function to insert a node at the end of the list
node *insert_at_end(node *head, int data) {
    node *new_node = create_node(data);
    if (head == NULL) {
        head = new_node;
        return head;
    }
    node *current_node = head;
    while (current_node->next != NULL) {
        current_node = current_node->next;
    }
    current_node->next = new_node;
    return head;
}

// Function to insert a node at a specific position in the list
node *insert_at_position(node *head, int data, int position) {
    if (position == 1) {
        return insert_at_beginning(head, data);
    }
    node *new_node = create_node(data);
    node *current_node = head;
    int current_position = 1;
    while (current_node->next != NULL && current_position < position - 1) {
        current_node = current_node->next;
        current_position++;
    }
    if (current_position == position - 1) {
        new_node->next = current_node->next;
        current_node->next = new_node;
    }
    return head;
}

// Function to delete a node from the beginning of the list
node *delete_from_beginning(node *head) {
    if (head == NULL) {
        return NULL;
    }
    node *new_head = head->next;
    free(head);
    return new_head;
}

// Function to delete a node from the end of the list
node *delete_from_end(node *head) {
    if (head == NULL) {
        return NULL;
    }
    if (head->next == NULL) {
        free(head);
        return NULL;
    }
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

// Function to delete a node from a specific position in the list
node *delete_from_position(node *head, int position) {
    if (position == 1) {
        return delete_from_beginning(head);
    }
    node *current_node = head;
    node *previous_node = NULL;
    int current_position = 1;
    while (current_node->next != NULL && current_position < position) {
        previous_node = current_node;
        current_node = current_node->next;
        current_position++;
    }
    if (current_position == position) {
        previous_node->next = current_node->next;
        free(current_node);
    }
    return head;
}

// Function to print the list
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
    node *head = NULL;

    // Inserting nodes at the beginning of the list
    head = insert_at_beginning(head, 1);
    head = insert_at_beginning(head, 2);
    head = insert_at_beginning(head, 3);

    // Printing the list
    printf("List after inserting nodes at the beginning: ");
    print_list(head);

    // Inserting nodes at the end of the list
    head = insert_at_end(head, 4);
    head = insert_at_end(head, 5);
    head = insert_at_end(head, 6);

    // Printing the list
    printf("List after inserting nodes at the end: ");
    print_list(head);

    // Inserting nodes at a specific position in the list
    head = insert_at_position(head, 7, 3);
    head = insert_at_position(head, 8, 5);
    head = insert_at_position(head, 9, 7);

    // Printing the list
    printf("List after inserting nodes at specific positions: ");
    print_list(head);

    // Deleting nodes from the beginning of the list
    head = delete_from_beginning(head);
    head = delete_from_beginning(head);

    // Printing the list
    printf("List after deleting nodes from the beginning: ");
    print_list(head);

    // Deleting nodes from the end of the list
    head = delete_from_end(head);
    head = delete_from_end(head);

    // Printing the list
    printf("List after deleting nodes from the end: ");
    print_list(head);

    // Deleting nodes from a specific position in the list
    head = delete_from_position(head, 3);
    head = delete_from_position(head, 5);

    // Printing the list
    printf("List after deleting nodes from specific positions: ");
    print_list(head);

    return 0;
}