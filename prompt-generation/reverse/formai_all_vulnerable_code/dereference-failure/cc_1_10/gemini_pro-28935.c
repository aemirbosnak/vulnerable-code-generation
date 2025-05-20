//GEMINI-pro DATASET v1.0 Category: Linked list operations ; Style: excited
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
    if (new_node == NULL) {
        printf("Error creating a new node.\n");
        exit(1);
    }
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Function to insert a node at the beginning of the linked list
node *insert_at_beginning(node *head, int data) {
    node *new_node = create_node(data);
    new_node->next = head;
    return new_node;
}

// Function to insert a node at the end of the linked list
node *insert_at_end(node *head, int data) {
    node *new_node = create_node(data);
    if (head == NULL) {
        return new_node;
    }
    node *temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new_node;
    return head;
}

// Function to insert a node at a specific position in the linked list
node *insert_at_position(node *head, int data, int position) {
    if (position == 0) {
        return insert_at_beginning(head, data);
    }
    node *new_node = create_node(data);
    node *temp = head;
    for (int i = 0; i < position - 1; i++) {
        if (temp == NULL) {
            printf("Invalid position.\n");
            exit(1);
        }
        temp = temp->next;
    }
    new_node->next = temp->next;
    temp->next = new_node;
    return head;
}

// Function to delete a node from the beginning of the linked list
node *delete_from_beginning(node *head) {
    if (head == NULL) {
        return NULL;
    }
    node *temp = head;
    head = head->next;
    free(temp);
    return head;
}

// Function to delete a node from the end of the linked list
node *delete_from_end(node *head) {
    if (head == NULL) {
        return NULL;
    }
    node *temp = head;
    node *prev = NULL;
    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }
    if (prev == NULL) {
        return NULL;
    }
    prev->next = NULL;
    free(temp);
    return head;
}

// Function to delete a node from a specific position in the linked list
node *delete_from_position(node *head, int position) {
    if (position == 0) {
        return delete_from_beginning(head);
    }
    node *temp = head;
    node *prev = NULL;
    for (int i = 0; i < position; i++) {
        if (temp == NULL) {
            printf("Invalid position.\n");
            exit(1);
        }
        prev = temp;
        temp = temp->next;
    }
    prev->next = temp->next;
    free(temp);
    return head;
}

// Function to print the linked list
void print_linked_list(node *head) {
    node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main function
int main() {
    // Create a linked list
    node *head = NULL;

    // Insert some nodes into the linked list
    head = insert_at_beginning(head, 1);
    head = insert_at_end(head, 2);
    head = insert_at_end(head, 3);
    head = insert_at_position(head, 4, 1);

    // Print the linked list
    printf("Linked list before deletion:\n");
    print_linked_list(head);

    // Delete a node from the beginning of the linked list
    head = delete_from_beginning(head);

    // Delete a node from the end of the linked list
    head = delete_from_end(head);

    // Delete a node from a specific position in the linked list
    head = delete_from_position(head, 1);

    // Print the linked list
    printf("Linked list after deletion:\n");
    print_linked_list(head);

    return 0;
}