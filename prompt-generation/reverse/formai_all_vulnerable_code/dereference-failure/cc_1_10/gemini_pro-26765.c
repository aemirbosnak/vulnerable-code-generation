//GEMINI-pro DATASET v1.0 Category: Linked list operations ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>

// Node structure
typedef struct Node {
    int data;
    struct Node *next;
} Node;

// Function to create a new node
Node *create_node(int data) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("Error creating new node.\n");
        exit(1);
    }
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Function to insert a node at the beginning of the list
void insert_at_beginning(Node **head, int data) {
    Node *new_node = create_node(data);
    new_node->next = *head;
    *head = new_node;
}

// Function to insert a node at the end of the list
void insert_at_end(Node **head, int data) {
    Node *new_node = create_node(data);
    if (*head == NULL) {
        *head = new_node;
        return;
    }
    Node *current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = new_node;
}

// Function to insert a node after a given node
void insert_after(Node *prev_node, int data) {
    if (prev_node == NULL) {
        printf("Previous node cannot be NULL.\n");
        return;
    }
    Node *new_node = create_node(data);
    new_node->next = prev_node->next;
    prev_node->next = new_node;
}

// Function to delete a node from the beginning of the list
void delete_from_beginning(Node **head) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }
    Node *temp = *head;
    *head = (*head)->next;
    free(temp);
}

// Function to delete a node from the end of the list
void delete_from_end(Node **head) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }
    Node *current = *head;
    Node *prev = NULL;
    while (current->next != NULL) {
        prev = current;
        current = current->next;
    }
    if (prev == NULL) {
        *head = NULL;
    } else {
        prev->next = NULL;
    }
    free(current);
}

// Function to delete a node from the middle of the list
void delete_from_middle(Node *node) {
    if (node == NULL) {
        printf("Node cannot be NULL.\n");
        return;
    }
    node->data = node->next->data;
    node->next = node->next->next;
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

int main() {
    // Create a linked list
    Node *head = NULL;
    insert_at_beginning(&head, 1);
    insert_at_end(&head, 2);
    insert_at_end(&head, 3);
    insert_after(head, 4);

    // Print the list
    print_list(head);

    // Delete a node from the beginning
    delete_from_beginning(&head);

    // Print the list
    print_list(head);

    // Delete a node from the end
    delete_from_end(&head);

    // Print the list
    print_list(head);

    // Delete a node from the middle
    delete_from_middle(head->next);

    // Print the list
    print_list(head);

    return 0;
}