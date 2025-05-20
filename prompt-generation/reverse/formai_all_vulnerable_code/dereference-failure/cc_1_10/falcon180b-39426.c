//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node in the linked list
struct node {
    int data;
    struct node* next;
};

// Recursive function to insert a node at the end of the list
void insert_at_end(struct node** head, int data) {
    // If the list is empty, create a new node as the head
    if (*head == NULL) {
        *head = (struct node*) malloc(sizeof(struct node));
        (*head)->data = data;
        (*head)->next = NULL;
        return;
    }

    // Otherwise, traverse the list until the end and insert the new node
    struct node* temp = *head;
    while (temp->next!= NULL) {
        temp = temp->next;
    }
    temp->next = (struct node*) malloc(sizeof(struct node));
    temp->next->data = data;
    temp->next->next = NULL;
}

// Recursive function to delete a node with a given value
void delete_node(struct node** head, int value) {
    // If the list is empty, return
    if (*head == NULL) {
        return;
    }

    // If the first node has the given value, delete it and return
    if ((*head)->data == value) {
        (*head) = (*head)->next;
        free(*head);
        return;
    }

    // Otherwise, traverse the list until the node with the given value is found
    struct node* temp = *head;
    while (temp->next!= NULL && temp->next->data!= value) {
        temp = temp->next;
    }

    // If the node with the given value is not found, return
    if (temp->next == NULL) {
        return;
    }

    // Otherwise, delete the node with the given value
    temp->next = temp->next->next;
    free(temp->next);
}

// Recursive function to print the list
void print_list(struct node* head) {
    // If the list is empty, return
    if (head == NULL) {
        return;
    }

    // Otherwise, print the current node and traverse the rest of the list
    printf("%d ", head->data);
    print_list(head->next);
}

// Main function to test the linked list operations
int main() {
    // Initialize the list with some nodes
    struct node* head = NULL;
    insert_at_end(&head, 1);
    insert_at_end(&head, 2);
    insert_at_end(&head, 3);
    insert_at_end(&head, 4);

    // Print the list
    printf("Original list:\n");
    print_list(head);

    // Delete a node with value 3
    delete_node(&head, 3);

    // Print the list after deleting a node
    printf("\nList after deleting node with value 3:\n");
    print_list(head);

    // Insert a new node with value 5 at the end of the list
    insert_at_end(&head, 5);

    // Print the list after inserting a new node
    printf("\nList after inserting a new node with value 5:\n");
    print_list(head);

    return 0;
}