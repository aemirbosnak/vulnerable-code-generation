//FormAI DATASET v1.0 Category: Data structures visualization ; Style: scalable
#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in a singly linked list
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function to create a new node with the given data
Node* createNode(int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the beginning of the linked list
void insertAtBeginning(Node** headRef, int data) {
    Node* newNode = createNode(data);
    newNode->next = *headRef;
    *headRef = newNode;
}

// Function to insert a node at the end of the linked list
void insertAtEnd(Node** headRef, int data) {
    Node* newNode = createNode(data);
    Node* currNode = *headRef;
    if(currNode == NULL) {
        // If list is empty, set the new node as head
        *headRef = newNode;
        return;
    }
    while(currNode->next != NULL) {
        currNode = currNode->next;
    }
    currNode->next = newNode;
}

// Function to remove a node with the given data from the linked list
void removeNode(Node** headRef, int data) {
    Node* currNode = *headRef;

    if(currNode == NULL) {
        // If list is empty, no node to remove
        return;
    }
    if(currNode->data == data) {
        // If head node has the data to be removed, remove it and set the next node as head
        *headRef = currNode->next;
        free(currNode);
        return;
    }

    while(currNode->next != NULL) {
        if(currNode->next->data == data) {
            // If the data to be removed is found, remove the node and set the current node's next as next of the removed node
            Node* removedNode = currNode->next;
            currNode->next = removedNode->next;
            free(removedNode);
            return;
        }
        currNode = currNode->next;
    }
}

// Function to print the linked list
void printList(Node* head) {
    Node* currNode = head;
    while(currNode != NULL) {
        printf("%d -> ", currNode->data);
        currNode = currNode->next;
    }
    printf("NULL\n");
}

int main() {
    Node* head = NULL;

    insertAtBeginning(&head, 5);
    insertAtBeginning(&head, 10);
    insertAtEnd(&head, 15);
    insertAtEnd(&head, 20);
    removeNode(&head, 5);
    printList(head);

    return 0;
}