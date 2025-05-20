//GEMINI-pro DATASET v1.0 Category: Linked list operations ; Style: optimized
#include <stdio.h>
#include <stdlib.h>

// Define the node structure
typedef struct node {
    int data;
    struct node *next;
} node;

// Create a new node
node* create_node(int data) {
    node *new_node = (node*)malloc(sizeof(node));
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
        return;
    }
    node *current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = new_node;
}

// Insert a node after a given node
void insert_after(node *prev_node, int data) {
    if (prev_node == NULL) {
        printf("Previous node cannot be NULL\n");
        return;
    }
    node *new_node = create_node(data);
    new_node->next = prev_node->next;
    prev_node->next = new_node;
}

// Delete a node from the beginning of the list
void delete_from_beginning(node **head) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    node *temp = *head;
    *head = (*head)->next;
    free(temp);
}

// Delete a node from the end of the list
void delete_from_end(node **head) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }
    node *current = *head;
    node *prev = NULL;
    while (current->next != NULL) {
        prev = current;
        current = current->next;
    }
    prev->next = NULL;
    free(current);
}

// Delete a node from the list
void delete_node(node **head, node *node_to_delete) {
    if (*head == NULL || node_to_delete == NULL) {
        printf("List or node to delete is empty\n");
        return;
    }
    if (*head == node_to_delete) {
        delete_from_beginning(head);
        return;
    }
    node *current = *head;
    node *prev = NULL;
    while (current != NULL) {
        if (current == node_to_delete) {
            prev->next = current->next;
            free(current);
            return;
        }
        prev = current;
        current = current->next;
    }
    printf("Node to delete not found in the list\n");
}

// Reverse the list
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
    // Create a linked list
    node *head = NULL;
    insert_at_beginning(&head, 1);
    insert_at_end(&head, 2);
    insert_at_end(&head, 3);
    insert_at_end(&head, 4);
    insert_after(head->next, 5);

    // Print the list
    print_list(head);

    // Reverse the list
    reverse_list(&head);

    // Print the reversed list
    print_list(head);

    // Delete a node from the beginning of the list
    delete_from_beginning(&head);

    // Print the list
    print_list(head);

    // Delete a node from the end of the list
    delete_from_end(&head);

    // Print the list
    print_list(head);

    // Delete a node from the list
    delete_node(&head, head->next->next);

    // Print the list
    print_list(head);

    // Free the list
    node *current = head;
    while (current != NULL) {
        node *next = current->next;
        free(current);
        current = next;
    }

    return 0;
}