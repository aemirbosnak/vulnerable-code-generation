//FormAI DATASET v1.0 Category: Linked list operations ; Style: careful
#include <stdio.h>
#include <stdlib.h>

// Define the structure of each node in the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to insert a new node at the head of the linked list
void insertAtHead(struct Node** headRef, int newData) {
    // Allocate memory for the new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    // Assign the data for the new node
    newNode->data = newData;
    // Make the new node point to the current head of the list
    newNode->next = *headRef;
    // Update the head of the list to point to the new node
    *headRef = newNode;
}

// Function to insert a new node at the end of the linked list
void insertAtTail(struct Node** headRef, int newData) {
    // Allocate memory for the new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    // Assign the data for the new node
    newNode->data = newData;
    // Make the new node point to NULL since it will be the new tail
    newNode->next = NULL;
    // If the list is currently empty, make the new node the head of the list
    if (*headRef == NULL) {
        *headRef = newNode;
    }
    // Otherwise, traverse to the end of the list and insert the new node there
    else {
        // Create a temporary node to traverse the list
        struct Node* tempNode = *headRef;
        while (tempNode->next != NULL) {
            tempNode = tempNode->next;
        }
        tempNode->next = newNode;
    }
}

// Function to remove the first occurrence of a given value from the linked list
void removeNode(struct Node** headRef, int key) {
    // If the list is empty, there is nothing to remove
    if (*headRef == NULL) {
        return;
    }
    // If the head node contains the key, remove it and update the head
    if ((*headRef)->data == key) {
        struct Node* tempNode = *headRef;
        *headRef = (*headRef)->next;
        free(tempNode);
        return;
    }
    // Traverse the list and find the node with the key
    struct Node* prevNode = NULL;
    struct Node* currNode = *headRef;
    while (currNode != NULL && currNode->data != key) {
        prevNode = currNode;
        currNode = currNode->next;
    }
    // If the key is found, remove the node and update the previous node
    if (currNode != NULL) {
        prevNode->next = currNode->next;
        free(currNode);
        return;
    }
}

// Function to print the linked list
void printList(struct Node* head) {
    struct Node* tempNode = head;
    while (tempNode != NULL) {
        printf("%d ", tempNode->data);
        tempNode = tempNode->next;
    }
    printf("\n");
}

int main() {
    // Initialize an empty linked list
    struct Node* head = NULL;

    // Insert some nodes into the list
    insertAtHead(&head, 5);
    insertAtHead(&head, 10);
    insertAtTail(&head, 15);
    insertAtHead(&head, 20);
    insertAtTail(&head, 25);

    // Print the current state of the list
    printf("Initial linked list:\n");
    printList(head);

    // Remove a node from the list
    removeNode(&head, 10);

    // Print the updated state of the list
    printf("Linked list after removing 10:\n");
    printList(head);

    // Remove another node from the list
    removeNode(&head, 25);

    // Print the final state of the list
    printf("Final linked list:\n");
    printList(head);

    // Free the memory allocated for the nodes in the list
    struct Node* tempNode = head;
    while (tempNode != NULL) {
        struct Node* nextNode = tempNode->next;
        free(tempNode);
        tempNode = nextNode;
    }

    return 0;
}