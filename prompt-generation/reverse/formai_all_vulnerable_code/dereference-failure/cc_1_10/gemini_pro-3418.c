//GEMINI-pro DATASET v1.0 Category: Linked list operations ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>

// Define the node structure
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
        return head;
    }

    struct node *current_node = head;
    while (current_node->next != NULL) {
        current_node = current_node->next;
    }

    current_node->next = new_node;
    return head;
}

// Insert a node at a specific position in the list
struct node *insert_at_position(struct node *head, int data, int position) {
    if (position == 0) {
        return insert_at_beginning(head, data);
    }

    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;

    struct node *current_node = head;
    int current_position = 0;
    while (current_node != NULL && current_position < position - 1) {
        current_node = current_node->next;
        current_position++;
    }

    if (current_node == NULL || current_position != position - 1) {
        printf("Invalid position\n");
        free(new_node);
        return head;
    }

    new_node->next = current_node->next;
    current_node->next = new_node;
    return head;
}

// Delete a node from the beginning of the list
struct node *delete_from_beginning(struct node *head) {
    if (head == NULL) {
        return NULL;
    }

    struct node *new_head = head->next;
    free(head);
    return new_head;
}

// Delete a node from the end of the list
struct node *delete_from_end(struct node *head) {
    if (head == NULL) {
        return NULL;
    }

    if (head->next == NULL) {
        free(head);
        return NULL;
    }

    struct node *current_node = head;
    struct node *previous_node = NULL;
    while (current_node->next != NULL) {
        previous_node = current_node;
        current_node = current_node->next;
    }

    previous_node->next = NULL;
    free(current_node);
    return head;
}

// Delete a node from a specific position in the list
struct node *delete_from_position(struct node *head, int position) {
    if (position == 0) {
        return delete_from_beginning(head);
    }

    struct node *current_node = head;
    struct node *previous_node = NULL;
    int current_position = 0;
    while (current_node != NULL && current_position < position) {
        previous_node = current_node;
        current_node = current_node->next;
        current_position++;
    }

    if (current_node == NULL || current_position != position) {
        printf("Invalid position\n");
        return head;
    }

    previous_node->next = current_node->next;
    free(current_node);
    return head;
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
    head = insert_at_beginning(head, 10);
    head = insert_at_end(head, 20);
    head = insert_at_position(head, 30, 1);
    head = insert_at_position(head, 40, 3);

    // Print the list
    print_list(head);

    // Delete some nodes from the list
    head = delete_from_beginning(head);
    head = delete_from_end(head);
    head = delete_from_position(head, 1);

    // Print the list again
    print_list(head);

    return 0;
}