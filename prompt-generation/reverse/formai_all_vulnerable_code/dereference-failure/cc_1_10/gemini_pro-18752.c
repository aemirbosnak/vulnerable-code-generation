//GEMINI-pro DATASET v1.0 Category: Memory management ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

// Define a custom data structure to represent a node in a linked list
struct Node {
    int data;
    struct Node *next;
};

// Define a function to create a new node with the given data
struct Node *create_node(int data) {
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    if (new_node == NULL) {
        printf("Error: Could not allocate memory for new node.\n");
        exit(1);
    }
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Define a function to insert a new node at the beginning of the linked list
void insert_at_beginning(struct Node **head, int data) {
    struct Node *new_node = create_node(data);
    new_node->next = *head;
    *head = new_node;
}

// Define a function to insert a new node at the end of the linked list
void insert_at_end(struct Node **head, int data) {
    struct Node *new_node = create_node(data);
    if (*head == NULL) {
        *head = new_node;
        return;
    }
    struct Node *current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = new_node;
}

// Define a function to insert a new node after a given node in the linked list
void insert_after(struct Node *prev_node, int data) {
    if (prev_node == NULL) {
        printf("Error: Previous node cannot be NULL.\n");
        return;
    }
    struct Node *new_node = create_node(data);
    new_node->next = prev_node->next;
    prev_node->next = new_node;
}

// Define a function to delete a node from the linked list
void delete_node(struct Node **head, struct Node *node_to_delete) {
    if (*head == node_to_delete) {
        *head = (*head)->next;
    } else {
        struct Node *current = *head;
        while (current->next != node_to_delete) {
            current = current->next;
        }
        current->next = node_to_delete->next;
    }
    free(node_to_delete);
}

// Define a function to print the linked list
void print_linked_list(struct Node *head) {
    struct Node *current = head;
    printf("Linked list: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    // Create an empty linked list
    struct Node *head = NULL;

    // Insert some data into the linked list
    insert_at_beginning(&head, 10);
    insert_at_end(&head, 20);
    insert_after(head, 15);

    // Print the linked list
    print_linked_list(head);

    // Delete a node from the linked list
    delete_node(&head, head->next);

    // Print the linked list again
    print_linked_list(head);

    // Free the memory allocated to the linked list
    struct Node *current = head;
    while (current != NULL) {
        struct Node *next = current->next;
        free(current);
        current = next;
    }

    return 0;
}