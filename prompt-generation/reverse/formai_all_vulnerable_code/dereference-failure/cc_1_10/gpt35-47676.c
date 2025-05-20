//FormAI DATASET v1.0 Category: Data structures visualization ; Style: invasive
#include <stdio.h>
#include <stdlib.h>

// Define a node for a singly-linked list
typedef struct node {
    int data;
    struct node *next;
} Node;

// Initialize a new node with given data and a pointer to the next node
Node *create_node(int data, Node *next) {
    Node *new_node = malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("Error: Unable to allocate memory for new node.\n");
        exit(1);
    }
    new_node->data = data;
    new_node->next = next;
    return new_node;
}

// Insert a new node at the beginning of the linked list
void insert_at_beginning(Node **head, int data) {
    Node *new_node = create_node(data, *head);
    *head = new_node;
}

// Print out the linked list starting from the head node
void print_list(Node *head) {
    printf("Current Linked List State:\n");
    while (head != NULL) {
        printf("%d", head->data);
        head = head->next;
        if (head != NULL) {
            printf(" -> ");
        }
    }
    printf("\n\n");
}

int main() {
    // Initialize the linked list with a NULL head node
    Node *head = NULL;

    // Insert some nodes at the beginning of the linked list
    insert_at_beginning(&head, 5);
    print_list(head);
    insert_at_beginning(&head, 7);
    print_list(head);
    insert_at_beginning(&head, 2);
    print_list(head);

    return 0;
}