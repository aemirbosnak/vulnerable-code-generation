//LLAMA2-13B DATASET v1.0 Category: Linked list operations ; Style: protected
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node with a given value
struct Node* newNode(int data) {
    struct Node* node = malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Function to append a node to the end of the list
void append(struct Node** head_ref, int data) {
    struct Node* new_node = newNode(data);
    new_node->next = *head_ref;
    *head_ref = new_node;
}

// Function to print the list
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;

    // Example 1: Basic Insertion
    append(&head, 1);
    append(&head, 2);
    append(&head, 3);
    printList(head);

    // Example 2: Insertion at Middle
    struct Node* new_node = newNode(4);
    append(&head, 1);
    append(&head, 2);
    new_node->next = head;
    head = new_node;
    printList(head);

    // Example 3: Deletion from Beginning
    struct Node* temp = head;
    head = head->next;
    free(temp);
    printList(head);

    // Example 4: Deletion from End
    struct Node* last = head;
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = NULL;
    printList(head);

    return 0;
}