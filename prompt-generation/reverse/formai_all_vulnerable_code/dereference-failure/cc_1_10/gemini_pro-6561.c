//GEMINI-pro DATASET v1.0 Category: Linked list operations ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

// Node structure
typedef struct Node {
    int data;
    struct Node *next;
} Node;

// Head of the linked list
Node *head = NULL;

// Function to insert a node at the beginning of the linked list
void insertAtBeginning(int data) {
    // Create a new node
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = head;

    // Update the head of the linked list
    head = newNode;
}

// Function to insert a node at the end of the linked list
void insertAtEnd(int data) {
    // Create a new node
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    // If the linked list is empty, make the new node as the head
    if (head == NULL) {
        head = newNode;
    } else {
        // Traverse the linked list until we reach the last node
        Node *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }

        // Insert the new node at the end
        temp->next = newNode;
    }
}

// Function to insert a node at a given position in the linked list
void insertAtPosition(int data, int position) {
    // Create a new node
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;

    // If the position is 1, make the new node as the head
    if (position == 1) {
        newNode->next = head;
        head = newNode;
    } else {
        // Traverse the linked list until we reach the position
        Node *temp = head;
        for (int i = 1; i < position; i++) {
            temp = temp->next;
        }

        // Insert the new node at the given position
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

// Function to delete a node from the beginning of the linked list
void deleteFromBeginning() {
    // If the linked list is empty, do nothing
    if (head == NULL) {
        return;
    }

    // Store the head node in a temporary variable
    Node *temp = head;

    // Update the head of the linked list
    head = head->next;

    // Free the memory allocated to the deleted node
    free(temp);
}

// Function to delete a node from the end of the linked list
void deleteFromEnd() {
    // If the linked list is empty, do nothing
    if (head == NULL) {
        return;
    }

    // If the linked list has only one node, make the head as NULL
    if (head->next == NULL) {
        head = NULL;
    } else {
        // Traverse the linked list until we reach the second last node
        Node *temp = head;
        while (temp->next->next != NULL) {
            temp = temp->next;
        }

        // Free the memory allocated to the last node
        free(temp->next);

        // Make the second last node as the last node
        temp->next = NULL;
    }
}

// Function to delete a node from a given position in the linked list
void deleteFromPosition(int position) {
    // If the position is 1, delete the head node
    if (position == 1) {
        deleteFromBeginning();
    } else {
        // Traverse the linked list until we reach the node before the given position
        Node *temp = head;
        for (int i = 1; i < position - 1; i++) {
            temp = temp->next;
        }

        // Store the node to be deleted in a temporary variable
        Node *nodeToDelete = temp->next;

        // Update the next pointer of the previous node
        temp->next = nodeToDelete->next;

        // Free the memory allocated to the deleted node
        free(nodeToDelete);
    }
}

// Function to print the linked list
void printLinkedList() {
    // If the linked list is empty, print an empty message
    if (head == NULL) {
        printf("The linked list is empty.\n");
        return;
    }

    // Traverse the linked list and print the data of each node
    Node *temp = head;
    printf("The linked list is: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Main function
int main() {
    // Insert some nodes into the linked list
    insertAtBeginning(10);
    insertAtEnd(20);
    insertAtPosition(30, 2);

    // Print the linked list
    printf("The linked list after insertion:\n");
    printLinkedList();

    // Delete a node from the beginning of the linked list
    deleteFromBeginning();

    // Print the linked list
    printf("The linked list after deletion from beginning:\n");
    printLinkedList();

    // Delete a node from the end of the linked list
    deleteFromEnd();

    // Print the linked list
    printf("The linked list after deletion from end:\n");
    printLinkedList();

    // Delete a node from a given position in the linked list
    deleteFromPosition(2);

    // Print the linked list
    printf("The linked list after deletion from position 2:\n");
    printLinkedList();

    return 0;
}