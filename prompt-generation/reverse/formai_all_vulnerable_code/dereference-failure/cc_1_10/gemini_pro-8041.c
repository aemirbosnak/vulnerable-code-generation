//GEMINI-pro DATASET v1.0 Category: Linked list operations ; Style: futuristic
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
    return new_node;
}

// Insert a node at the end of the list
node *insert_at_end(node *head, int data) {
    node *new_node = create_node(data);
    if (head == NULL) {
        return new_node;
    }
    node *current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = new_node;
    return head;
}

// Insert a node at a specific position in the list
node *insert_at_position(node *head, int data, int position) {
    if (position == 0) {
        return insert_at_beginning(head, data);
    }
    node *new_node = create_node(data);
    node *current = head;
    for (int i = 0; i < position - 1; i++) {
        if (current == NULL) {
            return head;
        }
        current = current->next;
    }
    new_node->next = current->next;
    current->next = new_node;
    return head;
}

// Delete a node from the beginning of the list
node *delete_from_beginning(node *head) {
    if (head == NULL) {
        return NULL;
    }
    node *new_head = head->next;
    free(head);
    return new_head;
}

// Delete a node from the end of the list
node *delete_from_end(node *head) {
    if (head == NULL) {
        return NULL;
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

// Delete a node from a specific position in the list
node *delete_from_position(node *head, int position) {
    if (position == 0) {
        return delete_from_beginning(head);
    }
    node *current = head;
    for (int i = 0; i < position - 1; i++) {
        if (current == NULL) {
            return head;
        }
        current = current->next;
    }
    node *temp = current->next;
    current->next = temp->next;
    free(temp);
    return head;
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
    // Create an empty list
    node *head = NULL;

    // Insert some nodes into the list
    head = insert_at_beginning(head, 1);
    head = insert_at_end(head, 2);
    head = insert_at_position(head, 3, 1);

    // Print the list
    printf("Original list: ");
    print_list(head);

    // Delete a node from the beginning of the list
    head = delete_from_beginning(head);

    // Delete a node from the end of the list
    head = delete_from_end(head);

    // Delete a node from a specific position in the list
    head = delete_from_position(head, 1);

    // Print the list
    printf("Modified list: ");
    print_list(head);

    return 0;
}