//GEMINI-pro DATASET v1.0 Category: Linked list operations ; Style: visionary
#include <stdio.h>
#include <stdlib.h>

// Define the node structure
typedef struct node {
    int data;
    struct node *next;
} node_t;

// Function to create a new node
node_t* create_node(int data) {
    node_t *new_node = (node_t*)malloc(sizeof(node_t));
    if (new_node == NULL) {
        printf("Error: Could not allocate memory for new node.\n");
        exit(1);
    }
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Function to insert a new node at the beginning of the list
void insert_at_beginning(node_t **head, int data) {
    node_t *new_node = create_node(data);
    new_node->next = *head;
    *head = new_node;
}

// Function to insert a new node at the end of the list
void insert_at_end(node_t **head, int data) {
    node_t *new_node = create_node(data);
    if (*head == NULL) {
        *head = new_node;
    } else {
        node_t *current_node = *head;
        while (current_node->next != NULL) {
            current_node = current_node->next;
        }
        current_node->next = new_node;
    }
}

// Function to insert a new node after a given node
void insert_after(node_t *prev_node, int data) {
    if (prev_node == NULL) {
        printf("Error: Previous node cannot be NULL.\n");
        exit(1);
    }
    node_t *new_node = create_node(data);
    new_node->next = prev_node->next;
    prev_node->next = new_node;
}

// Function to delete a node from the beginning of the list
void delete_from_beginning(node_t **head) {
    if (*head == NULL) {
        printf("Error: List is empty.\n");
        exit(1);
    }
    node_t *temp = *head;
    *head = (*head)->next;
    free(temp);
}

// Function to delete a node from the end of the list
void delete_from_end(node_t **head) {
    if (*head == NULL) {
        printf("Error: List is empty.\n");
        exit(1);
    }
    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
    } else {
        node_t *current_node = *head;
        while (current_node->next->next != NULL) {
            current_node = current_node->next;
        }
        free(current_node->next);
        current_node->next = NULL;
    }
}

// Function to delete a node after a given node
void delete_after(node_t *prev_node) {
    if (prev_node == NULL) {
        printf("Error: Previous node cannot be NULL.\n");
        exit(1);
    }
    if (prev_node->next == NULL) {
        printf("Error: Node after previous node does not exist.\n");
        exit(1);
    }
    node_t *temp = prev_node->next;
    prev_node->next = temp->next;
    free(temp);
}

// Function to print the list
void print_list(node_t *head) {
    node_t *current_node = head;
    while (current_node != NULL) {
        printf("%d ", current_node->data);
        current_node = current_node->next;
    }
    printf("\n");
}

// Main function
int main() {
    // Create an empty list
    node_t *head = NULL;

    // Insert some nodes into the list
    insert_at_beginning(&head, 1);
    insert_at_end(&head, 2);
    insert_at_end(&head, 3);
    insert_after(head->next, 4);

    // Print the list
    printf("Original list: ");
    print_list(head);

    // Delete a node from the beginning of the list
    delete_from_beginning(&head);

    // Delete a node from the end of the list
    delete_from_end(&head);

    // Delete a node after a given node
    delete_after(head);

    // Print the list again
    printf("Modified list: ");
    print_list(head);

    return 0;
}