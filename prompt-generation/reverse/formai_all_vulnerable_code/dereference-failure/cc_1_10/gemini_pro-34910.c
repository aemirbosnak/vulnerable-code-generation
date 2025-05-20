//GEMINI-pro DATASET v1.0 Category: Data structures visualization ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node of a doubly linked list
struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

// Function to create a new node
struct Node *create_node(int data) {
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->prev = NULL;
    new_node->next = NULL;
    return new_node;
}

// Function to insert a node at the beginning of a doubly linked list
void insert_at_beginning(struct Node **head, int data) {
    struct Node *new_node = create_node(data);
    if (*head == NULL) {
        *head = new_node;
        return;
    }
    new_node->next = *head;
    (*head)->prev = new_node;
    *head = new_node;
}

// Function to insert a node at the end of a doubly linked list
void insert_at_end(struct Node **head, int data) {
    struct Node *new_node = create_node(data);
    if (*head == NULL) {
        *head = new_node;
        return;
    }
    struct Node *temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new_node;
    new_node->prev = temp;
}

// Function to insert a node after a given node
void insert_after(struct Node *prev_node, int data) {
    if (prev_node == NULL) {
        printf("Previous node cannot be NULL\n");
        return;
    }
    struct Node *new_node = create_node(data);
    new_node->next = prev_node->next;
    prev_node->next = new_node;
    new_node->prev = prev_node;
    if (new_node->next != NULL) {
        new_node->next->prev = new_node;
    }
}

// Function to delete a node from a doubly linked list
void delete_node(struct Node **head, struct Node *node) {
    if (*head == NULL || node == NULL) {
        return;
    }
    if (*head == node) {
        *head = (*head)->next;
        if (*head != NULL) {
            (*head)->prev = NULL;
        }
        free(node);
        return;
    }
    if (node->next != NULL) {
        node->next->prev = node->prev;
    }
    node->prev->next = node->next;
    free(node);
}

// Function to print a doubly linked list
void print_list(struct Node *head) {
    struct Node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main function
int main() {
    struct Node *head = NULL;
    insert_at_beginning(&head, 10);
    insert_at_end(&head, 20);
    insert_after(head->next, 30);
    print_list(head);  // Output: 10 30 20
    delete_node(&head, head->next);
    print_list(head);  // Output: 10 20
    return 0;
}