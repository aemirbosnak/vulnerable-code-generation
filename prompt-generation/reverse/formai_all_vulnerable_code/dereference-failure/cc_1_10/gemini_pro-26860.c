//GEMINI-pro DATASET v1.0 Category: Data structures visualization ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Node structure for a singly linked list
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

// Function to insert a new node at the beginning of a singly linked list
struct node *insert_at_beginning(struct node *head, int data) {
    struct node *new_node = create_node(data);
    new_node->next = head;
    return new_node;
}

// Function to insert a new node at the end of a singly linked list
struct node *insert_at_end(struct node *head, int data) {
    struct node *new_node = create_node(data);
    if (head == NULL) {
        return new_node;
    }
    struct node *current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = new_node;
    return head;
}

// Function to insert a new node after a given node in a singly linked list
struct node *insert_after_node(struct node *head, int data, int after_data) {
    struct node *new_node = create_node(data);
    if (head == NULL) {
        return new_node;
    }
    struct node *current = head;
    while (current != NULL && current->data != after_data) {
        current = current->next;
    }
    if (current == NULL) {
        printf("Node with data %d not found\n", after_data);
        return head;
    }
    new_node->next = current->next;
    current->next = new_node;
    return head;
}

// Function to delete a node from a singly linked list
struct node *delete_node(struct node *head, int data) {
    if (head == NULL) {
        return head;
    }
    if (head->data == data) {
        return head->next;
    }
    struct node *current = head;
    while (current->next != NULL && current->next->data != data) {
        current = current->next;
    }
    if (current->next == NULL) {
        printf("Node with data %d not found\n", data);
        return head;
    }
    current->next = current->next->next;
    return head;
}

// Function to print a singly linked list
void print_list(struct node *head) {
    struct node *current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    struct node *head = NULL;

    // Insert 10 random numbers into the singly linked list
    for (int i = 0; i < 10; i++) {
        head = insert_at_end(head, rand() % 100);
    }

    // Print the original singly linked list
    printf("Original list: ");
    print_list(head);

    // Insert a new node at the beginning of the singly linked list
    head = insert_at_beginning(head, 100);

    // Print the singly linked list after inserting a node at the beginning
    printf("List after inserting a node at the beginning: ");
    print_list(head);

    // Insert a new node at the end of the singly linked list
    head = insert_at_end(head, 200);

    // Print the singly linked list after inserting a node at the end
    printf("List after inserting a node at the end: ");
    print_list(head);

    // Insert a new node after a given node in the singly linked list
    head = insert_after_node(head, 150, 50);

    // Print the singly linked list after inserting a node after a given node
    printf("List after inserting a node after a given node: ");
    print_list(head);

    // Delete a node from the singly linked list
    head = delete_node(head, 50);

    // Print the singly linked list after deleting a node
    printf("List after deleting a node: ");
    print_list(head);

    return 0;
}