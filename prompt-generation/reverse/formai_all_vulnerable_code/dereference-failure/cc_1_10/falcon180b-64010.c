//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define structure for a node
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function to create a new node with the given data
Node* newNode(int data) {
    Node* node = (Node*) malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Function to add a node at the beginning of the list
void push(Node** head_ref, int new_data) {
    Node* new_node = newNode(new_data);
    new_node->next = *head_ref;
    *head_ref = new_node;
}

// Function to add a node at the end of the list
void append(Node** head_ref, int new_data) {
    Node* new_node = newNode(new_data);
    Node* last = *head_ref;

    if (*head_ref == NULL) {
        new_node->next = NULL;
        *head_ref = new_node;
        return;
    }

    while (last->next!= NULL)
        last = last->next;

    last->next = new_node;
    return;
}

// Function to add a node after the given position in the list
void insertAfter(Node* prev_node, int new_data) {
    if (prev_node == NULL) {
        printf("the given previous node cannot be NULL");
        return;
    }

    Node* new_node = newNode(new_data);
    new_node->next = prev_node->next;
    prev_node->next = new_node;
    return;
}

// Function to delete a node at the given position in the list
void deleteNode(Node **head_ref, Node *del) {
    Node* temp = *head_ref;

    if (temp == del) {
        *head_ref = temp->next;
        free(temp);
        return;
    }

    while (temp!= NULL && temp!= del) {
        temp = temp->next;
    }

    if (temp == NULL)
        return;

    Node* next = del->next;
    free(del);
    temp->next = next;
    return;
}

// Function to search for a node with the given data in the list
Node* search(Node* head, int x) {
    Node* current = head;
    while (current!= NULL) {
        if (current->data == x)
            return current;
        current = current->next;
    }
    return NULL;
}

// Function to print the list
void printList(Node* node) {
    while (node!= NULL) {
        printf(" %d ", node->data);
        node = node->next;
    }
}

// Main function
int main() {
    Node* head = NULL;

    // Add nodes to the list
    push(&head, 10);
    push(&head, 20);
    push(&head, 30);
    append(&head, 40);
    append(&head, 50);

    // Print the list
    printf("Singly linked list: ");
    printList(head);

    // Search for a node with the given data
    Node* result = search(head, 20);
    if (result!= NULL)
        printf("\nNode found with value %d", result->data);
    else
        printf("\nNode not found in the list");

    // Delete a node at the given position
    Node* del = search(head, 30);
    if (del!= NULL)
        deleteNode(&head, del);

    // Print the updated list
    printf("\nList after deleting node with value 30: ");
    printList(head);

    return 0;
}