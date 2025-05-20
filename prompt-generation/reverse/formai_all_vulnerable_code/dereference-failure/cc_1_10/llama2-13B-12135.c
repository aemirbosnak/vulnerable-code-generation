//LLAMA2-13B DATASET v1.0 Category: Linked list operations ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

// Node representing a linked list
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function to create a new node with given value
Node* newNode(int value) {
    Node* node = (Node*) malloc(sizeof(Node));
    node->data = value;
    node->next = NULL;
    return node;
}

// Function to append a node to the end of a linked list
Node* append(Node** head_ref, int value) {
    Node* new_node = newNode(value);
    new_node->next = *head_ref;
    *head_ref = new_node;
    return new_node;
}

// Function to print all nodes in a linked list
void printList(Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// Example program
int main() {
    Node* head = NULL;

    // Create a list with the numbers 1 to 5
    head = append(&head, 1);
    head = append(&head, 2);
    head = append(&head, 3);
    head = append(&head, 4);
    head = append(&head, 5);

    // Print the list
    printList(head);

    // Append 6 to the end of the list
    head = append(&head, 6);

    // Print the updated list
    printList(head);

    return 0;
}