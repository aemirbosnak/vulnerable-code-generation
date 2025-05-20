//GEMINI-pro DATASET v1.0 Category: Linked list operations ; Style: scalable
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
        node *current_node = *head;
        while (current_node->next != NULL) {
            current_node = current_node->next;
        }
        current_node->next = new_node;
    }
}

// Insert a node after a given node
void insert_after(node *prev_node, int data) {
    if (prev_node == NULL) {
        printf("Previous node cannot be NULL\n");
    } else {
        node *new_node = create_node(data);
        new_node->next = prev_node->next;
        prev_node->next = new_node;
    }
}

// Delete a node from the beginning of the list
void delete_from_beginning(node **head) {
    if (*head == NULL) {
        printf("List is empty\n");
    } else {
        node *temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}

// Delete a node from the end of the list
void delete_from_end(node **head) {
    if (*head == NULL) {
        printf("List is empty\n");
    } else if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
    } else {
        node *current_node = *head;
        while (current_node->next->next != NULL) {
            current_node = current_node->next;
        }
        free(current_node->next);
        current_node->next = NULL;
    }
}

// Delete a node after a given node
void delete_after(node *prev_node) {
    if (prev_node == NULL) {
        printf("Previous node cannot be NULL\n");
    } else if (prev_node->next == NULL) {
        printf("Node to be deleted does not exist\n");
    } else {
        node *temp = prev_node->next;
        prev_node->next = temp->next;
        free(temp);
    }
}

// Print the list
void print_list(node *head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// Driver code
int main() {
    node *head = NULL;

    // Insert some nodes into the list
    insert_at_beginning(&head, 1);
    insert_at_end(&head, 2);
    insert_at_end(&head, 3);
    insert_at_end(&head, 4);

    // Print the list
    print_list(head);

    // Insert a node after the second node
    insert_after(head->next, 5);

    // Print the list
    print_list(head);

    // Delete a node from the beginning of the list
    delete_from_beginning(&head);

    // Print the list
    print_list(head);

    // Delete a node from the end of the list
    delete_from_end(&head);

    // Print the list
    print_list(head);

    // Delete a node after the first node
    delete_after(head);

    // Print the list
    print_list(head);

    return 0;
}