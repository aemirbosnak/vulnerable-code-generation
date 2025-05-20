//Falcon2-11B DATASET v1.0 Category: Data structures visualization ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

// Define the data structure
typedef struct node {
    int data;
    struct node* next;
} node;

// Create a linked list
node* head = NULL;

// Function to add a new node to the list
void addNode(int data) {
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = data;
    newNode->next = NULL;

    // If the list is empty, set the head to the new node
    if (head == NULL) {
        head = newNode;
    } else {
        node* current = head;
        while (current->next!= NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

// Function to print the list
void printList() {
    node* current = head;
    while (current!= NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Function to delete a node from the list
void deleteNode(int data) {
    node* current = head;
    node* previous = NULL;

    // If the node to be deleted is the head, update the head
    if (current->data == data) {
        head = current->next;
        free(current);
        return;
    }

    // Search for the node to be deleted
    while (current!= NULL && current->data!= data) {
        previous = current;
        current = current->next;
    }

    // If the node was not found, return
    if (current == NULL) {
        return;
    }

    // Update the previous node's next pointer
    if (previous!= NULL) {
        previous->next = current->next;
    } else {
        head = current->next;
    }

    // Free the node
    free(current);
}

// Main function
int main() {
    // Add nodes to the list
    addNode(1);
    addNode(2);
    addNode(3);
    addNode(4);
    addNode(5);

    // Print the list
    printf("Original list: ");
    printList();

    // Delete a node from the list
    deleteNode(3);

    // Print the updated list
    printf("Updated list: ");
    printList();

    return 0;
}