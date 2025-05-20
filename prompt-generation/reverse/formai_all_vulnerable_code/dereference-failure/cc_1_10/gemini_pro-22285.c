//GEMINI-pro DATASET v1.0 Category: Educational ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum size of the array
#define MAX_SIZE 100

// Define the structure of a node
typedef struct node {
    int data;
    struct node *next;
} node;

// Define the head of the linked list
node *head = NULL;

// Function to insert a node at the beginning of the linked list
void insert_at_beginning(int data) {
    // Create a new node
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;

    // If the linked list is empty, set the head to the new node
    if (head == NULL) {
        head = new_node;
        return;
    }

    // Otherwise, insert the new node at the beginning of the linked list
    new_node->next = head;
    head = new_node;
}

// Function to insert a node at the end of the linked list
void insert_at_end(int data) {
    // Create a new node
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;

    // If the linked list is empty, set the head to the new node
    if (head == NULL) {
        head = new_node;
        return;
    }

    // Otherwise, traverse the linked list until we reach the last node
    node *current_node = head;
    while (current_node->next != NULL) {
        current_node = current_node->next;
    }

    // Insert the new node at the end of the linked list
    current_node->next = new_node;
}

// Function to insert a node at a specific position in the linked list
void insert_at_position(int data, int position) {
    // Create a new node
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;

    // If the linked list is empty, set the head to the new node
    if (head == NULL) {
        head = new_node;
        return;
    }

    // If the position is 0, insert the new node at the beginning of the linked list
    if (position == 0) {
        new_node->next = head;
        head = new_node;
        return;
    }

    // Otherwise, traverse the linked list until we reach the node before the desired position
    node *current_node = head;
    for (int i = 0; i < position - 1; i++) {
        current_node = current_node->next;
    }

    // Insert the new node at the desired position
    new_node->next = current_node->next;
    current_node->next = new_node;
}

// Function to delete a node at the beginning of the linked list
void delete_at_beginning() {
    // If the linked list is empty, return
    if (head == NULL) {
        return;
    }

    // Otherwise, set the head to the next node
    head = head->next;
}

// Function to delete a node at the end of the linked list
void delete_at_end() {
    // If the linked list is empty, return
    if (head == NULL) {
        return;
    }

    // Otherwise, traverse the linked list until we reach the last node
    node *current_node = head;
    while (current_node->next->next != NULL) {
        current_node = current_node->next;
    }

    // Delete the last node
    current_node->next = NULL;
}

// Function to delete a node at a specific position in the linked list
void delete_at_position(int position) {
    // If the linked list is empty, return
    if (head == NULL) {
        return;
    }

    // If the position is 0, delete the node at the beginning of the linked list
    if (position == 0) {
        head = head->next;
        return;
    }

    // Otherwise, traverse the linked list until we reach the node before the desired position
    node *current_node = head;
    for (int i = 0; i < position - 1; i++) {
        current_node = current_node->next;
    }

    // Delete the node at the desired position
    current_node->next = current_node->next->next;
}

// Function to print the linked list
void print_linked_list() {
    // If the linked list is empty, return
    if (head == NULL) {
        return;
    }

    // Otherwise, traverse the linked list and print the data of each node
    node *current_node = head;
    while (current_node != NULL) {
        printf("%d ", current_node->data);
        current_node = current_node->next;
    }

    printf("\n");
}

// Main function
int main() {
    // Insert some nodes into the linked list
    insert_at_beginning(1);
    insert_at_end(2);
    insert_at_position(3, 1);

    // Print the linked list
    print_linked_list();

    // Delete a node at the beginning of the linked list
    delete_at_beginning();

    // Print the linked list
    print_linked_list();

    // Delete a node at the end of the linked list
    delete_at_end();

    // Print the linked list
    print_linked_list();

    // Delete a node at a specific position in the linked list
    delete_at_position(1);

    // Print the linked list
    print_linked_list();

    return 0;
}