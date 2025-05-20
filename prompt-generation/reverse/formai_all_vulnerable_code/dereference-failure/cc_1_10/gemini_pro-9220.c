//GEMINI-pro DATASET v1.0 Category: Educational ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a node in the linked list
struct node {
    char data;
    struct node *next;
};

// Function to create a new node
struct node *create_node(char data) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Function to insert a node at the beginning of the linked list
void insert_at_beginning(struct node **head, char data) {
    struct node *new_node = create_node(data);
    new_node->next = *head;
    *head = new_node;
}

// Function to insert a node at the end of the linked list
void insert_at_end(struct node **head, char data) {
    struct node *new_node = create_node(data);
    if (*head == NULL) {
        *head = new_node;
        return;
    }
    struct node *temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new_node;
}

// Function to insert a node after a given node
void insert_after(struct node *prev_node, char data) {
    if (prev_node == NULL) {
        printf("Previous node cannot be null");
        return;
    }
    struct node *new_node = create_node(data);
    new_node->next = prev_node->next;
    prev_node->next = new_node;
}

// Function to delete a node from the beginning of the linked list
void delete_from_beginning(struct node **head) {
    if (*head == NULL) {
        printf("List is empty");
        return;
    }
    struct node *temp = *head;
    *head = (*head)->next;
    free(temp);
}

// Function to delete a node from the end of the linked list
void delete_from_end(struct node **head) {
    if (*head == NULL) {
        printf("List is empty");
        return;
    }
    struct node *temp = *head;
    struct node *prev = NULL;
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
void delete_after(struct node *prev_node) {
    if (prev_node == NULL) {
        printf("Previous node cannot be null");
        return;
    }
    if (prev_node->next == NULL) {
        printf("No node to delete after the given node");
        return;
    }
    struct node *temp = prev_node->next;
    prev_node->next = temp->next;
    free(temp);
}

// Function to print the linked list
void print_linked_list(struct node *head) {
    struct node *temp = head;
    while (temp != NULL) {
        printf("%c ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct node *head = NULL;

    // Inserting nodes into the linked list
    insert_at_beginning(&head, 'A');
    insert_at_end(&head, 'B');
    insert_after(head, 'C');
    insert_after(head->next, 'D');

    // Printing the linked list
    printf("Linked list before deletion: ");
    print_linked_list(head);

    // Deleting nodes from the linked list
    delete_from_beginning(&head);
    delete_from_end(&head);
    delete_after(head);

    // Printing the linked list
    printf("Linked list after deletion: ");
    print_linked_list(head);

    return 0;
}