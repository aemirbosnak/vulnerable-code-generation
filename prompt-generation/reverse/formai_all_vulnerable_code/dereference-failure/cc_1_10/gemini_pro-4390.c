//GEMINI-pro DATASET v1.0 Category: Linked list operations ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

// Node structure
struct node {
    int data;
    struct node *next;
};

// Insert a node at the beginning of the list
struct node *insert_at_beginning(struct node *head, int data) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = head;
    head = new_node;
    return head;
}

// Insert a node at the end of the list
struct node *insert_at_end(struct node *head, int data) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;

    if (head == NULL) {
        head = new_node;
    } else {
        struct node *current_node = head;
        while (current_node->next != NULL) {
            current_node = current_node->next;
        }
        current_node->next = new_node;
    }

    return head;
}

// Insert a node after a given node
struct node *insert_after_node(struct node *head, struct node *prev_node, int data) {
    if (prev_node == NULL) {
        printf("Previous node cannot be NULL\n");
        return head;
    }

    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = prev_node->next;
    prev_node->next = new_node;

    return head;
}

// Delete a node from the beginning of the list
struct node *delete_from_beginning(struct node *head) {
    if (head == NULL) {
        printf("List is empty\n");
        return head;
    }

    struct node *new_head = head->next;
    free(head);
    return new_head;
}

// Delete a node from the end of the list
struct node *delete_from_end(struct node *head) {
    if (head == NULL) {
        printf("List is empty\n");
        return head;
    }

    struct node *current_node = head;
    struct node *prev_node = NULL;

    while (current_node->next != NULL) {
        prev_node = current_node;
        current_node = current_node->next;
    }

    if (prev_node == NULL) {
        head = NULL;
    } else {
        prev_node->next = NULL;
    }

    free(current_node);
    return head;
}

// Delete a node after a given node
struct node *delete_after_node(struct node *head, struct node *prev_node) {
    if (prev_node == NULL) {
        printf("Previous node cannot be NULL\n");
        return head;
    }

    if (prev_node->next == NULL) {
        printf("Cannot delete after the last node\n");
        return head;
    }

    struct node *node_to_delete = prev_node->next;
    prev_node->next = node_to_delete->next;
    free(node_to_delete);

    return head;
}

// Search for a node in the list
struct node *search_node(struct node *head, int data) {
    struct node *current_node = head;

    while (current_node != NULL) {
        if (current_node->data == data) {
            return current_node;
        }
        current_node = current_node->next;
    }

    return NULL;
}

// Print the list
void print_list(struct node *head) {
    struct node *current_node = head;

    while (current_node != NULL) {
        printf("%d ", current_node->data);
        current_node = current_node->next;
    }

    printf("\n");
}

// Main function
int main() {
    // Create an empty list
    struct node *head = NULL;

    // Insert some nodes into the list
    head = insert_at_beginning(head, 1);
    head = insert_at_end(head, 2);
    head = insert_at_end(head, 3);
    head = insert_after_node(head, head, 4);

    // Print the list
    printf("Initial list: ");
    print_list(head);

    // Delete a node from the beginning of the list
    head = delete_from_beginning(head);

    // Print the list
    printf("List after deleting from beginning: ");
    print_list(head);

    // Delete a node from the end of the list
    head = delete_from_end(head);

    // Print the list
    printf("List after deleting from end: ");
    print_list(head);

    // Delete a node after a given node
    head = delete_after_node(head, head);

    // Print the list
    printf("List after deleting after node: ");
    print_list(head);

    // Search for a node in the list
    struct node *found_node = search_node(head, 3);
    if (found_node != NULL) {
        printf("Node found: %d\n", found_node->data);
    } else {
        printf("Node not found\n");
    }

    return 0;
}