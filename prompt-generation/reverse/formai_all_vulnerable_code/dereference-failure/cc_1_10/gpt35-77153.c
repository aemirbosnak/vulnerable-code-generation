//FormAI DATASET v1.0 Category: Linked list operations ; Style: happy
#include <stdio.h>
#include <stdlib.h>

// Node structure
typedef struct Node {
    int data;
    struct Node *next;
} Node;

// Function to add a new node at the beginning of the linked list
void insert_at_beginning(Node **head, int data) {
    Node *new_node = malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = *head;
    *head = new_node;
}

// Function to add a new node at the end of the linked list
void insert_at_end(Node **head, int data) {
    Node *new_node = malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    if (*head == NULL) {
        *head = new_node;
        return;
    }
    Node *temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new_node;
}

// Function to delete a node from the linked list
void delete_node(Node **head, int data) {
    Node *prev = NULL;
    Node *current = *head;
    while (current != NULL && current->data != data) {
        prev = current;
        current = current->next;
    }
    if (current == NULL) {
        return;
    }
    if (prev == NULL) {
        *head = current->next;
    } else {
        prev->next = current->next;
    }
    free(current);
}

// Function to print the linked list
void print_list(Node *head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    printf("Welcome to the happy linked list program! Let's create a new linked list...\n");

    Node *head = NULL;

    // Add some nodes to the beginning of the linked list
    insert_at_beginning(&head, 6);
    insert_at_beginning(&head, 4);
    insert_at_beginning(&head, 2);

    printf("The linked list after adding nodes at the beginning: ");
    print_list(head);

    // Add some nodes to the end of the linked list
    insert_at_end(&head, 8);
    insert_at_end(&head, 10);
    insert_at_end(&head, 12);

    printf("The linked list after adding nodes at the end: ");
    print_list(head);

    // Delete a node from the linked list
    delete_node(&head, 8);

    printf("The linked list after deleting node with value 8: ");
    print_list(head);

    printf("That's it for this happy linked list program! Goodbye!\n");

    return 0;
}