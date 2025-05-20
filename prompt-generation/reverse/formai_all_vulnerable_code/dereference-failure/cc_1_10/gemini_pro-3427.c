//GEMINI-pro DATASET v1.0 Category: Linked list operations ; Style: immersive
#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node *next;
};

// Create a new node
struct Node *create_node(int data) {
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Insert a node at the beginning of the list
void insert_at_beginning(struct Node **head, int data) {
    struct Node *new_node = create_node(data);
    new_node->next = *head;
    *head = new_node;
}

// Insert a node at the end of the list
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
}

// Insert a node after a given node
void insert_after(struct Node *prev_node, int data) {
    if (prev_node == NULL) {
        printf("Previous node cannot be NULL\n");
        return;
    }
    struct Node *new_node = create_node(data);
    new_node->next = prev_node->next;
    prev_node->next = new_node;
}

// Delete a node from the beginning of the list
void delete_from_beginning(struct Node **head) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node *temp = *head;
    *head = (*head)->next;
    free(temp);
}

// Delete a node from the end of the list
void delete_from_end(struct Node **head) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node *temp = *head;
    struct Node *prev = NULL;
    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }
    if (prev == NULL) {
        *head = NULL;
    } else {
        prev->next = NULL;
    }
    free(temp);
}

// Delete a node from the middle of the list
void delete_from_middle(struct Node *node) {
    if (node == NULL || node->next == NULL) {
        printf("Node cannot be NULL or the last node\n");
        return;
    }
    struct Node *temp = node->next;
    node->data = temp->data;
    node->next = temp->next;
    free(temp);
}

// Print the list
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
    // Create a linked list
    struct Node *head = NULL;
    insert_at_beginning(&head, 1);
    insert_at_end(&head, 2);
    insert_at_end(&head, 3);
    insert_at_end(&head, 4);
    insert_at_end(&head, 5);

    // Print the list
    printf("Original list: ");
    print_list(head);

    // Insert a node at the beginning of the list
    insert_at_beginning(&head, 0);

    // Print the list
    printf("List after inserting at the beginning: ");
    print_list(head);

    // Insert a node at the end of the list
    insert_at_end(&head, 6);

    // Print the list
    printf("List after inserting at the end: ");
    print_list(head);

    // Insert a node after a given node
    insert_after(head->next, 2.5);

    // Print the list
    printf("List after inserting after a node: ");
    print_list(head);

    // Delete a node from the beginning of the list
    delete_from_beginning(&head);

    // Print the list
    printf("List after deleting from the beginning: ");
    print_list(head);

    // Delete a node from the end of the list
    delete_from_end(&head);

    // Print the list
    printf("List after deleting from the end: ");
    print_list(head);

    // Delete a node from the middle of the list
    delete_from_middle(head->next->next);

    // Print the list
    printf("List after deleting from the middle: ");
    print_list(head);

    return 0;
}