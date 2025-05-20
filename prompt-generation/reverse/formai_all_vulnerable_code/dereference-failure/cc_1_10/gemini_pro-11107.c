//GEMINI-pro DATASET v1.0 Category: Linked list operations ; Style: shape shifting
// Shape-Shifting Linked List Operations

#include <stdio.h>
#include <stdlib.h>

// Node structure
typedef struct node {
    int data;
    struct node *next;
} Node;

// Insert at the beginning
Node *insert_beginning(Node *head, int data) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = head;
    return new_node;
}

// Insert at the end
Node *insert_end(Node *head, int data) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;

    if (head == NULL) {
        return new_node;
    }

    Node *current = head;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = new_node;
    return head;
}

// Insert at a specific position
Node *insert_position(Node *head, int data, int position) {
    if (position == 1) {
        return insert_beginning(head, data);
    }

    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = data;

    Node *current = head;
    for (int i = 1; i < position - 1; i++) {
        if (current == NULL) {
            printf("Invalid position: %d\n", position);
            free(new_node);
            return head;
        }
        current = current->next;
    }

    if (current == NULL) {
        printf("Invalid position: %d\n", position);
        free(new_node);
        return head;
    }

    new_node->next = current->next;
    current->next = new_node;
    return head;
}

// Delete at the beginning
Node *delete_beginning(Node *head) {
    if (head == NULL) {
        return NULL;
    }

    Node *new_head = head->next;
    free(head);
    return new_head;
}

// Delete at the end
Node *delete_end(Node *head) {
    if (head == NULL) {
        return NULL;
    }

    if (head->next == NULL) {
        free(head);
        return NULL;
    }

    Node *current = head;
    while (current->next->next != NULL) {
        current = current->next;
    }

    free(current->next);
    current->next = NULL;
    return head;
}

// Delete at a specific position
Node *delete_position(Node *head, int position) {
    if (position == 1) {
        return delete_beginning(head);
    }

    Node *current = head;
    for (int i = 1; i < position - 1; i++) {
        if (current == NULL) {
            printf("Invalid position: %d\n", position);
            return head;
        }
        current = current->next;
    }

    if (current == NULL) {
        printf("Invalid position: %d\n", position);
        return head;
    }

    Node *to_be_deleted = current->next;
    current->next = to_be_deleted->next;
    free(to_be_deleted);
    return head;
}

// Search for an element
Node *search(Node *head, int data) {
    while (head != NULL) {
        if (head->data == data) {
            return head;
        }
        head = head->next;
    }

    return NULL;
}

// Print the linked list
void print_list(Node *head) {
    printf("[ ");
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("]\n");
}

// Main function
int main() {
    // Initialize an empty linked list
    Node *head = NULL;

    // Shape-Shifting Operations

    // Insert 10, 20, 30, 40, 50 at the end
    head = insert_end(head, 10);
    head = insert_end(head, 20);
    head = insert_end(head, 30);
    head = insert_end(head, 40);
    head = insert_end(head, 50);

    // Print the linked list
    print_list(head); // [ 10 20 30 40 50 ]

    // Insert 15 at the beginning
    head = insert_beginning(head, 15);

    // Print the linked list
    print_list(head); // [ 15 10 20 30 40 50 ]

    // Insert 25 at position 3
    head = insert_position(head, 25, 3);

    // Print the linked list
    print_list(head); // [ 15 10 25 20 30 40 50 ]

    // Delete the first element
    head = delete_beginning(head);

    // Print the linked list
    print_list(head); // [ 10 25 20 30 40 50 ]

    // Delete the last element
    head = delete_end(head);

    // Print the linked list
    print_list(head); // [ 10 25 20 30 40 ]

    // Delete the element at position 3
    head = delete_position(head, 3);

    // Print the linked list
    print_list(head); // [ 10 25 30 40 ]

    // Search for the element 30
    Node *found_node = search(head, 30);

    if (found_node != NULL) {
        printf("Element found: %d\n", found_node->data);
    } else {
        printf("Element not found.\n");
    }

    // Free the linked list
    while (head != NULL) {
        Node *next = head->next;
        free(head);
        head = next;
    }

    return 0;
}