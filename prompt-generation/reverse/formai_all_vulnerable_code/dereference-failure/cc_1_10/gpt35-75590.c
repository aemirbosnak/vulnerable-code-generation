//FormAI DATASET v1.0 Category: Data structures visualization ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

// A structure to represent a node in the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to add a new node at the beginning of the linked list
void push(struct Node** head_ref, int new_data) {

    // Allocate memory for new node
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

    // Assign data to the new node
    new_node->data = new_data;

    // Set the next pointer of new node to the current head
    new_node->next = (*head_ref);

    // Set the head pointer to the new node
    (*head_ref) = new_node;
}

// Function to print the linked list in reverse order
void printReverse(struct Node* head) {

    // If the linked list is empty, return
    if(head == NULL) {
        return;
    }

    // Recursively call printReverse for the next node
    printReverse(head->next);

    // Print the data of the current node
    printf("%d ", head->data);
}

int main() {

    // Initialize an empty linked list
    struct Node* head = NULL;

    // Add some nodes to the list
    push(&head, 1);
    push(&head, 2);
    push(&head, 3);
    push(&head, 4);

    // Print the linked list in reverse order
    printf("The linked list in reverse order is: ");
    printReverse(head);

    return 0;
}