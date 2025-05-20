//GEMINI-pro DATASET v1.0 Category: Linked list operations ; Style: optimized
#include <stdio.h>
#include <stdlib.h>

// Node structure
typedef struct node {
    int data;
    struct node *next;
} node;

// Function to create a new node
node* create_node(int data) {
    node *new_node = (node*)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;

    return new_node;
}

// Function to insert a node at the beginning of the linked list
void insert_at_beginning(node** head, int data) {
    node *new_node = create_node(data);
    new_node->next = *head;
    *head = new_node;
}

// Function to insert a node at the end of the linked list
void insert_at_end(node** head, int data) {
    node *new_node = create_node(data);

    if (*head == NULL) {
        *head = new_node;
    } else {
        node *current_node = *head;

        while (current_node->next != NULL) {
            current_node = current_node->next;
        }

        current_node->next = new_node;
    }
}

// Function to insert a node after a specific node
void insert_after(node** head, int data, int after_data) {
    node *new_node = create_node(data);

    node *current_node = *head;

    while (current_node != NULL && current_node->data != after_data) {
        current_node = current_node->next;
    }

    if (current_node != NULL) {
        new_node->next = current_node->next;
        current_node->next = new_node;
    }
}

// Function to delete a node at the beginning of the linked list
void delete_at_beginning(node** head) {
    if (*head == NULL) {
        return;
    }

    node *temp = *head;
    *head = (*head)->next;
    free(temp);
}

// Function to delete a node at the end of the linked list
void delete_at_end(node** head) {
    if (*head == NULL) {
        return;
    }

    node *current_node = *head;
    node *previous_node = NULL;

    while (current_node->next != NULL) {
        previous_node = current_node;
        current_node = current_node->next;
    }

    if (previous_node != NULL) {
        previous_node->next = NULL;
    } else {
        *head = NULL;
    }

    free(current_node);
}

// Function to delete a node after a specific node
void delete_after(node** head, int after_data) {
    node *current_node = *head;
    node *previous_node = NULL;

    while (current_node != NULL && current_node->data != after_data) {
        previous_node = current_node;
        current_node = current_node->next;
    }

    if (current_node != NULL && current_node->next != NULL) {
        previous_node->next = current_node->next;
        free(current_node);
    }
}

// Function to print the linked list
void print_linked_list(node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }

    printf("NULL\n");
}

// Main function
int main() {
    // Create an empty linked list
    node *head = NULL;

    // Insert some data into the linked list
    insert_at_beginning(&head, 1);
    insert_at_end(&head, 2);
    insert_at_beginning(&head, 3);
    insert_after(&head, 4, 2);

    // Print the linked list
    print_linked_list(head);

    // Delete a node at the beginning of the linked list
    delete_at_beginning(&head);

    // Print the linked list
    print_linked_list(head);

    // Delete a node at the end of the linked list
    delete_at_end(&head);

    // Print the linked list
    print_linked_list(head);

    // Delete a node after a specific node
    delete_after(&head, 2);

    // Print the linked list
    print_linked_list(head);

    return 0;
}