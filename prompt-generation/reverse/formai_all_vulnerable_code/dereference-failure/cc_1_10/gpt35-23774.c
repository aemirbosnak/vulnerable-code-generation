//FormAI DATASET v1.0 Category: Linked list operations ; Style: portable
#include <stdio.h>
#include <stdlib.h>

// Define a node of the linked list
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Insert a new node at the beginning of the linked list
void insertAtBeginning(Node** headRef, int newData) {
    // Allocate memory for the new node
    Node* newNode = (Node*)malloc(sizeof(Node));

    // Set the data and next fields of the new node
    newNode->data = newData;
    newNode->next = *headRef;

    // Set the head of the linked list to the new node
    *headRef = newNode;
}

// Insert a new node after a given node
void insertAfter(Node* prevNode, int newData) {
    // Check if the previous node is null
    if (prevNode == NULL) {
        printf("The previous node cannot be null.");
        return;
    }

    // Allocate memory for the new node
    Node* newNode = (Node*)malloc(sizeof(Node));

    // Set the data and next fields of the new node
    newNode->data = newData;
    newNode->next = prevNode->next;

    // Set the next field of the previous node to the new node
    prevNode->next = newNode;
}

// Insert a new node at the end of the linked list
void insertAtEnd(Node** headRef, int newData) {
    // Allocate memory for the new node
    Node* newNode = (Node*)malloc(sizeof(Node));

    // Set the data and next fields of the new node
    newNode->data = newData;
    newNode->next = NULL;

    // Check if the linked list is empty
    if (*headRef == NULL) {
        // Set the head of the linked list to the new node
        *headRef = newNode;
        return;
    }

    // Traverse the linked list to the end
    Node* lastNode = *headRef;
    while (lastNode->next != NULL) {
        lastNode = lastNode->next;
    }

    // Set the next field of the last node to the new node
    lastNode->next = newNode;
}

// Remove the first occurrence of a node with a given value
void removeNode(Node** headRef, int value) {
    // Check if the linked list is empty
    if (*headRef == NULL) {
        printf("The linked list is empty.");
        return;
    }

    // Check if the first node contains the value
    if ((*headRef)->data == value) {
        Node* temp = *headRef;
        *headRef = (*headRef)->next;
        free(temp);
        return;
    }

    // Traverse the linked list to find the node with the value
    Node* prevNode = *headRef;
    Node* currentNode = (*headRef)->next;
    while (currentNode != NULL && currentNode->data != value) {
        prevNode = currentNode;
        currentNode = currentNode->next;
    }

    // Check if the node with the value was found
    if (currentNode == NULL) {
        printf("The linked list does not contain the value.");
        return;
    }

    // Remove the node with the value
    prevNode->next = currentNode->next;
    free(currentNode);
}

// Print the linked list
void printLinkedList(Node* head) {
    // Traverse the linked list
    Node* currentNode = head;
    while (currentNode != NULL) {
        // Print the data field of the current node
        printf("%d ", currentNode->data);

        // Move to the next node
        currentNode = currentNode->next;
    }

    // Print a newline character
    printf("\n");
}

int main() {
    // Initialize the linked list
    Node* head = NULL;

    // Insert nodes into the linked list
    insertAtBeginning(&head, 1);
    insertAtEnd(&head, 2);
    insertAfter(head->next, 3);
    insertAtEnd(&head, 4);
    insertAtBeginning(&head, 0);

    // Print the linked list
    printf("Linked list: ");
    printLinkedList(head);

    // Remove a node from the linked list
    removeNode(&head, 3);

    // Print the linked list again
    printf("Linked list after removing value 3: ");
    printLinkedList(head);

    // Free the memory allocated for the linked list
    Node* currentNode = head;
    while (currentNode != NULL) {
        Node* temp = currentNode;
        currentNode = currentNode->next;
        free(temp);
    }

    return 0;
}