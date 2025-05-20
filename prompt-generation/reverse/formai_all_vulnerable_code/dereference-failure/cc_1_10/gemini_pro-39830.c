//GEMINI-pro DATASET v1.0 Category: Performance-Critical Component ; Style: innovative
#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node in a linked list
struct node {
    int data;
    struct node *next;
};

// Define the head of the linked list
struct node *head = NULL;

// Insert a node at the beginning of the linked list
void insert_at_beginning(int data) {
    // Create a new node
    struct node *new_node = (struct node *)malloc(sizeof(struct node));

    // Set the data of the new node
    new_node->data = data;

    // Set the next pointer of the new node to the head of the linked list
    new_node->next = head;

    // Set the head of the linked list to the new node
    head = new_node;
}

// Insert a node at the end of the linked list
void insert_at_end(int data) {
    // Create a new node
    struct node *new_node = (struct node *)malloc(sizeof(struct node));

    // Set the data of the new node
    new_node->data = data;

    // Set the next pointer of the new node to NULL
    new_node->next = NULL;

    // If the linked list is empty, set the head of the linked list to the new node
    if (head == NULL) {
        head = new_node;
    } else {
        // Iterate through the linked list until we reach the last node
        struct node *current_node = head;
        while (current_node->next != NULL) {
            current_node = current_node->next;
        }

        // Set the next pointer of the last node to the new node
        current_node->next = new_node;
    }
}

// Delete a node from the linked list
void delete_node(int data) {
    // If the linked list is empty, return
    if (head == NULL) {
        return;
    }

    // If the head of the linked list is the node to be deleted, set the head of the linked list to the next node
    if (head->data == data) {
        head = head->next;
        return;
    }

    // Iterate through the linked list until we find the node to be deleted
    struct node *current_node = head;
    while (current_node->next != NULL) {
        if (current_node->next->data == data) {
            break;
        }
        current_node = current_node->next;
    }

    // If the node to be deleted was not found, return
    if (current_node->next == NULL) {
        return;
    }

    // Set the next pointer of the previous node to the next pointer of the node to be deleted
    current_node->next = current_node->next->next;
}

// Print the linked list
void print_linked_list() {
    // If the linked list is empty, return
    if (head == NULL) {
        return;
    }

    // Iterate through the linked list and print the data of each node
    struct node *current_node = head;
    while (current_node != NULL) {
        printf("%d ", current_node->data);
        current_node = current_node->next;
    }

    printf("\n");
}

int main() {
    // Insert some nodes into the linked list
    insert_at_beginning(1);
    insert_at_end(2);
    insert_at_end(3);
    insert_at_end(4);
    insert_at_end(5);

    // Print the linked list
    print_linked_list();

    // Delete a node from the linked list
    delete_node(3);

    // Print the linked list
    print_linked_list();

    return 0;
}