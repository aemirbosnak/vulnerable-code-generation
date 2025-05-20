//GEMINI-pro DATASET v1.0 Category: Linked list operations ; Style: irregular
#include <stdio.h>
#include <stdlib.h>

// Define a node
typedef struct node {
    int data;
    struct node *next;
} node;

// Function to create a node
node *create_node(int data) {
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Function to insert a node at the beginning of a linked list
node *insert_at_beginning(node *head, int data) {
    node *new_node = create_node(data);
    new_node->next = head;
    return new_node;
}

// Function to insert a node at the end of a linked list
node *insert_at_end(node *head, int data) {
    node *new_node = create_node(data);
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

// Function to insert a node at a specific position in a linked list
node *insert_at_position(node *head, int data, int position) {
    node *new_node = create_node(data);
    if (position == 0) {
        return insert_at_beginning(head, data);
    }
    node *current = head;
    int current_position = 0;
    while (current != NULL && current_position < position - 1) {
        current = current->next;
        current_position++;
    }
    if (current == NULL) {
        return insert_at_end(head, data);
    }
    new_node->next = current->next;
    current->next = new_node;
    return head;
}

// Function to delete a node from the beginning of a linked list
node *delete_from_beginning(node *head) {
    if (head == NULL) {
        return NULL;
    }
    node *next_node = head->next;
    free(head);
    return next_node;
}

// Function to delete a node from the end of a linked list
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
    node *last_node = current->next;
    current->next = NULL;
    free(last_node);
    return head;
}

// Function to delete a node from a specific position in a linked list
node *delete_from_position(node *head, int position) {
    if (position == 0) {
        return delete_from_beginning(head);
    }
    node *current = head;
    int current_position = 0;
    while (current != NULL && current_position < position - 1) {
        current = current->next;
        current_position++;
    }
    if (current == NULL || current->next == NULL) {
        return delete_from_end(head);
    }
    node *next_node = current->next->next;
    free(current->next);
    current->next = next_node;
    return head;
}

// Function to print a linked list
void print_linked_list(node *head) {
    node *current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Driver code
int main() {
    node *head = NULL;
    head = insert_at_beginning(head, 1);
    head = insert_at_end(head, 2);
    head = insert_at_position(head, 3, 1);
    print_linked_list(head);
    head = delete_from_beginning(head);
    head = delete_from_end(head);
    head = delete_from_position(head, 0);
    print_linked_list(head);
    return 0;
}