//GEMINI-pro DATASET v1.0 Category: Database Indexing System ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node structure for the linked list
struct Node {
    int data;
    struct Node *next;
};

// Function to create a new node
struct Node *create_node(int data) {
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Function to insert a new node at the beginning of the linked list
struct Node *insert_at_beginning(struct Node *head, int data) {
    struct Node *new_node = create_node(data);
    new_node->next = head;
    return new_node;
}

// Function to insert a new node at the end of the linked list
struct Node *insert_at_end(struct Node *head, int data) {
    struct Node *new_node = create_node(data);
    if (head == NULL) {
        return new_node;
    }
    struct Node *current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = new_node;
    return head;
}

// Function to insert a new node after a given node
struct Node *insert_after(struct Node *head, int data, int after) {
    struct Node *new_node = create_node(data);
    if (head == NULL) {
        return new_node;
    }
    struct Node *current = head;
    while (current != NULL && current->data != after) {
        current = current->next;
    }
    if (current == NULL) {
        return head;
    }
    new_node->next = current->next;
    current->next = new_node;
    return head;
}

// Function to delete a node from the linked list
struct Node *delete_node(struct Node *head, int data) {
    if (head == NULL) {
        return NULL;
    }
    if (head->data == data) {
        return head->next;
    }
    struct Node *current = head;
    while (current->next != NULL && current->next->data != data) {
        current = current->next;
    }
    if (current->next == NULL) {
        return head;
    }
    current->next = current->next->next;
    return head;
}

// Function to search for a node in the linked list
struct Node *search_node(struct Node *head, int data) {
    struct Node *current = head;
    while (current != NULL && current->data != data) {
        current = current->next;
    }
    return current;
}

// Function to print the linked list
void print_list(struct Node *head) {
    struct Node *current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    // Create an empty linked list
    struct Node *head = NULL;

    // Insert some nodes into the linked list
    head = insert_at_beginning(head, 10);
    head = insert_at_end(head, 20);
    head = insert_after(head, 15, 10);

    // Print the linked list
    printf("Linked list: ");
    print_list(head);

    // Search for a node in the linked list
    struct Node *found_node = search_node(head, 15);
    if (found_node != NULL) {
        printf("Node found: %d\n", found_node->data);
    } else {
        printf("Node not found\n");
    }

    // Delete a node from the linked list
    head = delete_node(head, 15);

    // Print the linked list
    printf("Linked list after deletion: ");
    print_list(head);

    return 0;
}