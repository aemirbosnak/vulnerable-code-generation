//GEMINI-pro DATASET v1.0 Category: File handling ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

// Define a structure to represent a node in a linked list.
struct node {
    int data;
    struct node *next;
};

// Define a function to create a new node.
struct node *create_node(int data) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Define a function to insert a new node at the beginning of a linked list.
struct node *insert_at_beginning(struct node *head, int data) {
    struct node *new_node = create_node(data);
    new_node->next = head;
    return new_node;
}

// Define a function to insert a new node at the end of a linked list.
struct node *insert_at_end(struct node *head, int data) {
    struct node *new_node = create_node(data);
    if (head == NULL) {
        return new_node;
    }
    struct node *current_node = head;
    while (current_node->next != NULL) {
        current_node = current_node->next;
    }
    current_node->next = new_node;
    return head;
}

// Define a function to delete a node from the beginning of a linked list.
struct node *delete_from_beginning(struct node *head) {
    if (head == NULL) {
        return NULL;
    }
    struct node *new_head = head->next;
    free(head);
    return new_head;
}

// Define a function to delete a node from the end of a linked list.
struct node *delete_from_end(struct node *head) {
    if (head == NULL) {
        return NULL;
    }
    if (head->next == NULL) {
        free(head);
        return NULL;
    }
    struct node *current_node = head;
    struct node *previous_node = NULL;
    while (current_node->next != NULL) {
        previous_node = current_node;
        current_node = current_node->next;
    }
    previous_node->next = NULL;
    free(current_node);
    return head;
}

// Define a function to print a linked list.
void print_linked_list(struct node *head) {
    struct node *current_node = head;
    while (current_node != NULL) {
        printf("%d ", current_node->data);
        current_node = current_node->next;
    }
    printf("\n");
}

int main() {
    // Create an empty linked list.
    struct node *head = NULL;

    // Insert some data into the linked list.
    head = insert_at_beginning(head, 1);
    head = insert_at_beginning(head, 2);
    head = insert_at_beginning(head, 3);
    head = insert_at_end(head, 4);
    head = insert_at_end(head, 5);
    head = insert_at_end(head, 6);

    // Print the linked list.
    printf("Initial linked list: ");
    print_linked_list(head);

    // Delete a node from the beginning of the linked list.
    head = delete_from_beginning(head);

    // Print the linked list.
    printf("Linked list after deleting a node from the beginning: ");
    print_linked_list(head);

    // Delete a node from the end of the linked list.
    head = delete_from_end(head);

    // Print the linked list.
    printf("Linked list after deleting a node from the end: ");
    print_linked_list(head);

    return 0;
}