//FormAI DATASET v1.0 Category: Linked list operations ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

// Define the structure of our Linked List Nodes
typedef struct linkedlist_node {
    int data;
    struct linkedlist_node* next;
} LinkedListNode;

// Function to add a new Node to the linked list
void add(LinkedListNode** head, int data) {
    
    LinkedListNode* new_node = (LinkedListNode*) malloc(sizeof(LinkedListNode));
    new_node->data = data;
    new_node->next = (*head);
    *head = new_node;
}

// Function to remove a current Node from the linked list
void remove_node(LinkedListNode** head, int data) {
    
    LinkedListNode* current_node = *head;
    LinkedListNode* prev_node = NULL;
    
    // Look for the node with the specified data value
    while (current_node != NULL && current_node->data != data) {
        prev_node = current_node;
        current_node = current_node->next;
    }
    
    // If we didn't find a Node with the specified value, return
    if (current_node == NULL) {
        printf("Node with value %d not found.\n", data);
        return;
    }
    
    // Remove the current node from the list
    if (prev_node == NULL) {
        *head = current_node->next;
    } else {
        prev_node->next = current_node->next;
    }
    free(current_node);
}

// Function to print the contents of the linked list
void print_list(LinkedListNode* head) {
    
    LinkedListNode* current_node = head;
    while (current_node != NULL) {
        printf("%d -> ", current_node->data);
        current_node = current_node->next;
    }
    printf("NULL\n");
}

int main() {
    
    // Initialize our Linked List
    LinkedListNode* head = NULL;
    
    // Add some Nodes to it
    add(&head, 5);
    add(&head, 9);
    add(&head, 2);
    add(&head, 7);
    
    // Print out the contents of the List
    printf("Initial List: ");
    print_list(head);
    
    // Remove Node with data value of 2
    remove_node(&head, 2);
    
    // Print out the List after removing a Node
    printf("Updated List: ");
    print_list(head);
    
    return 0;
}