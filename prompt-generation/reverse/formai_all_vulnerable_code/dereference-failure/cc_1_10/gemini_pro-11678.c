//GEMINI-pro DATASET v1.0 Category: Data structures visualization ; Style: curious
#include <stdio.h>
#include <stdlib.h>

// Define a node for a linked list
typedef struct node {
    int data;
    struct node *next;
} node;

// Create a new node
node *create_node(int data) {
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Insert a node at the beginning of a linked list
void insert_at_beginning(node **head, int data) {
    node *new_node = create_node(data);
    new_node->next = *head;
    *head = new_node;
}

// Insert a node at the end of a linked list
void insert_at_end(node **head, int data) {
    node *new_node = create_node(data);
    if (*head == NULL) {
        *head = new_node;
    } else {
        node *current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
}

// Delete a node from a linked list
void delete_node(node **head, int data) {
    if (*head == NULL) {
        return;
    }
    if ((*head)->data == data) {
        *head = (*head)->next;
        return;
    }
    node *current = *head;
    while (current->next != NULL) {
        if (current->next->data == data) {
            current->next = current->next->next;
            return;
        }
        current = current->next;
    }
}

// Print a linked list
void print_list(node *head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    node *current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Find the length of a linked list
int length(node *head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

// Reverse a linked list
node *reverse_list(node *head) {
    node *prev = NULL;
    node *next = NULL;
    while (head != NULL) {
        next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }
    return prev;
}

// Main function
int main() {
    node *head = NULL;
    insert_at_beginning(&head, 10);
    insert_at_end(&head, 20);
    insert_at_end(&head, 30);
    insert_at_end(&head, 40);
    print_list(head);  // Output: 10 20 30 40

    delete_node(&head, 20);
    print_list(head);  // Output: 10 30 40

    int len = length(head);
    printf("Length of the list: %d\n", len);  // Output: 3

    head = reverse_list(head);
    print_list(head);  // Output: 40 30 10

    return 0;
}