//GEMINI-pro DATASET v1.0 Category: Linked list operations ; Style: standalone
#include <stdio.h>
#include <stdlib.h>

// Define the node structure
typedef struct node {
    int data;
    struct node *next;
} node;

// Function to create a new node
node *create_node(int data) {
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Function to insert a new node at the beginning of the list
void insert_at_beginning(node **head, int data) {
    node *new_node = create_node(data);
    new_node->next = *head;
    *head = new_node;
}

// Function to insert a new node at the end of the list
void insert_at_end(node **head, int data) {
    node *new_node = create_node(data);
    if (*head == NULL) {
        *head = new_node;
        return;
    }
    node *current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = new_node;
}

// Function to insert a new node after a given node
void insert_after(node *prev_node, int data) {
    if (prev_node == NULL) {
        printf("Previous node cannot be NULL\n");
        return;
    }
    node *new_node = create_node(data);
    new_node->next = prev_node->next;
    prev_node->next = new_node;
}

// Function to delete a node from the beginning of the list
void delete_at_beginning(node **head) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    node *temp = *head;
    *head = (*head)->next;
    free(temp);
}

// Function to delete a node from the end of the list
void delete_at_end(node **head) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    node *current = *head;
    node *prev = NULL;
    while (current->next != NULL) {
        prev = current;
        current = current->next;
    }
    if (prev == NULL) {
        *head = NULL;
    } else {
        prev->next = NULL;
    }
    free(current);
}

// Function to delete a node after a given node
void delete_after(node *prev_node) {
    if (prev_node == NULL) {
        printf("Previous node cannot be NULL\n");
        return;
    }
    if (prev_node->next == NULL) {
        printf("No node to delete after the given node\n");
        return;
    }
    node *temp = prev_node->next;
    prev_node->next = temp->next;
    free(temp);
}

// Function to print the list
void print_list(node *head) {
    node *current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Main function
int main() {
    // Create a new list
    node *head = NULL;

    // Insert some nodes into the list
    insert_at_beginning(&head, 10);
    insert_at_end(&head, 20);
    insert_after(head, 30);
    insert_at_end(&head, 40);

    // Print the list
    printf("The list is: ");
    print_list(head);

    // Delete a node from the beginning of the list
    delete_at_beginning(&head);

    // Print the list
    printf("The list after deletion from the beginning is: ");
    print_list(head);

    // Delete a node from the end of the list
    delete_at_end(&head);

    // Print the list
    printf("The list after deletion from the end is: ");
    print_list(head);

    // Delete a node after a given node
    delete_after(head);

    // Print the list
    printf("The list after deletion after a given node is: ");
    print_list(head);

    return 0;
}