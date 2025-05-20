//GEMINI-pro DATASET v1.0 Category: Linked list operations ; Style: automated
#include <stdio.h>
#include <stdlib.h>

// Define a node in the linked list
struct node {
    int data;
    struct node *next;
};

// Insert a new node at the beginning of the linked list
struct node* insert_at_beginning(struct node *head, int data) {
    // Create a new node
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    
    // Set the data in the new node
    new_node->data = data;

    // Make the new node point to the existing head of the list
    new_node->next = head;

    // Make the new node the new head of the list
    head = new_node;

    // Return the new head of the list
    return head;
}

// Insert a new node at the end of the linked list
struct node* insert_at_end(struct node *head, int data) {
    // Create a new node
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    
    // Set the data in the new node
    new_node->data = data;

    // Make the new node point to NULL
    new_node->next = NULL;

    // If the list is empty, make the new node the head of the list
    if (head == NULL) {
        head = new_node;
    } else {
        // Find the last node in the list
        struct node *current_node = head;
        while (current_node->next != NULL) {
            current_node = current_node->next;
        }

        // Make the last node point to the new node
        current_node->next = new_node;
    }

    // Return the head of the list
    return head;
}

// Insert a new node after a given node in the linked list
struct node* insert_after_node(struct node *head, int data, struct node *prev_node) {
    // Create a new node
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    
    // Set the data in the new node
    new_node->data = data;

    // Make the new node point to the next node after the given node
    new_node->next = prev_node->next;

    // Make the given node point to the new node
    prev_node->next = new_node;

    // Return the head of the list
    return head;
}

// Delete a node from the linked list
struct node* delete_node(struct node *head, int data) {
    // If the list is empty, return NULL
    if (head == NULL) {
        return NULL;
    }

    // If the head of the list is the node to be deleted, make the next node the new head
    if (head->data == data) {
        head = head->next;
        return head;
    }

    // Find the node to be deleted
    struct node *current_node = head;
    struct node *prev_node = NULL;
    while (current_node != NULL && current_node->data != data) {
        prev_node = current_node;
        current_node = current_node->next;
    }

    // If the node to be deleted was not found, return the original list
    if (current_node == NULL) {
        return head;
    }

    // Make the previous node point to the next node of the node to be deleted
    prev_node->next = current_node->next;

    // Free the node to be deleted
    free(current_node);

    // Return the head of the list
    return head;
}

// Print the linked list
void print_list(struct node *head) {
    // If the list is empty, print "Empty list"
    if (head == NULL) {
        printf("Empty list\n");
        return;
    }

    // Print the data in each node
    struct node *current_node = head;
    while (current_node != NULL) {
        printf("%d ", current_node->data);
        current_node = current_node->next;
    }

    printf("\n");
}

// Free the linked list
void free_list(struct node *head) {
    // If the list is empty, return
    if (head == NULL) {
        return;
    }

    // Free the first node
    struct node *current_node = head;
    head = head->next;
    free(current_node);

    // Free the rest of the list
    free_list(head);
}

// Main function
int main() {
    // Create an empty linked list
    struct node *head = NULL;

    // Insert some data into the linked list
    head = insert_at_beginning(head, 1);
    head = insert_at_end(head, 2);
    head = insert_at_end(head, 3);
    head = insert_after_node(head, 4, head->next);

    // Print the linked list
    print_list(head);

    // Delete a node from the linked list
    head = delete_node(head, 2);

    // Print the linked list
    print_list(head);

    // Free the linked list
    free_list(head);

    return 0;
}