//GEMINI-pro DATASET v1.0 Category: Linked list operations ; Style: immersive
#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
    int data;
    struct _node *next;
} node;

// Creates a new node with the given data and returns a pointer to it.
node* create_node(int data) {
    node* new_node = malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Inserts a new node with the given data at the beginning of the list.
void insert_at_beginning(node** head, int data) {
    node* new_node = create_node(data);
    new_node->next = *head;
    *head = new_node;
}

// Inserts a new node with the given data at the end of the list.
void insert_at_end(node** head, int data) {
    node* new_node = create_node(data);
    if (*head == NULL) {
        *head = new_node;
        return;
    }
    node* current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = new_node;
}

// Inserts a new node with the given data after the given node.
void insert_after(node* prev_node, int data) {
    if (prev_node == NULL) {
        printf("Previous node cannot be null.");
        return;
    }
    node* new_node = create_node(data);
    new_node->next = prev_node->next;
    prev_node->next = new_node;
}

// Deletes the given node from the list.
void delete_node(node** head, node* del_node) {
    if (*head == NULL || del_node == NULL) {
        return;
    }
    if (*head == del_node) {
        *head = (*head)->next;
        free(del_node);
        return;
    }
    node* current = *head;
    while (current->next != del_node) {
        current = current->next;
        if (current == NULL) {
            printf("Node to be deleted not found in the list.");
            return;
        }
    }
    current->next = del_node->next;
    free(del_node);
}

// Prints the data of each node in the list.
void print_list(node* head) {
    node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Main function to test the linked list operations.
int main() {
    node* head = NULL;

    // Insert at beginning
    insert_at_beginning(&head, 10);
    insert_at_beginning(&head, 20);

    // Insert at end
    insert_at_end(&head, 30);
    insert_at_end(&head, 40);

    // Insert after
    insert_after(head->next, 25);

    // Print list
    printf("Original list: ");
    print_list(head);

    // Delete node
    delete_node(&head, head->next->next);

    // Print list
    printf("List after deletion: ");
    print_list(head);

    return 0;
}