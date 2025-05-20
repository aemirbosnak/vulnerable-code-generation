//GEMINI-pro DATASET v1.0 Category: Linked list operations ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

// Node structure
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

// Function to insert a node at the beginning of the linked list
void insert_at_beginning(node **head, int data) {
    node *new_node = create_node(data);
    new_node->next = *head;
    *head = new_node;
}

// Function to insert a node at the end of the linked list
void insert_at_end(node **head, int data) {
    node *new_node = create_node(data);
    if (*head == NULL) {
        *head = new_node;
        return;
    }
    node *temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new_node;
}

// Function to insert a node after a given node
void insert_after(node *prev_node, int data) {
    if (prev_node == NULL) {
        printf("Previous node cannot be NULL\n");
        return;
    }
    node *new_node = create_node(data);
    new_node->next = prev_node->next;
    prev_node->next = new_node;
}

// Function to delete a node from the beginning of the linked list
void delete_from_beginning(node **head) {
    if (*head == NULL) {
        printf("Linked list is empty\n");
        return;
    }
    node *temp = *head;
    *head = (*head)->next;
    free(temp);
}

// Function to delete a node from the end of the linked list
void delete_from_end(node **head) {
    if (*head == NULL) {
        printf("Linked list is empty\n");
        return;
    }
    node *temp = *head;
    node *prev = NULL;
    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }
    if (prev == NULL) {
        *head = NULL;
    } else {
        prev->next = NULL;
    }
    free(temp);
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

// Function to reverse a linked list
void reverse_linked_list(node **head) {
    node *prev = NULL;
    node *current = *head;
    node *next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}

// Function to print the linked list
void print_linked_list(node *head) {
    printf("Linked list: ");
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// Function to test the linked list operations
void test_linked_list() {
    node *head = NULL;

    // Inserting nodes at the beginning of the linked list
    insert_at_beginning(&head, 1);
    insert_at_beginning(&head, 2);
    insert_at_beginning(&head, 3);

    // Printing the linked list
    print_linked_list(head);

    // Inserting nodes at the end of the linked list
    insert_at_end(&head, 4);
    insert_at_end(&head, 5);
    insert_at_end(&head, 6);

    // Printing the linked list
    print_linked_list(head);

    // Inserting a node after a given node
    insert_after(head->next, 7);

    // Printing the linked list
    print_linked_list(head);

    // Deleting a node from the beginning of the linked list
    delete_from_beginning(&head);

    // Printing the linked list
    print_linked_list(head);

    // Deleting a node from the end of the linked list
    delete_from_end(&head);

    // Printing the linked list
    print_linked_list(head);

    // Deleting a node after a given node
    delete_after(head->next);

    // Printing the linked list
    print_linked_list(head);

    // Reversing the linked list
    reverse_linked_list(&head);

    // Printing the linked list
    print_linked_list(head);
}

int main() {
    test_linked_list();
    return 0;
}