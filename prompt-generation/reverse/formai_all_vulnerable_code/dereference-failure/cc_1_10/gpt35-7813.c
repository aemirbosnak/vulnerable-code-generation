//FormAI DATASET v1.0 Category: Linked list operations ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

// Define the node struct
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Initialize the head node as NULL
Node* head = NULL;

// Function to insert a node at the beginning
void insertNodeAtBeginning(int value) {
    // Allocate memory for new node
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;

    // If the list is empty, make the new node as head
    if (head == NULL) {
        head = newNode;
        return;
    }

    // Insert the new node at the beginning
    newNode->next = head;
    head = newNode;
}

// Function to insert a node at the end
void insertNodeAtEnd(int value) {
    // Allocate memory for new node
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;

    // If the list is empty, make the new node as head
    if (head == NULL) {
        head = newNode;
        return;
    }

    // Traverse to the last node
    Node* currentNode = head;
    while (currentNode->next != NULL) {
        currentNode = currentNode->next;
    }

    // Insert the new node at the end
    currentNode->next = newNode;
}

// Function to delete the node at the beginning
void deleteNodeAtBeginning() {
    // If the list is empty, return
    if (head == NULL) {
        return;
    }

    // Delete the first node
    Node* nodeToDelete = head;
    head = head->next;
    free(nodeToDelete);
}

// Function to delete the node at the end
void deleteNodeAtEnd() {
    // If the list is empty, return
    if (head == NULL) {
        return;
    }

    // If there is only one node, delete it and make head NULL
    if (head->next == NULL) {
        free(head);
        head = NULL;
        return;
    }

    // Traverse to the second last node
    Node* currentNode = head;
    while (currentNode->next->next != NULL) {
        currentNode = currentNode->next;
    }

    // Delete the last node
    Node* nodeToDelete = currentNode->next;
    currentNode->next = NULL;
    free(nodeToDelete);
}

// Function to display the list
void displayList() {
    // If the list is empty, return
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    // Traverse the list and print the nodes
    Node* currentNode = head;
    while (currentNode != NULL) {
        printf("%d ", currentNode->data);
        currentNode = currentNode->next;
    }
    printf("\n");
}

// Main function
int main() {
    // Insert nodes at the beginning
    insertNodeAtBeginning(10);
    insertNodeAtBeginning(20);
    insertNodeAtBeginning(30);
    printf("List after inserting at beginning\n");
    displayList();

    // Insert nodes at the end
    insertNodeAtEnd(40);
    insertNodeAtEnd(50);
    printf("List after inserting at end\n");
    displayList();

    // Delete nodes from the beginning
    deleteNodeAtBeginning();
    deleteNodeAtBeginning();
    printf("List after deleting from beginning\n");
    displayList();

    // Delete nodes from the end
    deleteNodeAtEnd();
    deleteNodeAtEnd();
    printf("List after deleting from end\n");
    displayList();

    return 0;
}