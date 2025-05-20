//Falcon2-11B DATASET v1.0 Category: Data structures visualization ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the node structure
typedef struct node {
    int data;
    struct node* next;
} Node;

// Function to add a new node to the end of the list
void append(Node** head, int data) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;

    // If the list is empty, make the new node the head
    if (*head == NULL) {
        *head = new_node;
        return;
    }

    // Otherwise, traverse the list until the end and insert the new node
    Node* current = *head;
    while (current->next!= NULL) {
        current = current->next;
    }
    current->next = new_node;
}

// Function to print the contents of the list
void print_list(Node* head) {
    Node* current = head;
    while (current!= NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    // Create a new node
    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->data = 5;
    new_node->next = NULL;

    // Create a new list
    Node* head = new_node;

    // Append more nodes to the list
    append(&head, 2);
    append(&head, 3);
    append(&head, 4);

    // Print the contents of the list
    print_list(head);

    // Free the memory allocated for the nodes
    Node* current = head;
    while (current!= NULL) {
        Node* next = current->next;
        free(current);
        current = next;
    }

    return 0;
}