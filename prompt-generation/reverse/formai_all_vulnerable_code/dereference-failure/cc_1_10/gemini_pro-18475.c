//GEMINI-pro DATASET v1.0 Category: Data structures visualization ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

// Node structure
typedef struct node {
    int data;
    struct node *next;
} node;

// Function to create a new node
node *create_node(int data) {
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Function to insert a new node at the beginning of the linked list
node *insert_at_beginning(node *head, int data) {
    node *new_node = create_node(data);
    new_node->next = head;
    return new_node;
}

// Function to insert a new node at the end of the linked list
node *insert_at_end(node *head, int data) {
    if (head == NULL) {
        return create_node(data);
    } else {
        head->next = insert_at_end(head->next, data);
        return head;
    }
}

// Function to insert a new node after a given node
node *insert_after(node *head, int data, int after) {
    if (head == NULL) {
        return NULL;
    } else if (head->data == after) {
        node *new_node = create_node(data);
        new_node->next = head->next;
        head->next = new_node;
        return head;
    } else {
        head->next = insert_after(head->next, data, after);
        return head;
    }
}

// Function to delete a node from the linked list
node *delete_node(node *head, int data) {
    if (head == NULL) {
        return NULL;
    } else if (head->data == data) {
        node *temp = head->next;
        free(head);
        return temp;
    } else {
        head->next = delete_node(head->next, data);
        return head;
    }
}

// Function to print the linked list
void print_linked_list(node *head) {
    if (head == NULL) {
        printf("[]\n");
    } else {
        printf("[");
        node *current = head;
        while (current != NULL) {
            printf("%d, ", current->data);
            current = current->next;
        }
        printf("]\n");
    }
}

// Main function
int main() {
    // Create a linked list
    node *head = NULL;
    head = insert_at_beginning(head, 10);
    head = insert_at_end(head, 20);
    head = insert_at_end(head, 30);
    head = insert_after(head, 15, 10);

    // Print the linked list
    print_linked_list(head);

    // Delete a node from the linked list
    head = delete_node(head, 20);

    // Print the linked list
    print_linked_list(head);

    return 0;
}