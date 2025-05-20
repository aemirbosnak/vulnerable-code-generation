//GEMINI-pro DATASET v1.0 Category: Linked list operations ; Style: automated
#include <stdio.h>
#include <stdlib.h>

// Node structure
typedef struct node {
    int data;
    struct node *next;
} node;

// Function to create a new node
node *create_node(int data) {
    node *new_node = (node *)malloc(sizeof(node));
    if (new_node == NULL) {
        printf("Error: malloc failed\n");
        exit(1);
    }
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Function to insert a node at the beginning of the list
void insert_at_beginning(node **head, int data) {
    node *new_node = create_node(data);
    new_node->next = *head;
    *head = new_node;
}

// Function to insert a node at the end of the list
void insert_at_end(node **head, int data) {
    node *new_node = create_node(data);
    if (*head == NULL) {
        *head = new_node;
        return;
    }
    node *last_node = *head;
    while (last_node->next != NULL) {
        last_node = last_node->next;
    }
    last_node->next = new_node;
}

// Function to insert a node after a given node
void insert_after(node *prev_node, int data) {
    if (prev_node == NULL) {
        printf("Error: prev_node is NULL\n");
        return;
    }
    node *new_node = create_node(data);
    new_node->next = prev_node->next;
    prev_node->next = new_node;
}

// Function to delete a node from the beginning of the list
void delete_from_beginning(node **head) {
    if (*head == NULL) {
        printf("Error: list is empty\n");
        return;
    }
    node *temp = *head;
    *head = (*head)->next;
    free(temp);
}

// Function to delete a node from the end of the list
void delete_from_end(node **head) {
    if (*head == NULL) {
        printf("Error: list is empty\n");
        return;
    }
    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }
    node *prev_last_node = NULL;
    node *last_node = *head;
    while (last_node->next != NULL) {
        prev_last_node = last_node;
        last_node = last_node->next;
    }
    prev_last_node->next = NULL;
    free(last_node);
}

// Function to delete a node from the middle of the list
void delete_from_middle(node *prev_node) {
    if (prev_node == NULL || prev_node->next == NULL) {
        printf("Error: prev_node or prev_node->next is NULL\n");
        return;
    }
    node *temp = prev_node->next;
    prev_node->next = temp->next;
    free(temp);
}

// Function to reverse the list
void reverse_list(node **head) {
    node *prev = NULL;
    node *current = *head;
    node *next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}

// Function to print the list
void print_list(node *head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// Driver code
int main() {
    // Create an empty list
    node *head = NULL;

    // Insert some nodes into the list
    insert_at_beginning(&head, 10);
    insert_at_end(&head, 20);
    insert_at_end(&head, 30);
    insert_at_end(&head, 40);
    insert_at_end(&head, 50);

    // Print the list
    printf("Original list: ");
    print_list(head);

    // Insert a node after the second node
    insert_after(head->next, 15);

    // Print the list
    printf("List after inserting a node after the second node: ");
    print_list(head);

    // Delete a node from the beginning of the list
    delete_from_beginning(&head);

    // Print the list
    printf("List after deleting a node from the beginning: ");
    print_list(head);

    // Delete a node from the end of the list
    delete_from_end(&head);

    // Print the list
    printf("List after deleting a node from the end: ");
    print_list(head);

    // Delete a node from the middle of the list
    delete_from_middle(head->next);

    // Print the list
    printf("List after deleting a node from the middle: ");
    print_list(head);

    // Reverse the list
    reverse_list(&head);

    // Print the list
    printf("Reversed list: ");
    print_list(head);

    // Free the list
    while (head != NULL) {
        node *temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}