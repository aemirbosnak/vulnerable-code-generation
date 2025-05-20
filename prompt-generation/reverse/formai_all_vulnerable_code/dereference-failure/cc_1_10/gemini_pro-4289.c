//GEMINI-pro DATASET v1.0 Category: Data structures visualization ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node;

// Create a new node
node *create_node(int data) {
    node *new_node = malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Insert a node at the beginning of the list
void insert_at_beginning(node **head, int data) {
    node *new_node = create_node(data);
    new_node->next = *head;
    *head = new_node;
}

// Insert a node at the end of the list
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

// Insert a node after a given node
void insert_after(node *prev_node, int data) {
    if (prev_node == NULL) {
        printf("Previous node cannot be NULL");
        return;
    }
    node *new_node = create_node(data);
    new_node->next = prev_node->next;
    prev_node->next = new_node;
}

// Delete a node from the beginning of the list
void delete_at_beginning(node **head) {
    if (*head == NULL) {
        printf("List is empty");
        return;
    }
    node *temp = *head;
    *head = (*head)->next;
    free(temp);
}

// Delete a node from the end of the list
void delete_at_end(node **head) {
    if (*head == NULL) {
        printf("List is empty");
        return;
    }
    node *current = *head;
    node *prev = NULL;
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

// Delete a node from the list
void delete_node(node **head, int data) {
    if (*head == NULL) {
        printf("List is empty");
        return;
    }
    node *current = *head;
    node *prev = NULL;
    while (current->data != data) {
        prev = current;
        current = current->next;
    }
    if (current == NULL) {
        printf("Node not found");
        return;
    }
    if (prev == NULL) {
        *head = (*head)->next;
    } else {
        prev->next = current->next;
    }
    free(current);
}

// Print the list
void print_list(node *head) {
    node *current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Main function
int main() {
    node *head = NULL;
    insert_at_beginning(&head, 10);
    insert_at_beginning(&head, 20);
    insert_at_beginning(&head, 30);
    insert_at_end(&head, 40);
    insert_at_end(&head, 50);
    insert_after(head->next, 25);
    printf("Original list: ");
    print_list(head);
    delete_at_beginning(&head);
    printf("After deleting from the beginning: ");
    print_list(head);
    delete_at_end(&head);
    printf("After deleting from the end: ");
    print_list(head);
    delete_node(&head, 25);
    printf("After deleting a node: ");
    print_list(head);
    return 0;
}