//GEMINI-pro DATASET v1.0 Category: Linked list operations ; Style: immersive
#include <stdio.h>
#include <stdlib.h>

// Node structure
typedef struct node {
    int data;
    struct node *next;
} node;

// Insert a node at the beginning of the linked list
void insert_at_beginning(node **head, int data) {
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = *head;
    *head = new_node;
}

// Insert a node at the end of the linked list
void insert_at_end(node **head, int data) {
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;

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
        printf("Previous node cannot be null\n");
        return;
    }

    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = prev_node->next;
    prev_node->next = new_node;
}

// Delete a node from the beginning of the linked list
void delete_from_beginning(node **head) {
    if (*head == NULL) {
        printf("Linked list is empty\n");
        return;
    }

    node *temp = *head;
    *head = (*head)->next;
    free(temp);
}

// Delete a node from the end of the linked list
void delete_from_end(node **head) {
    if (*head == NULL) {
        printf("Linked list is empty\n");
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

// Delete a node from the middle of the linked list
void delete_from_middle(node *node_to_delete) {
    if (node_to_delete == NULL) {
        printf("Node to delete cannot be null\n");
        return;
    }

    node *temp = node_to_delete->next;
    node_to_delete->data = temp->data;
    node_to_delete->next = temp->next;
    free(temp);
}

// Search for a node in the linked list
node *search(node *head, int data) {
    node *current = head;

    while (current != NULL) {
        if (current->data == data) {
            return current;
        }
        current = current->next;
    }

    return NULL;
}

// Print the linked list
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
    // Create an empty linked list
    node *head = NULL;

    // Insert some nodes into the linked list
    insert_at_beginning(&head, 10);
    insert_at_end(&head, 20);
    insert_after(head, 15);
    insert_at_end(&head, 25);

    // Print the linked list
    printf("Linked list before deletions:\n");
    print_list(head);

    // Delete a node from the beginning of the linked list
    delete_from_beginning(&head);

    // Delete a node from the end of the linked list
    delete_from_end(&head);

    // Delete a node from the middle of the linked list
    node *node_to_delete = search(head, 15);
    if (node_to_delete != NULL) {
        delete_from_middle(node_to_delete);
    }

    // Print the linked list
    printf("Linked list after deletions:\n");
    print_list(head);

    return 0;
}