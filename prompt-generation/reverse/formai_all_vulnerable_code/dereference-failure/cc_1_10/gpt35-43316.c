//FormAI DATASET v1.0 Category: Data structures visualization ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>

// Define a node structure for a list
struct Node {
    int data;
    struct Node* next;
};

// Function to add a node at the beginning of a list
void push(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

// Function to print the list
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
}

int main() {
    // Create a list with some nodes
    struct Node* head = NULL;
    push(&head, 1);
    push(&head, 2);
    push(&head, 3);

    // Print the list
    printf("Original Linked List:\n");
    printList(head);
    printf("\n");

    // Reverse the list
    struct Node* prev = NULL;
    struct Node* current = head;
    struct Node* next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;

    // Print the reversed list
    printf("Reversed Linked List:\n");
    printList(head);
    printf("\n");

    // Free memory
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}