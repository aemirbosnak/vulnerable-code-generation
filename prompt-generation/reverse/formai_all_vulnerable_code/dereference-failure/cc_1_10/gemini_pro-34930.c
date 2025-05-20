//GEMINI-pro DATASET v1.0 Category: Linked list operations ; Style: modular
#include <stdio.h>
#include <stdlib.h>

// Node structure
typedef struct node {
    int data;
    struct node *next;
} Node;

// Function to create a new node
Node* create_node(int data) {
    Node *new_node = (Node*)malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("Error: Couldn't allocate memory for new node.\n");
        exit(1);
    }
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Function to insert a node at the beginning of the linked list
Node* insert_at_beginning(Node *head, int data) {
    Node *new_node = create_node(data);
    new_node->next = head;
    head = new_node;
    return head;
}

// Function to insert a node at the end of the linked list
Node* insert_at_end(Node *head, int data) {
    Node *new_node = create_node(data);
    if (head == NULL) {
        head = new_node;
    } else {
        Node *current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
    return head;
}

// Function to insert a node after a given node
Node* insert_after_node(Node *head, int data, int after_data) {
    Node *new_node = create_node(data);
    if (head == NULL) {
        printf("Error: List is empty.\n");
        exit(1);
    }
    Node *current = head;
    while (current != NULL) {
        if (current->data == after_data) {
            new_node->next = current->next;
            current->next = new_node;
            return head;
        }
        current = current->next;
    }
    printf("Error: Node with data %d not found.\n", after_data);
    exit(1);
}

// Function to delete a node from the beginning of the linked list
Node* delete_from_beginning(Node *head) {
    if (head == NULL) {
        printf("Error: List is empty.\n");
        exit(1);
    }
    Node *new_head = head->next;
    free(head);
    return new_head;
}

// Function to delete a node from the end of the linked list
Node* delete_from_end(Node *head) {
    if (head == NULL) {
        printf("Error: List is empty.\n");
        exit(1);
    }
    Node *current = head;
    Node *previous = NULL;
    while (current->next != NULL) {
        previous = current;
        current = current->next;
    }
    if (previous == NULL) {
        head = NULL;
    } else {
        previous->next = NULL;
    }
    free(current);
    return head;
}

// Function to delete a node after a given node
Node* delete_after_node(Node *head, int after_data) {
    if (head == NULL) {
        printf("Error: List is empty.\n");
        exit(1);
    }
    Node *current = head;
    Node *previous = NULL;
    while (current != NULL) {
        if (current->data == after_data) {
            if (current->next == NULL) {
                printf("Error: No node after given node.\n");
                exit(1);
            }
            previous = current;
            current = current->next;
            break;
        }
        current = current->next;
    }
    if (previous == NULL) {
        printf("Error: Node with data %d not found.\n", after_data);
        exit(1);
    }
    previous->next = current->next;
    free(current);
    return head;
}

// Function to print the linked list
void print_list(Node *head) {
    Node *current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Main function
int main() {
    // Create an empty linked list
    Node *head = NULL;

    // Insert some nodes into the linked list
    head = insert_at_beginning(head, 1);
    head = insert_at_end(head, 2);
    head = insert_at_end(head, 3);
    head = insert_after_node(head, 4, 2);

    // Print the linked list before deletion
    printf("Linked list before deletion:\n");
    print_list(head);

    // Delete a node from the beginning of the linked list
    head = delete_from_beginning(head);

    // Delete a node from the end of the linked list
    head = delete_from_end(head);

    // Delete a node after a given node
    head = delete_after_node(head, 2);

    // Print the linked list after deletion
    printf("Linked list after deletion:\n");
    print_list(head);

    return 0;
}