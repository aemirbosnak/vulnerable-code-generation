//FormAI DATASET v1.0 Category: Linked list operations ; Style: complete
#include <stdio.h>
#include <stdlib.h>

// Define the struct for our linked list nodes
typedef struct node {
    int data;
    struct node *next;
} Node;

// Function to add a node to the end of the linked list
void append(Node **headRef, int newData) {
    // Create a new node
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = newData;
    newNode->next = NULL;

    // If the linked list is empty, set the new node as the head
    if (*headRef == NULL) {
        *headRef = newNode;
        return;
    }

    // Traverse to the end of the linked list
    Node *lastNode = *headRef;
    while (lastNode->next != NULL) {
        lastNode = lastNode->next;
    }

    // Set the new node as the next node of the last node
    lastNode->next = newNode;
}

// Function to delete a node with a given value from the linked list
int deleteNode(Node **headRef, int key) {
    // Check if the linked list is empty
    if (*headRef == NULL) {
        return -1;
    }

    // Check if the head node is the node to be deleted
    Node *temp = *headRef;
    if (temp->data == key) {
        *headRef = temp->next;
        free(temp);
        return 0;
    }

    // Traverse the list to find the node to be deleted
    Node *prev = NULL;
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    // If the node was not found, return -1
    if (temp == NULL) {
        return -1;
    }

    // Otherwise, delete the node and return 0
    prev->next = temp->next;
    free(temp);
    return 0;
}

// Function to print the linked list
void printList(Node *head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Main function to test our linked list operations
int main() {
    Node *head = NULL;

    // Add some nodes to the linked list
    append(&head, 2);
    append(&head, 5);
    append(&head, 10);
    append(&head, 3);

    // Print the initial linked list
    printf("Initial linked list:\n");
    printList(head);

    // Delete a node from the linked list
    int key = 5;
    if (deleteNode(&head, key) == 0) {
        printf("Node with value %d has been deleted\n", key);
    } else {
        printf("Node with value %d not found\n", key);
    }

    // Print the updated linked list
    printf("Updated linked list:\n");
    printList(head);

    return 0;
}