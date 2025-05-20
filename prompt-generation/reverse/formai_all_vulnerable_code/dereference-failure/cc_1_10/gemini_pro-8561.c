//GEMINI-pro DATASET v1.0 Category: Data structures visualization ; Style: irregular
#include <stdio.h>
#include <stdlib.h>

// Node structure
struct node {
    int data;
    struct node *next;
};

// Function to create a new node
struct node *create_node(int data) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Function to insert a node at the beginning of the linked list
void insert_at_beginning(struct node **head, int data) {
    struct node *new_node = create_node(data);
    new_node->next = *head;
    *head = new_node;
}

// Function to insert a node at the end of the linked list
void insert_at_end(struct node **head, int data) {
    struct node *new_node = create_node(data);
    if (*head == NULL) {
        *head = new_node;
        return;
    }
    struct node *last_node = *head;
    while (last_node->next != NULL) {
        last_node = last_node->next;
    }
    last_node->next = new_node;
}

// Function to insert a node after a given node
void insert_after(struct node **head, int data, int after_data) {
    struct node *new_node = create_node(data);
    struct node *current_node = *head;
    while (current_node != NULL) {
        if (current_node->data == after_data) {
            new_node->next = current_node->next;
            current_node->next = new_node;
            return;
        }
        current_node = current_node->next;
    }
}

// Function to delete a node from the linked list
void delete_node(struct node **head, int data) {
    struct node *current_node = *head;
    struct node *previous_node = NULL;
    while (current_node != NULL) {
        if (current_node->data == data) {
            if (previous_node == NULL) {
                *head = current_node->next;
            } else {
                previous_node->next = current_node->next;
            }
            free(current_node);
            return;
        }
        previous_node = current_node;
        current_node = current_node->next;
    }
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
    // Create a linked list
    struct node *head = NULL;
    insert_at_beginning(&head, 10);
    insert_at_end(&head, 20);
    insert_at_end(&head, 30);
    insert_after(&head, 15, 10);

    // Print the linked list
    printf("The linked list is: ");
    print_linked_list(head);

    // Delete a node from the linked list
    delete_node(&head, 15);

    // Print the linked list
    printf("The linked list after deleting a node is: ");
    print_linked_list(head);

    return 0;
}