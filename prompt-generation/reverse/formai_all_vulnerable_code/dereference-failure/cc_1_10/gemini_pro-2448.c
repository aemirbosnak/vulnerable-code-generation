//GEMINI-pro DATASET v1.0 Category: Linked list operations ; Style: dynamic
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
node *insert_at_beginning(node *head, int data) {
    node *new_node = create_node(data);
    new_node->next = head;
    head = new_node;
    return head;
}

// Insert a node at the end of the list
node *insert_at_end(node *head, int data) {
    node *new_node = create_node(data);
    if (head == NULL) {
        head = new_node;
        return head;
    }
    node *current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = new_node;
    return head;
}

// Insert a node after a given node
node *insert_after_node(node *head, int data, int after_data) {
    node *new_node = create_node(data);
    if (head == NULL) {
        head = new_node;
        return head;
    }
    node *current = head;
    while (current != NULL && current->data != after_data) {
        current = current->next;
    }
    if (current == NULL) {
        printf("Node not found\n");
        return head;
    }
    new_node->next = current->next;
    current->next = new_node;
    return head;
}

// Delete a node from the beginning of the list
node *delete_from_beginning(node *head) {
    if (head == NULL) {
        printf("List is empty\n");
        return head;
    }
    node *temp = head;
    head = head->next;
    free(temp);
    return head;
}

// Delete a node from the end of the list
node *delete_from_end(node *head) {
    if (head == NULL) {
        printf("List is empty\n");
        return head;
    }
    if (head->next == NULL) {
        free(head);
        return NULL;
    }
    node *current = head;
    while (current->next->next != NULL) {
        current = current->next;
    }
    free(current->next);
    current->next = NULL;
    return head;
}

// Delete a node after a given node
node *delete_after_node(node *head, int after_data) {
    if (head == NULL) {
        printf("List is empty\n");
        return head;
    }
    node *current = head;
    while (current != NULL && current->data != after_data) {
        current = current->next;
    }
    if (current == NULL) {
        printf("Node not found\n");
        return head;
    }
    if (current->next == NULL) {
        printf("No node after the given node\n");
        return head;
    }
    node *temp = current->next;
    current->next = current->next->next;
    free(temp);
    return head;
}

// Print the list
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

// Main function
int main() {
    // Create an empty list
    node *head = NULL;

    // Insert some nodes into the list
    head = insert_at_beginning(head, 10);
    head = insert_at_end(head, 20);
    head = insert_after_node(head, 30, 10);

    // Print the list
    printf("List after insertion:\n");
    print_list(head);

    // Delete some nodes from the list
    head = delete_from_beginning(head);
    head = delete_from_end(head);
    head = delete_after_node(head, 20);

    // Print the list
    printf("List after deletion:\n");
    print_list(head);

    return 0;
}