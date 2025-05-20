//FormAI DATASET v1.0 Category: Linked list operations ; Style: immersive
#include <stdio.h>
#include <stdlib.h>

// Define the structure of our node
struct node {
    int data;
    struct node* next;
};

// Declare the functions that our program will use
void add_node(struct node** head_ref, int new_data);
void delete_node(struct node** head_ref, int index);
void print_list(struct node* head);

int main() {
    // Declare the head node for our linked list
    struct node* head = NULL;
    
    // Fill our linked list with some initial values
    add_node(&head, 1);
    add_node(&head, 3);
    add_node(&head, 5);
    
    // Print the list before we delete any nodes
    printf("\nInitial Linked List: ");
    print_list(head);
    
    // Delete the second node (index 1)
    delete_node(&head, 1);
    
    // Print the updated list
    printf("\nLinked List After Node Deletion: ");
    print_list(head);
    
    // Add a few more nodes to the list and print it again
    add_node(&head, 7);
    add_node(&head, 9);
    printf("\nLinked List After Node Addition: ");
    print_list(head);
    
    // Delete the first node from the list
    delete_node(&head, 0);
    
    // Print the final linked list
    printf("\nFinal Linked List: ");
    print_list(head);
    
    return 0;
}

// Function to add a new node to the end of the list
void add_node(struct node** head_ref, int new_data) {
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    new_node->data = new_data;
    new_node->next = NULL;
    
    if (*head_ref == NULL) {
        // If the list is empty, make this the head node
        *head_ref = new_node;
    } else {
        // Traverse the list to find the end and append the new node
        struct node* current_node = *head_ref;
        while (current_node->next != NULL) {
            current_node = current_node->next;
        }
        current_node->next = new_node;
    }
}

// Function to delete a node at a specific index
void delete_node(struct node** head_ref, int index) {
    if (*head_ref == NULL) {
        return;
    } else if (index == 0) {
        // If we're deleting the head node, move the head to the next node
        *head_ref = (*head_ref)->next;
    } else {
        // Traverse the list to find the node before the one we want to delete
        struct node* current_node = *head_ref;
        int i;
        for (i = 0; i < index-1; i++) {
            if (current_node->next == NULL) {
                return;
            }
            current_node = current_node->next;
        }
        // Delete the node by skipping over it in the linked list
        current_node->next = current_node->next->next;
    }
}

// Function to print the current state of the linked list
void print_list(struct node* head) {
    if (head == NULL) {
        printf("List is empty.");
        return;
    }
    printf("%d", head->data);
    struct node* current_node = head->next;
    while (current_node != NULL) {
        printf(", %d", current_node->data);
        current_node = current_node->next;
    }
}