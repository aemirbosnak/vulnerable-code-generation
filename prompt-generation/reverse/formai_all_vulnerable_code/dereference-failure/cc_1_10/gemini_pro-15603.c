//GEMINI-pro DATASET v1.0 Category: Linked list operations ; Style: modular
#include <stdio.h>
#include <stdlib.h>

// Define the node structure
typedef struct Node {
    int data;
    struct Node *next;
} Node;

// Function to create a new node
Node *create_node(int data) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Function to insert a node at the beginning of the list
Node *insert_at_beginning(Node *head, int data) {
    Node *new_node = create_node(data);
    new_node->next = head;
    head = new_node;
    return head;
}

// Function to insert a node at the end of the list
Node *insert_at_end(Node *head, int data) {
    Node *new_node = create_node(data);
    Node *current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = new_node;
    return head;
}

// Function to insert a node at a given position in the list
Node *insert_at_position(Node *head, int data, int position) {
    Node *new_node = create_node(data);
    Node *current = head;
    int i = 1;
    while (i < position && current->next != NULL) {
        current = current->next;
        i++;
    }
    if (i == position) {
        new_node->next = current->next;
        current->next = new_node;
    }
    return head;
}

// Function to delete a node from the beginning of the list
Node *delete_from_beginning(Node *head) {
    if (head == NULL) {
        return NULL;
    }
    Node *new_head = head->next;
    free(head);
    return new_head;
}

// Function to delete a node from the end of the list
Node *delete_from_end(Node *head) {
    if (head == NULL) {
        return NULL;
    }
    Node *current = head;
    Node *previous = NULL;
    while (current->next != NULL) {
        previous = current;
        current = current->next;
    }
    if (previous == NULL) {
        free(current);
        return NULL;
    }
    previous->next = NULL;
    free(current);
    return head;
}

// Function to delete a node from a given position in the list
Node *delete_from_position(Node *head, int position) {
    if (head == NULL) {
        return NULL;
    }
    Node *current = head;
    Node *previous = NULL;
    int i = 1;
    while (i < position && current->next != NULL) {
        previous = current;
        current = current->next;
        i++;
    }
    if (i == position) {
        if (previous == NULL) {
            head = head->next;
        } else {
            previous->next = current->next;
        }
        free(current);
    }
    return head;
}

// Function to print the list
void print_list(Node *head) {
    Node *current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Function to test the linked list operations
int main() {
    Node *head = NULL;
    head = insert_at_beginning(head, 10);
    head = insert_at_end(head, 20);
    head = insert_at_position(head, 30, 2);
    print_list(head);
    head = delete_from_beginning(head);
    head = delete_from_end(head);
    head = delete_from_position(head, 1);
    print_list(head);
    return 0;
}