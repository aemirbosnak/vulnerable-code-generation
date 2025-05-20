//Falcon-180B DATASET v1.0 Category: Memory management ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define structure for a node
typedef struct node {
    int data;
    struct node* next;
} Node;

// Function to create a new node with given data
Node* createNode(int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));

    if (newNode == NULL) {
        printf("Memory error\n");
        exit(1);
    }

    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}

// Function to add a node at the end of the list
void addNode(Node** head, int data) {
    Node* newNode = createNode(data);
    Node* temp = *head;

    // If the list is empty, set the new node as the head
    if (*head == NULL) {
        newNode->next = NULL;
        *head = newNode;
        return;
    }

    // Traverse to the end of the list
    while (temp->next!= NULL)
        temp = temp->next;

    // Add the new node at the end
    temp->next = newNode;
}

// Function to delete a node with given data
void deleteNode(Node** head, int data) {
    Node* temp = *head;
    Node* prev = NULL;

    // If the head node is to be deleted
    if (temp!= NULL && temp->data == data) {
        *head = temp->next;
        free(temp);
        return;
    }

    // Traverse the list to find the node to be deleted
    while (temp!= NULL && temp->data!= data) {
        prev = temp;
        temp = temp->next;
    }

    // If the node is not found
    if (temp == NULL)
        return;

    // Unlink the node from the list
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

int main() {
    Node* head = NULL;

    // Add nodes to the list
    addNode(&head, 1);
    addNode(&head, 2);
    addNode(&head, 3);
    addNode(&head, 4);
    addNode(&head, 5);

    // Print the list
    printf("Original list:\n");
    printList(head);

    // Delete a node
    deleteNode(&head, 3);

    // Print the list after deletion
    printf("\nList after deleting 3:\n");
    printList(head);

    // Delete the entire list
    Node* temp = head;
    while (temp!= NULL) {
        Node* next = temp->next;
        free(temp);
        temp = next;
    }

    return 0;
}