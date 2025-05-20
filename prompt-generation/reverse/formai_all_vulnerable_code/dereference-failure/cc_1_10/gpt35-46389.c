//FormAI DATASET v1.0 Category: Linked list operations ; Style: happy
#include <stdio.h>
#include <stdlib.h>

// Define a structure for each node in our linked list.
typedef struct Node {
    int data;           // Data stored in the node.
    struct Node* next;  // Pointer to the next node in the list.
} Node;

// Create a new node with the specified data and return a pointer to it.
Node* createNode(int data) {
    // Allocate memory for the new node.
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Oops! Memory allocation failed. Please try again later.\n");
        exit(1);
    }

    // Set the data in the new node.
    newNode->data = data;

    // Set the next pointer to NULL (since this is the last node in the list).
    newNode->next = NULL;

    // Return the pointer to the new node.
    printf("Yay! A new node with the value %d has been created!\n", data);
    return newNode;
}

// Insert a node with the specified data at the front of the list.
void insertFront(Node** head, int data) {
    // Create the new node and set the next pointer to the current head.
    Node* newNode = createNode(data);
    newNode->next = *head;

    // Set the new head to be the new node.
    *head = newNode;

    printf("Awesome! A new node with the value %d has been inserted at the front of the list.\n", data);
}

// Insert a node with the specified data at the end of the list.
void insertEnd(Node** head, int data) {
    // Create the new node and set the next pointer to NULL since this is the last node.
    Node* newNode = createNode(data);
    newNode->next = NULL;

    // If the list is empty, set the new node to be the head.
    if (*head == NULL) {
        *head = newNode;
        printf("Woohoo! A new node with the value %d has been inserted at the end of the list.\n", data);
        return;
    }

    // Otherwise, iterate to the end of the list and insert the new node there.
    Node* currNode = *head;
    while (currNode->next != NULL) {
        currNode = currNode->next;
    }
    currNode->next = newNode;

    printf("Amazing! A new node with the value %d has been inserted at the end of the list.\n", data);
}

// Delete the first node with the specified data from the list.
void deleteNode(Node** head, int data) {
    // If the list is empty, return.
    if (*head == NULL) {
        printf("Oops! The list is empty. Nothing to delete.\n");
        return;
    }

    // If the node to delete is the head, update the head to be the next node.
    if ((*head)->data == data) {
        Node* temp = *head;
        *head = (*head)->next;
        free(temp);
        printf("Hooray! The first node with the value %d has been deleted.\n", data);
        return;
    }

    // Otherwise, iterate over the list and delete the node.
    Node* currNode = *head;
    while (currNode->next != NULL && currNode->next->data != data) {
        currNode = currNode->next;
    }
    if (currNode->next == NULL) {
        printf("Oops! The node with the value %d was not found in the list.\n", data);
        return;
    }
    Node* temp = currNode->next;
    currNode->next = currNode->next->next;
    free(temp);
    printf("Great! The first node with the value %d has been deleted.\n", data);
}

// Print the values of all nodes in the list.
void printList(Node* head) {
    // If the list is empty, return.
    if (head == NULL) {
        printf("Oops! The list is empty. Nothing to print.\n");
        return;
    }

    // Otherwise, iterate over the list and print the data in each node.
    printf("Here are the values of all nodes in the list:\n");
    Node* currNode = head;
    while (currNode != NULL) {
        printf("%d ", currNode->data);
        currNode = currNode->next;
    }
    printf("\n");
}

int main() {
    // Initialize an empty linked list.
    Node* head = NULL;

    // Insert some nodes into the list.
    insertFront(&head, 1);
    insertFront(&head, 2);
    insertEnd(&head, 3);
    insertEnd(&head, 4);
    insertFront(&head, 5);

    // Print the values of all nodes in the list.
    printList(head);

    // Delete some nodes from the list.
    deleteNode(&head, 2);
    deleteNode(&head, 6);
    deleteNode(&head, 5);

    // Print the values of all nodes in the list again (should have changed).
    printList(head);

    // Free the memory allocated for all nodes in the list.
    Node* currNode = head;
    while (currNode != NULL) {
        Node* temp = currNode;
        currNode = currNode->next;
        free(temp);
    }

    printf("Thanks for playing with our happy linked list program!\n");
    return 0;
}