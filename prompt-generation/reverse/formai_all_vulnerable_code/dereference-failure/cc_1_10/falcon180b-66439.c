//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for a node in the linked list
typedef struct node {
    char data;
    struct node* next;
} Node;

// Function to create a new node with the given data
Node* create_node(char data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Function to add a new node to the end of the list
void add_node(Node** head, char data) {
    Node* new_node = create_node(data);
    Node* temp = *head;
    if (*head == NULL) {
        *head = new_node;
        return;
    }
    while (temp->next!= NULL) {
        temp = temp->next;
    }
    temp->next = new_node;
}

// Function to print the contents of the list
void print_list(Node* head) {
    Node* temp = head;
    while (temp!= NULL) {
        printf("%c ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Function to reverse the list
void reverse_list(Node** head) {
    Node* prev = NULL;
    Node* curr = *head;
    while (curr!= NULL) {
        Node* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    *head = prev;
}

// Function to sort the list in alphabetical order
void sort_list(Node** head) {
    Node* temp = *head;
    while (temp!= NULL) {
        char data = temp->data;
        temp->data = temp->next->data;
        temp->next->data = data;
        temp = temp->next->next;
    }
}

// Main function to demonstrate the linked list operations
int main() {
    Node* head = NULL;

    // Add nodes to the list
    add_node(&head, 'a');
    add_node(&head, 'b');
    add_node(&head, 'c');
    add_node(&head, 'd');

    // Print the contents of the list
    printf("Original list:\n");
    print_list(head);

    // Reverse the list
    reverse_list(&head);

    // Print the reversed list
    printf("Reversed list:\n");
    print_list(head);

    // Sort the list
    sort_list(&head);

    // Print the sorted list
    printf("Sorted list:\n");
    print_list(head);

    return 0;
}