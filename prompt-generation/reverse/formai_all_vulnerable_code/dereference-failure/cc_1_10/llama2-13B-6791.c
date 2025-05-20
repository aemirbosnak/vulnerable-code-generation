//LLAMA2-13B DATASET v1.0 Category: Linked list operations ; Style: genius
#include <stdio.h>
#include <stdlib.h>

// Definition of linked list node
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function to create a new node with given value
Node* newNode(int value) {
    Node* node = malloc(sizeof(Node));
    node->data = value;
    node->next = NULL;
    return node;
}

// Function to insert a node at the beginning of the list
void insertAtBeginning(Node** head_ref, int value) {
    Node* new_node = newNode(value);
    new_node->next = *head_ref;
    *head_ref = new_node;
}

// Function to insert a node at the end of the list
void insertAtEnd(Node** head_ref, int value) {
    Node* current = *head_ref;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode(value);
}

// Function to print the list
void printList(Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    Node* head = NULL;

    // Example 1: Insert nodes at the beginning of the list
    insertAtBeginning(&head, 1);
    insertAtBeginning(&head, 2);
    insertAtBeginning(&head, 3);
    printList(head); // Output: 1 2 3

    // Example 2: Insert nodes at the end of the list
    insertAtEnd(&head, 4);
    insertAtEnd(&head, 5);
    insertAtEnd(&head, 6);
    printList(head); // Output: 1 2 3 4 5 6

    // Example 3: Insert nodes in the middle of the list
    Node* middle = head;
    while (middle->next != NULL) {
        middle = middle->next;
    }
    insertAtBeginning(&middle, 7);
    insertAtEnd(&middle, 8);
    printList(head); // Output: 1 2 3 4 5 6 7 8

    return 0;
}