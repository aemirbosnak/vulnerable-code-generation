//GEMINI-pro DATASET v1.0 Category: Data structures visualization ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

// Creating a custom data structure to represent a node in a linked list
typedef struct node {
    int data;
    struct node *next;
} Node;

// Visualizing the linked list
void visualize_list(Node *head) {
    if (head == NULL) {
        printf("Empty list.\n");
        return;
    }

    Node *current = head;
    printf("Head -> ");
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// Inserting a node at the beginning of the linked list
Node *insert_at_beginning(Node *head, int data) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = head;
    head = new_node;
    return head;
}

// Inserting a node at the end of the linked list
Node *insert_at_end(Node *head, int data) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    if (head == NULL) {
        head = new_node;
        return head;
    }
    Node *current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = new_node;
    return head;
}

// Deleting a node from the linked list
Node *delete_node(Node *head, int data) {
    if (head == NULL) {
        printf("Nothing to delete.\n");
        return head;
    }
    Node *current = head;
    Node *previous = NULL;
    while (current != NULL && current->data != data) {
        previous = current;
        current = current->next;
    }
    if (current == NULL) {
        printf("Node with data %d not found.\n", data);
        return head;
    }
    if (previous == NULL) {
        head = head->next;
    } else {
        previous->next = current->next;
    }
    free(current);
    printf("Node with data %d deleted.\n", data);
    return head;
}

// Creating a sample linked list
Node *create_list() {
    Node *head = NULL;
    head = insert_at_beginning(head, 10);
    head = insert_at_end(head, 20);
    head = insert_at_end(head, 30);
    return head;
}

// Main function
int main() {
    Node *head = create_list();
    printf("Initial linked list:\n");
    visualize_list(head);
    head = insert_at_beginning(head, 5);
    printf("\nLinked list after inserting at the beginning:\n");
    visualize_list(head);
    head = insert_at_end(head, 40);
    printf("\nLinked list after inserting at the end:\n");
    visualize_list(head);
    head = delete_node(head, 20);
    printf("\nLinked list after deleting node with value 20:\n");
    visualize_list(head);
    return 0;
}