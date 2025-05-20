//FormAI DATASET v1.0 Category: Data structures visualization ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>

// A structure to represent a node in the linked list
struct Node {
    int data;
    struct Node* next;
};

// A function to insert a new node at the beginning of a linked list
void push(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

// A function to print the linked list
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL");
}

int main() {
    // Initialize an empty linked list
    struct Node* head = NULL;

    // Add some nodes to the linked list
    push(&head, 6);
    push(&head, 7);
    push(&head, 1);
    push(&head, 2);

    // Print the linked list
    printf("The original linked list:\n");
    printList(head);
    printf("\n");

    // Reverse the linked list
    struct Node* current = head;
    struct Node* prev = NULL;
    struct Node* next = NULL;

    while (current != NULL) {
        // Store the next node
        next = current->next;

        // Reverse the current node's pointer
        current->next = prev;

        // Move pointers one position ahead
        prev = current;
        current = next;
    }

    // Set the new head of the linked list
    head = prev;

    // Print the linked list after reversing
    printf("The reversed linked list:\n");
    printList(head);
    printf("\n");

    return 0;
}