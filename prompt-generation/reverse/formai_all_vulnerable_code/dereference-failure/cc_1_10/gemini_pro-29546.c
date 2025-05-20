//GEMINI-pro DATASET v1.0 Category: Linked list operations ; Style: innovative
#include <stdio.h>
#include <stdlib.h>

// Define the node structure
struct node {
    int data;
    struct node *next;
};

// Create a new node
struct node *create_node(int data) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Insert a node at the beginning of the linked list
void insert_at_beginning(struct node **head, int data) {
    struct node *new_node = create_node(data);
    new_node->next = *head;
    *head = new_node;
}

// Insert a node at the end of the linked list
void insert_at_end(struct node **head, int data) {
    struct node *new_node = create_node(data);
    if (*head == NULL) {
        *head = new_node;
        return;
    }
    struct node *temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new_node;
}

// Insert a node after a given node
void insert_after(struct node *prev_node, int data) {
    if (prev_node == NULL) {
        printf("Previous node cannot be NULL\n");
        return;
    }
    struct node *new_node = create_node(data);
    new_node->next = prev_node->next;
    prev_node->next = new_node;
}

// Delete a node from the beginning of the linked list
void delete_at_beginning(struct node **head) {
    if (*head == NULL) {
        printf("Linked list is empty\n");
        return;
    }
    struct node *temp = *head;
    *head = (*head)->next;
    free(temp);
}

// Delete a node from the end of the linked list
void delete_at_end(struct node **head) {
    if (*head == NULL) {
        printf("Linked list is empty\n");
        return;
    }
    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }
    struct node *temp = *head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
}

// Delete a node from the middle of the linked list
void delete_after(struct node *prev_node) {
    if (prev_node == NULL) {
        printf("Previous node cannot be NULL\n");
        return;
    }
    if (prev_node->next == NULL) {
        printf("Cannot delete the last node\n");
        return;
    }
    struct node *temp = prev_node->next;
    prev_node->next = temp->next;
    free(temp);
}

// Reverse a linked list
void reverse_linked_list(struct node **head) {
    struct node *prev = NULL;
    struct node *current = *head;
    struct node *next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}

// Print the linked list
void print_linked_list(struct node *head) {
    struct node *temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    // Create a linked list
    struct node *head = NULL;
    insert_at_beginning(&head, 1);
    insert_at_end(&head, 2);
    insert_at_end(&head, 3);
    insert_at_end(&head, 4);
    insert_at_end(&head, 5);

    // Print the linked list
    printf("Original linked list: ");
    print_linked_list(head);

    // Insert a node after the second node
    printf("\nInserting 6 after the second node: ");
    insert_after(head->next, 6);
    print_linked_list(head);

    // Delete the first node
    printf("\nDeleting the first node: ");
    delete_at_beginning(&head);
    print_linked_list(head);

    // Delete the last node
    printf("\nDeleting the last node: ");
    delete_at_end(&head);
    print_linked_list(head);

    // Delete the third node
    printf("\nDeleting the third node: ");
    delete_after(head->next);
    print_linked_list(head);

    // Reverse the linked list
    printf("\nReversing the linked list: ");
    reverse_linked_list(&head);
    print_linked_list(head);

    return 0;
}