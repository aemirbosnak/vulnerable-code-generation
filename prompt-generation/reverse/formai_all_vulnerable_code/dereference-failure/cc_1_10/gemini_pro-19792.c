//GEMINI-pro DATASET v1.0 Category: Linked list operations ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

// Define the node structure
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
        node *temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
}

// Insert a node after a given node
void insert_after_node(node *prev_node, int data) {
    if (prev_node == NULL) {
        printf("Previous node cannot be NULL");
        return;
    }
    node *new_node = create_node(data);
    new_node->next = prev_node->next;
    prev_node->next = new_node;
}

// Delete a node from the beginning of the list
void delete_from_beginning(node **head) {
    if (*head == NULL) {
        printf("List is empty");
        return;
    }
    node *temp = *head;
    *head = (*head)->next;
    free(temp);
}

// Delete a node from the end of the list
void delete_from_end(node **head) {
    if (*head == NULL) {
        printf("List is empty");
        return;
    }
    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }
    node *temp = *head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
}

// Delete a node after a given node
void delete_after_node(node *prev_node) {
    if (prev_node == NULL || prev_node->next == NULL) {
        printf("Node or next node cannot be NULL");
        return;
    }
    node *temp = prev_node->next;
    prev_node->next = temp->next;
    free(temp);
}

// Print the list
void print_list(node *head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// Reverse the list
void reverse_list(node **head) {
    node *prev = NULL;
    node *current = *head;
    node *next;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}

// Main function
int main() {
    node *head = NULL;

    // Insert some nodes into the list
    insert_at_beginning(&head, 1);
    insert_at_end(&head, 2);
    insert_at_end(&head, 3);
    insert_after_node(head->next, 4);

    // Print the list
    printf("Original list: ");
    print_list(head);

    // Reverse the list
    reverse_list(&head);

    // Print the reversed list
    printf("Reversed list: ");
    print_list(head);

    // Delete a node from the beginning of the list
    delete_from_beginning(&head);

    // Delete a node from the end of the list
    delete_from_end(&head);

    // Delete a node after a given node
    delete_after_node(head);

    // Print the updated list
    printf("Updated list: ");
    print_list(head);

    return 0;
}