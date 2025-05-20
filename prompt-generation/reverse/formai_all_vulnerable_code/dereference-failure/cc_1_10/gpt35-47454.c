//FormAI DATASET v1.0 Category: Linked list operations ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

// Define a struct to represent a singly linked list node
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Initialize the head of the linked list to NULL
Node* head = NULL;

// Function to insert a new node at the beginning of the linked list
void insertNode(int newData) {
    Node* newNode = (Node*) malloc(sizeof(Node)); // Allocate memory for a new node
    newNode->data = newData; // Set the data of the new node
    newNode->next = head; // Make the new node point to the current head of the linked list
    head = newNode; // Make the new node the new head of the linked list
}

// Function to delete the first occurrence of a node with a given value in the linked list
void deleteNode(int key) {
    Node* prevNode = NULL; // Pointer to keep track of the previous node while traversing the linked list
    Node* currNode = head; // Pointer to keep track of the current node while traversing the linked list

    // Traverse the linked list to find the node with the given value
    while (currNode != NULL && currNode->data != key) {
        prevNode = currNode; // Move the prevNode pointer to the current node
        currNode = currNode->next; // Move the currNode pointer to the next node
    }

    // If the node is found, delete it
    if (currNode != NULL) {
        if (prevNode != NULL) {
            prevNode->next = currNode->next; // Make the previous node point to the next node
        } else {
            head = currNode->next; // Make the next node the new head of the linked list
        }
        free(currNode); // Free the memory allocated to the deleted node
    } else {
        printf("%d not found in the linked list.\n", key);
    }
}

// Function to print the linked list
void printList() {
    Node* currNode = head; // Pointer to keep track of the current node while traversing the linked list

    printf("Linked List: ");
    // Traverse the linked list and print the data of each node
    while (currNode != NULL) {
        printf("%d ", currNode->data);
        currNode = currNode->next;
    }
    printf("\n");
}

// Function to reverse the linked list
void reverseList() {
    Node* prevNode = NULL; // Pointer to the previous node
    Node* currNode = head; // Pointer to the current node
    Node* nextNode = NULL; // Pointer to the next node

    // Traverse the linked list and reverse the links between the nodes
    while (currNode != NULL) {
        nextNode = currNode->next; // Store the next node
        currNode->next = prevNode; // Reverse the link between the current node and the previous node
        prevNode = currNode; // Move the prevNode pointer to the current node
        currNode = nextNode; // Move the currNode pointer to the next node
    }
    head = prevNode; // Make the last node the new head of the linked list
}

// Function to delete the entire linked list
void deleteList() {
    Node* currNode = head; // Pointer to keep track of the current node while traversing the linked list
    Node* nextNode = NULL; // Pointer to the next node

    // Traverse the linked list and free the memory allocated to each node
    while (currNode != NULL) {
        nextNode = currNode->next; // Store the next node
        free(currNode); // Free the memory allocated to the current node
        currNode = nextNode; // Move the currNode pointer to the next node
    }
    head = NULL; // Make the head of the linked list NULL
}

int main() {
    // Insert nodes into the linked list
    insertNode(5);
    insertNode(10);
    insertNode(15);
    insertNode(20);

    // Print the initial linked list
    printf("Initial ");
    printList();

    // Delete a node from the linked list
    deleteNode(10);

    // Print the updated linked list
    printf("Updated ");
    printList();

    // Reverse the linked list
    reverseList();

    // Print the reversed linked list
    printf("Reversed ");
    printList();

    // Delete the entire linked list
    deleteList();

    // Print the linked list after deletion
    printf("Deleted ");
    printList();

    return 0;
}