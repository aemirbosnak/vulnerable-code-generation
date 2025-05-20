//GEMINI-pro DATASET v1.0 Category: Educational ; Style: innovative
#include <stdio.h>
#include <stdlib.h>

// Define a custom data type for a node in a linked list.
typedef struct node {
    int data;
    struct node *next;
} Node;

// Create a new node with the given data.
Node *new_node(int data) {
    Node *node = malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Insert a new node at the beginning of the linked list.
void insert_at_beginning(Node **head, int data) {
    Node *new_head = new_node(data);
    new_head->next = *head;
    *head = new_head;
}

// Insert a new node at the end of the linked list.
void insert_at_end(Node **head, int data) {
    Node *new_tail = new_node(data);
    if (*head == NULL) {
        *head = new_tail;
    } else {
        Node *current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_tail;
    }
}

// Delete the first node in the linked list.
void delete_at_beginning(Node **head) {
    if (*head != NULL) {
        Node *next_node = (*head)->next;
        free(*head);
        *head = next_node;
    }
}

// Delete the last node in the linked list.
void delete_at_end(Node **head) {
    if (*head == NULL) {
        return;
    } else if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
    } else {
        Node *current = *head;
        while (current->next->next != NULL) {
            current = current->next;
        }
        free(current->next);
        current->next = NULL;
    }
}

// Print the linked list.
void print_list(Node *head) {
    Node *current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Free the linked list.
void free_list(Node *head) {
    Node *current = head;
    while (current != NULL) {
        Node *next_node = current->next;
        free(current);
        current = next_node;
    }
}

// Main function.
int main() {
    // Create an empty linked list.
    Node *head = NULL;

    // Insert some data into the linked list.
    insert_at_beginning(&head, 1);
    insert_at_beginning(&head, 2);
    insert_at_end(&head, 3);
    insert_at_end(&head, 4);

    // Print the linked list.
    print_list(head);

    // Delete the first node in the linked list.
    delete_at_beginning(&head);

    // Delete the last node in the linked list.
    delete_at_end(&head);

    // Print the linked list again.
    print_list(head);

    // Free the linked list.
    free_list(head);

    return 0;
}