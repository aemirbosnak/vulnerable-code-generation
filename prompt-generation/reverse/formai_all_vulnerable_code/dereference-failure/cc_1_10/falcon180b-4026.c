//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>

// Node structure definition
typedef struct node {
    int data;
    struct node* next;
} Node;

// Function to create a new node with the given data
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory error\n");
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to add a node at the beginning of the list
void push(Node** headRef, int newData) {
    Node* newNode = createNode(newData);
    newNode->next = *headRef;
    *headRef = newNode;
}

// Function to add a node after a given position in the list
void insertAfter(Node* prevNode, int newData) {
    if (prevNode == NULL) {
        printf("The given previous node cannot be NULL\n");
        return;
    }
    Node* newNode = createNode(newData);
    newNode->next = prevNode->next;
    prevNode->next = newNode;
}

// Function to delete a node with the given data from the list
void deleteNode(Node** headRef, int key) {
    Node* temp = *headRef;
    Node* prev = NULL;

    if (temp!= NULL && temp->data == key) {
        *headRef = temp->next;
        free(temp);
        return;
    }

    while (temp!= NULL && temp->data!= key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
        return;

    prev->next = temp->next;
    free(temp);
}

// Function to print the list
void printList(Node* node) {
    while (node!= NULL) {
        printf("%d ", node->data);
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
    push(&head, 40);

    // Print the list
    printf("Original list: ");
    printList(head);

    // Insert a node after the second node in the list
    insertAfter(head->next, 25);

    // Print the updated list
    printf("\nList after inserting a node: ");
    printList(head);

    // Delete a node with value 20 from the list
    deleteNode(&head, 20);

    // Print the updated list
    printf("\nList after deleting a node: ");
    printList(head);

    return 0;
}