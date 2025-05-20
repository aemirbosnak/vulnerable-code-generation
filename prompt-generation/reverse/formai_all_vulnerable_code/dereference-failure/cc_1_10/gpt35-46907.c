//FormAI DATASET v1.0 Category: Linked list operations ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

// Declare struct for a node in the linked list
struct node {
    int data;
    struct node *next;
};

// Declare function prototypes
void insert_node(struct node **head, int data);
void delete_node(struct node **head, int data);
void print_list(struct node *head);

// Main function to test linked list operations
int main() {
    // Initialize empty linked list
    struct node *head = NULL;

    // Insert nodes into linked list
    insert_node(&head, 5);
    insert_node(&head, 10);
    insert_node(&head, 15);

    // Print linked list
    printf("Initial linked list:\n");
    print_list(head);

    // Delete nodes from linked list
    delete_node(&head, 5);
    delete_node(&head, 15);

    // Print linked list after node deletion
    printf("Linked list after deletion:\n");
    print_list(head);

    // Insert additional nodes into linked list
    insert_node(&head, 20);
    insert_node(&head, 25);
    insert_node(&head, 30);

    // Print final linked list
    printf("Final linked list:\n");
    print_list(head);

    return 0;
}

// Function to insert a node into the linked list at the beginning
void insert_node(struct node **head, int data) {
    // Allocate memory for new node and insert at head
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = *head;
    *head = new_node;
}

// Function to delete all occurrences of a node with given data from the linked list
void delete_node(struct node **head, int data) {
    // Initialize pointers to traverse linked list
    struct node *curr_node = *head;
    struct node *prev_node = NULL;

    // Traverse linked list to find nodes to delete
    while (curr_node != NULL) {
        // If current node contains data to delete
        if (curr_node->data == data) {
            // If the current node is the head of the linked list
            if (prev_node == NULL) {
                *head = curr_node->next;
            }
            // If current node is not the head of the linked list
            else {
                prev_node->next = curr_node->next;
            }
            // Free memory for current node
            free(curr_node);
            // Move on to next node
            curr_node = prev_node->next;
        }
        // If current node does not contain data to delete
        else {
            // Move on to next node
            prev_node = curr_node;
            curr_node = curr_node->next;
        }
    }
}

// Function to print the linked list
void print_list(struct node *head) {
    // Traverse linked list and print data in each node
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}