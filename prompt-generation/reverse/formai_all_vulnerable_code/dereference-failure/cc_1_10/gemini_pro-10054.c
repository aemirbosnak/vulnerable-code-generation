//GEMINI-pro DATASET v1.0 Category: Linked list operations ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

// Define a node in the linked list
typedef struct node {
    int data;
    struct node *next;
} node;

// Define the head of the linked list
node *head = NULL;

// Function to insert a node at the beginning of the linked list
void insert_at_beginning(int data) {
    // Allocate memory for the new node
    node *new_node = (node *)malloc(sizeof(node));

    // Set the data of the new node
    new_node->data = data;

    // Set the next pointer of the new node to the current head
    new_node->next = head;

    // Set the head to the new node
    head = new_node;
}

// Function to insert a node at the end of the linked list
void insert_at_end(int data) {
    // Allocate memory for the new node
    node *new_node = (node *)malloc(sizeof(node));

    // Set the data of the new node
    new_node->data = data;

    // Set the next pointer of the new node to NULL
    new_node->next = NULL;

    // If the linked list is empty, set the head to the new node
    if (head == NULL) {
        head = new_node;
        return;
    }

    // Traverse the linked list until we reach the last node
    node *current_node = head;
    while (current_node->next != NULL) {
        current_node = current_node->next;
    }

    // Set the next pointer of the last node to the new node
    current_node->next = new_node;
}

// Function to insert a node at a specific position in the linked list
void insert_at_position(int data, int position) {
    // Allocate memory for the new node
    node *new_node = (node *)malloc(sizeof(node));

    // Set the data of the new node
    new_node->data = data;

    // If the position is the beginning of the linked list, insert the node at the beginning
    if (position == 0) {
        insert_at_beginning(data);
        return;
    }

    // Traverse the linked list until we reach the node before the specified position
    node *current_node = head;
    for (int i = 0; i < position - 1; i++) {
        current_node = current_node->next;
    }

    // Set the next pointer of the new node to the node after the specified position
    new_node->next = current_node->next;

    // Set the next pointer of the node before the specified position to the new node
    current_node->next = new_node;
}

// Function to delete a node at the beginning of the linked list
void delete_at_beginning() {
    // If the linked list is empty, do nothing
    if (head == NULL) {
        return;
    }

    // Store the head in a temporary variable
    node *temp = head;

    // Set the head to the next node
    head = head->next;

    // Free the memory of the deleted node
    free(temp);
}

// Function to delete a node at the end of the linked list
void delete_at_end() {
    // If the linked list is empty, do nothing
    if (head == NULL) {
        return;
    }

    // If the linked list has only one node, delete the node
    if (head->next == NULL) {
        head = NULL;
        return;
    }

    // Traverse the linked list until we reach the node before the last node
    node *current_node = head;
    while (current_node->next->next != NULL) {
        current_node = current_node->next;
    }

    // Set the next pointer of the node before the last node to NULL
    current_node->next = NULL;

    // Free the memory of the deleted node
    free(current_node->next);
}

// Function to delete a node at a specific position in the linked list
void delete_at_position(int position) {
    // If the linked list is empty, do nothing
    if (head == NULL) {
        return;
    }

    // If the position is the beginning of the linked list, delete the node at the beginning
    if (position == 0) {
        delete_at_beginning();
        return;
    }

    // If the position is the end of the linked list, delete the node at the end
    if (position == length_of_linked_list() - 1) {
        delete_at_end();
        return;
    }

    // Traverse the linked list until we reach the node before the specified position
    node *current_node = head;
    for (int i = 0; i < position - 1; i++) {
        current_node = current_node->next;
    }

    // Store the node to be deleted in a temporary variable
    node *temp = current_node->next;

    // Set the next pointer of the node before the specified position to the node after the specified position
    current_node->next = temp->next;

    // Free the memory of the deleted node
    free(temp);
}

// Function to get the length of the linked list
int length_of_linked_list() {
    // Initialize the length to 0
    int length = 0;

    // Traverse the linked list and increment the length for each node
    node *current_node = head;
    while (current_node != NULL) {
        length++;
        current_node = current_node->next;
    }

    // Return the length of the linked list
    return length;
}

// Function to print the linked list
void print_linked_list() {
    // If the linked list is empty, print an empty list
    if (head == NULL) {
        printf("[]\n");
        return;
    }

    // Traverse the linked list and print each node's data
    node *current_node = head;
    printf("[");
    while (current_node != NULL) {
        printf("%d", current_node->data);
        if (current_node->next != NULL) {
            printf(", ");
        }
        current_node = current_node->next;
    }
    printf("]\n");
}

// Main function
int main() {
    // Insert some nodes into the linked list
    insert_at_beginning(1);
    insert_at_end(2);
    insert_at_position(3, 1);
    insert_at_position(4, 3);

    // Print the linked list
    printf("Linked list: ");
    print_linked_list();

    // Delete some nodes from the linked list
    delete_at_beginning();
    delete_at_end();
    delete_at_position(1);

    // Print the linked list
    printf("Linked list after deletions: ");
    print_linked_list();

    // Get the length of the linked list
    int length = length_of_linked_list();
    printf("Length of the linked list: %d\n", length);

    return 0;
}