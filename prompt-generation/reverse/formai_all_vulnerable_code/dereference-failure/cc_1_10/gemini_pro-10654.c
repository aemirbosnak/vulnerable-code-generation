//GEMINI-pro DATASET v1.0 Category: Data structures visualization ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in a linked list
typedef struct node {
    int data;
    struct node *next;
} node;

// Function to create a new node
node* create_node(int data) {
    node *new_node = (node*)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Function to insert a node at the beginning of a linked list
node* insert_at_beginning(node *head, int data) {
    node *new_node = create_node(data);
    new_node->next = head;
    return new_node;
}

// Function to insert a node at the end of a linked list
node* insert_at_end(node *head, int data) {
    node *new_node = create_node(data);
    if (head == NULL) {
        return new_node;
    }
    node *temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new_node;
    return head;
}

// Function to delete a node from a linked list
node* delete_node(node *head, int data) {
    if (head == NULL) {
        return NULL;
    }
    if (head->data == data) {
        return head->next;
    }
    node *temp = head;
    while (temp->next != NULL) {
        if (temp->next->data == data) {
            temp->next = temp->next->next;
            return head;
        }
        temp = temp->next;
    }
    return head;
}

// Function to print a linked list
void print_list(node *head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    // Create a linked list
    node *head = NULL;
    head = insert_at_beginning(head, 1);
    head = insert_at_beginning(head, 2);
    head = insert_at_beginning(head, 3);
    head = insert_at_end(head, 4);
    head = insert_at_end(head, 5);

    // Print the linked list
    printf("Linked list: ");
    print_list(head);

    // Delete a node from the linked list
    head = delete_node(head, 3);

    // Print the linked list
    printf("Linked list after deletion: ");
    print_list(head);

    return 0;
}