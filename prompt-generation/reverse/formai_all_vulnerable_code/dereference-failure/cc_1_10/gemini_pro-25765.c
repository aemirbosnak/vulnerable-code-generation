//GEMINI-pro DATASET v1.0 Category: Linked list operations ; Style: careful
#include <stdio.h>
#include <stdlib.h>

// Define the node structure
typedef struct node {
    int data;
    struct node *next;
} node;

// Prototype the linked list operations
void insert_at_beginning(node **head, int data);
void insert_at_end(node **head, int data);
void insert_at_position(node **head, int data, int position);
void delete_at_beginning(node **head);
void delete_at_end(node **head);
void delete_at_position(node **head, int position);
void display_list(node *head);

// Main function
int main() {
    // Initialize the head of the linked list to NULL
    node *head = NULL;

    // Insert some values into the linked list
    insert_at_beginning(&head, 1);
    insert_at_end(&head, 2);
    insert_at_position(&head, 3, 2);

    // Display the linked list
    display_list(head);

    // Delete some values from the linked list
    delete_at_beginning(&head);
    delete_at_end(&head);
    delete_at_position(&head, 2);

    // Display the linked list
    display_list(head);

    return 0;
}

// Function to insert a node at the beginning of the linked list
void insert_at_beginning(node **head, int data) {
    // Create a new node
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = data;

    // Set the next pointer of the new node to the current head
    new_node->next = *head;

    // Set the head to the new node
    *head = new_node;
}

// Function to insert a node at the end of the linked list
void insert_at_end(node **head, int data) {
    // Create a new node
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;

    // If the linked list is empty, set the head to the new node
    if (*head == NULL) {
        *head = new_node;
    } else {
        // Traverse the linked list to find the last node
        node *last_node = *head;
        while (last_node->next != NULL) {
            last_node = last_node->next;
        }

        // Set the next pointer of the last node to the new node
        last_node->next = new_node;
    }
}

// Function to insert a node at a specified position in the linked list
void insert_at_position(node **head, int data, int position) {
    // Create a new node
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = data;

    // If the position is 1, insert the new node at the beginning of the linked list
    if (position == 1) {
        new_node->next = *head;
        *head = new_node;
    } else {
        // Traverse the linked list to find the node at the specified position
        node *current_node = *head;
        int count = 1;
        while (current_node != NULL && count < position) {
            current_node = current_node->next;
            count++;
        }

        // If the specified position is valid, insert the new node after the current node
        if (current_node != NULL) {
            new_node->next = current_node->next;
            current_node->next = new_node;
        }
    }
}

// Function to delete a node from the beginning of the linked list
void delete_at_beginning(node **head) {
    // If the linked list is empty, return
    if (*head == NULL) {
        return;
    }

    // Store the head node in a temporary variable
    node *temp = *head;

    // Set the head to the next node
    *head = (*head)->next;

    // Free the memory allocated to the temporary node
    free(temp);
}

// Function to delete a node from the end of the linked list
void delete_at_end(node **head) {
    // If the linked list is empty, return
    if (*head == NULL) {
        return;
    }

    // If the linked list has only one node, set the head to NULL
    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }

    // Traverse the linked list to find the last node
    node *current_node = *head;
    while (current_node->next->next != NULL) {
        current_node = current_node->next;
    }

    // Set the next pointer of the second last node to NULL
    current_node->next = NULL;

    // Free the memory allocated to the last node
    free(current_node->next);
}

// Function to delete a node from a specified position in the linked list
void delete_at_position(node **head, int position) {
    // If the linked list is empty, return
    if (*head == NULL) {
        return;
    }

    // If the position is 1, delete the node at the beginning of the linked list
    if (position == 1) {
        delete_at_beginning(head);
    } else {
        // Traverse the linked list to find the node at the specified position
        node *current_node = *head;
        node *previous_node = NULL;
        int count = 1;
        while (current_node != NULL && count < position) {
            previous_node = current_node;
            current_node = current_node->next;
            count++;
        }

        // If the specified position is valid, delete the node
        if (current_node != NULL) {
            previous_node->next = current_node->next;
            free(current_node);
        }
    }
}

// Function to display the linked list
void display_list(node *head) {
    // Traverse the linked list and print the data of each node
    node *current_node = head;
    while (current_node != NULL) {
        printf("%d ", current_node->data);
        current_node = current_node->next;
    }

    printf("\n");
}