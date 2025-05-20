//GEMINI-pro DATASET v1.0 Category: Linked list operations ; Style: excited
#include <stdio.h>
#include <stdlib.h>

// Node structure
typedef struct node {
    int data;
    struct node *next;
} node;

// Insert a node at the beginning of the linked list
void insert_at_beginning(node **head, int data) {
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = *head;
    *head = new_node;
}

// Insert a node at the end of the linked list
void insert_at_end(node **head, int data) {
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;
    if (*head == NULL) {
        *head = new_node;
    } else {
        node *current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
}

// Insert a node after a given node
void insert_after_node(node **head, int data, int after_data) {
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;
    node *current = *head;
    while (current != NULL && current->data != after_data) {
        current = current->next;
    }
    if (current != NULL) {
        new_node->next = current->next;
        current->next = new_node;
    }
}

// Delete a node from the beginning of the linked list
void delete_from_beginning(node **head) {
    if (*head != NULL) {
        node *temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}

// Delete a node from the end of the linked list
void delete_from_end(node **head) {
    if (*head != NULL) {
        node *current = *head;
        node *previous = NULL;
        while (current->next != NULL) {
            previous = current;
            current = current->next;
        }
        if (previous == NULL) {
            *head = NULL;
        } else {
            previous->next = NULL;
        }
        free(current);
    }
}

// Delete a node after a given node
void delete_after_node(node **head, int after_data) {
    node *current = *head;
    node *previous = NULL;
    while (current != NULL && current->data != after_data) {
        previous = current;
        current = current->next;
    }
    if (current != NULL && current->next != NULL) {
        previous->next = current->next;
        free(current);
    }
}

// Print the linked list
void print_linked_list(node *head) {
    node *current = head;
    while (current != NULL) {
        printf("%d  ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    // Create a linked list
    node *head = NULL;

    // Insert some nodes into the linked list
    insert_at_beginning(&head, 10);
    insert_at_end(&head, 20);
    insert_at_end(&head, 30);
    insert_after_node(&head, 15, 10);

    // Print the linked list
    printf("Linked list: ");
    print_linked_list(head);

    // Delete a node from the beginning of the linked list
    delete_from_beginning(&head);

    // Print the linked list
    printf("Linked list after deleting a node from the beginning: ");
    print_linked_list(head);

    // Delete a node from the end of the linked list
    delete_from_end(&head);

    // Print the linked list
    printf("Linked list after deleting a node from the end: ");
    print_linked_list(head);

    // Delete a node after a given node
    delete_after_node(&head, 15);

    // Print the linked list
    printf("Linked list after deleting a node after a given node: ");
    print_linked_list(head);

    return 0;
}