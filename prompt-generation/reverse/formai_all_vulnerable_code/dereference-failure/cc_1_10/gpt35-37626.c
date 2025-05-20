//FormAI DATASET v1.0 Category: Data structures visualization ; Style: secure
#include <stdio.h>
#include <stdlib.h>

// Define struct for node
typedef struct node {
    int data;
    struct node *next;
} node;

// Function to insert a new node at the front of a linked list
void insertNode(node **head, int newData) {
    // Allocate memory for new node
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = newData;
    // Update new node's next pointer to point to current head
    newNode->next = *head;
    // Update head pointer to point to new node
    *head = newNode;
}

// Function to display a linked list
void displayList(node *head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Function to delete a node from a linked list
void deleteNode(node **head, int key) {
    // Initialize previous node and current node pointers
    node *prevNode = NULL;
    node *currNode = *head;
    // Traverse linked list until key is found or until end of list is reached
    while (currNode != NULL && currNode->data != key) {
        prevNode = currNode;
        currNode = currNode->next;
    }
    // If key was not found in the list, print an error message and return
    if (currNode == NULL) {
        printf("Error: Key %d not found in list\n", key);
        return;
    }
    // Update previous node's next pointer to skip over the current node
    prevNode->next = currNode->next;
    // Free memory allocated for current node
    free(currNode);
}

int main() {
    node *head = NULL;
    // Insert nodes at the front of the list
    insertNode(&head, 5);
    insertNode(&head, 3);
    insertNode(&head, 1);
    // Display the linked list
    printf("Linked list:\n");
    displayList(head);
    // Delete a node from the list
    deleteNode(&head, 3);
    // Display the updated linked list
    printf("Updated linked list:\n");
    displayList(head);
    return 0;
}