//GEMINI-pro DATASET v1.0 Category: Linked list operations ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>

// Node structure
typedef struct Node {
    int data;
    struct Node *next;
} Node;

// Function to insert a node at the beginning of the linked list
Node *insert_at_beginning(Node *head, int data) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = head;
    return new_node;
}

// Function to insert a node at the end of the linked list
Node *insert_at_end(Node *head, int data) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    if (head == NULL) {
        return new_node;
    } else {
        Node *last_node = head;
        while (last_node->next != NULL) {
            last_node = last_node->next;
        }
        last_node->next = new_node;
        return head;
    }
}

// Function to insert a node after a given node
Node *insert_after(Node *head, int data, int after_data) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = data;
    if (head == NULL) {
        return new_node;
    } else {
        Node *current_node = head;
        while (current_node->data != after_data) {
            current_node = current_node->next;
            if (current_node == NULL) {
                return head;
            }
        }
        new_node->next = current_node->next;
        current_node->next = new_node;
        return head;
    }
}

// Function to delete a node from the beginning of the linked list
Node *delete_from_beginning(Node *head) {
    if (head == NULL) {
        return NULL;
    } else {
        Node *new_head = head->next;
        free(head);
        return new_head;
    }
}

// Function to delete a node from the end of the linked list
Node *delete_from_end(Node *head) {
    if (head == NULL) {
        return NULL;
    } else if (head->next == NULL) {
        free(head);
        return NULL;
    } else {
        Node *current_node = head;
        while (current_node->next->next != NULL) {
            current_node = current_node->next;
        }
        free(current_node->next);
        current_node->next = NULL;
        return head;
    }
}

// Function to delete a node after a given node
Node *delete_after(Node *head, int data) {
    if (head == NULL) {
        return NULL;
    } else {
        Node *current_node = head;
        while (current_node->data != data) {
            current_node = current_node->next;
            if (current_node == NULL) {
                return head;
            }
        }
        if (current_node->next == NULL) {
            return head;
        } else {
            Node *next_node = current_node->next;
            current_node->next = next_node->next;
            free(next_node);
            return head;
        }
    }
}

// Function to print the linked list
void print_linked_list(Node *head) {
    Node *current_node = head;
    while (current_node != NULL) {
        printf("%d ", current_node->data);
        current_node = current_node->next;
    }
    printf("\n");
}

// Main function
int main() {
    // Initialize the linked list
    Node *head = NULL;

    // Insert some nodes into the linked list
    head = insert_at_beginning(head, 10);
    head = insert_at_end(head, 20);
    head = insert_after(head, 30, 10);

    // Print the linked list
    printf("Linked list: ");
    print_linked_list(head);

    // Delete a node from the beginning of the linked list
    head = delete_from_beginning(head);

    // Print the linked list
    printf("Linked list after deleting from the beginning: ");
    print_linked_list(head);

    // Delete a node from the end of the linked list
    head = delete_from_end(head);

    // Print the linked list
    printf("Linked list after deleting from the end: ");
    print_linked_list(head);

    // Delete a node after a given node
    head = delete_after(head, 30);

    // Print the linked list
    printf("Linked list after deleting after a given node: ");
    print_linked_list(head);

    return 0;
}