//GEMINI-pro DATASET v1.0 Category: Educational ; Style: careful
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a linked list node
struct node {
    int data;
    struct node *next;
};

// Function to create a new node with the given data
struct node *create_node(int data) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    if (new_node == NULL) {
        printf("Error: Could not allocate memory for new node.\n");
        exit(1);
    }
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Function to insert a new node at the beginning of the linked list
void insert_at_beginning(struct node **head, int data) {
    struct node *new_node = create_node(data);
    new_node->next = *head;
    *head = new_node;
}

// Function to insert a new node at the end of the linked list
void insert_at_end(struct node **head, int data) {
    struct node *new_node = create_node(data);
    if (*head == NULL) {
        *head = new_node;
        return;
    }
    struct node *current_node = *head;
    while (current_node->next != NULL) {
        current_node = current_node->next;
    }
    current_node->next = new_node;
}

// Function to insert a new node after a given node
void insert_after(struct node *prev_node, int data) {
    if (prev_node == NULL) {
        printf("Error: The given node cannot be NULL.\n");
        return;
    }
    struct node *new_node = create_node(data);
    new_node->next = prev_node->next;
    prev_node->next = new_node;
}

// Function to delete a node from the linked list
void delete_node(struct node **head, struct node *node_to_delete) {
    if (*head == NULL || node_to_delete == NULL) {
        return;
    }
    if (*head == node_to_delete) {
        *head = node_to_delete->next;
    } else {
        struct node *current_node = *head;
        while (current_node->next != node_to_delete) {
            current_node = current_node->next;
        }
        current_node->next = node_to_delete->next;
    }
    free(node_to_delete);
}

// Function to print the linked list
void print_linked_list(struct node *head) {
    struct node *current_node = head;
    while (current_node != NULL) {
        printf("%d ", current_node->data);
        current_node = current_node->next;
    }
    printf("\n");
}

// Main function
int main() {
    // Create an empty linked list
    struct node *head = NULL;

    // Insert some nodes into the linked list
    insert_at_beginning(&head, 10);
    insert_at_end(&head, 20);
    insert_after(head->next, 30);

    // Print the linked list
    printf("The linked list is: ");
    print_linked_list(head);

    // Delete a node from the linked list
    delete_node(&head, head->next);

    // Print the linked list again
    printf("The linked list after deleting a node is: ");
    print_linked_list(head);

    return 0;
}