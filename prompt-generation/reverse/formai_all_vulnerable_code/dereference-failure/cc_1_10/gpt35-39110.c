//FormAI DATASET v1.0 Category: Educational ; Style: careful
#include <stdio.h>
#include <stdlib.h>

// Define a linked list struct
typedef struct linked_list_node {
    int value;
    struct linked_list_node* next;
} linked_list_node;

// Function to create a new node
linked_list_node* create_node(int value) {
    linked_list_node* new_node = (linked_list_node*)malloc(sizeof(linked_list_node));
    new_node->value = value;
    new_node->next = NULL;
    return new_node;
}

// Function to add a node to the end of the linked list
void add_node(linked_list_node** head, int value) {
    linked_list_node* new_node = create_node(value);
    if (*head == NULL) {
        *head = new_node;
    }
    else {
        linked_list_node* current_node = *head;
        while (current_node->next != NULL) {
            current_node = current_node->next;
        }
        current_node->next = new_node;
    }
}

// Function to print all nodes in the linked list
void print_list(linked_list_node* head) {
    linked_list_node* current_node = head;
    while (current_node != NULL) {
        printf("%d ", current_node->value);
        current_node = current_node->next;
    }
    printf("\n");
}

int main() {
    // Create an empty linked list
    linked_list_node* head = NULL;

    // Add some nodes to the linked list
    add_node(&head, 5);
    add_node(&head, 10);
    add_node(&head, 15);

    // Print all nodes in the linked list
    print_list(head);

    // Free all nodes in the linked list
    linked_list_node* current_node = head;
    while (current_node != NULL) {
        linked_list_node* next_node = current_node->next;
        free(current_node);
        current_node = next_node;
    }

    return 0;
}