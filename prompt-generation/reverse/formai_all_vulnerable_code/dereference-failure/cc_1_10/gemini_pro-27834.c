//GEMINI-pro DATASET v1.0 Category: Searching algorithm ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>

// Define the node structure
typedef struct node {
    int data;
    struct node *next;
} node;

// Function to insert a node at the beginning of the linked list
node* insert_at_beginning(node *head, int data) {
    // Create a new node
    node *new_node = (node*)malloc(sizeof(node));
    new_node->data = data;

    // Make the new node point to the head of the list
    new_node->next = head;

    // Make the new node the head of the list
    head = new_node;

    return head;
}

// Function to insert a node at the end of the linked list
node* insert_at_end(node *head, int data) {
    // Create a new node
    node *new_node = (node*)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;

    // If the linked list is empty, make the new node the head of the list
    if (head == NULL) {
        head = new_node;
        return head;
    }

    // Otherwise, find the last node in the list and make the new node point to it
    node *current_node = head;
    while (current_node->next != NULL) {
        current_node = current_node->next;
    }
    current_node->next = new_node;

    return head;
}

// Function to insert a node at a specific position in the linked list
node* insert_at_position(node *head, int data, int position) {
    // Create a new node
    node *new_node = (node*)malloc(sizeof(node));
    new_node->data = data;

    // If the position is 0, make the new node the head of the list
    if (position == 0) {
        new_node->next = head;
        head = new_node;
        return head;
    }

    // Otherwise, find the node at the position before the desired position
    node *current_node = head;
    for (int i = 0; i < position - 1; i++) {
        current_node = current_node->next;
    }

    // Make the new node point to the node at the desired position
    new_node->next = current_node->next;

    // Make the node at the position before the desired position point to the new node
    current_node->next = new_node;

    return head;
}

// Function to delete a node from the beginning of the linked list
node* delete_from_beginning(node *head) {
    // If the linked list is empty, return NULL
    if (head == NULL) {
        return NULL;
    }

    // Otherwise, make the next node the head of the list
    head = head->next;

    // Free the memory allocated to the deleted node
    free(head);

    return head;
}

// Function to delete a node from the end of the linked list
node* delete_from_end(node *head) {
    // If the linked list is empty, return NULL
    if (head == NULL) {
        return NULL;
    }

    // Otherwise, find the last node in the list
    node *current_node = head;
    while (current_node->next != NULL) {
        current_node = current_node->next;
    }

    // If the last node is the head of the list, make the list empty
    if (current_node == head) {
        head = NULL;
        return head;
    }

    // Otherwise, find the node before the last node
    node *previous_node = head;
    while (previous_node->next != current_node) {
        previous_node = previous_node->next;
    }

    // Make the node before the last node point to NULL
    previous_node->next = NULL;

    // Free the memory allocated to the deleted node
    free(current_node);

    return head;
}

// Function to delete a node from a specific position in the linked list
node* delete_from_position(node *head, int position) {
    // If the position is 0, make the next node the head of the list
    if (position == 0) {
        head = head->next;
        return head;
    }

    // Otherwise, find the node before the node at the desired position
    node *current_node = head;
    for (int i = 0; i < position - 1; i++) {
        current_node = current_node->next;
    }

    // If the node at the desired position is the last node in the list, make the node before it point to NULL
    if (current_node->next->next == NULL) {
        current_node->next = NULL;
        return head;
    }

    // Otherwise, make the node before the node at the desired position point to the node after it
    current_node->next = current_node->next->next;

    return head;
}

// Function to print the linked list
void print_linked_list(node *head) {
    // If the linked list is empty, print an empty line
    if (head == NULL) {
        printf("\n");
        return;
    }

    // Otherwise, print the data in each node
    node *current_node = head;
    while (current_node != NULL) {
        printf("%d ", current_node->data);
        current_node = current_node->next;
    }
    printf("\n");
}

// Function to search for a value in the linked list
int search_linked_list(node *head, int value) {
    // If the linked list is empty, return -1
    if (head == NULL) {
        return -1;
    }

    // Otherwise, search for the value in each node
    node *current_node = head;
    int position = 0;
    while (current_node != NULL) {
        if (current_node->data == value) {
            return position;
        }
        current_node = current_node->next;
        position++;
    }

    // If the value was not found, return -1
    return -1;
}

int main() {
    // Create a linked list
    node *head = NULL;
    head = insert_at_beginning(head, 1);
    head = insert_at_end(head, 2);
    head = insert_at_position(head, 3, 1);
    head = insert_at_end(head, 4);
    head = insert_at_beginning(head, 5);

    // Print the linked list
    printf("Linked list: ");
    print_linked_list(head);

    // Search for a value in the linked list
    int value = 3;
    int position = search_linked_list(head, value);

    // Print the position of the value
    if (position == -1) {
        printf("Value not found\n");
    } else {
        printf("Value found at position %d\n", position);
    }

    return 0;
}