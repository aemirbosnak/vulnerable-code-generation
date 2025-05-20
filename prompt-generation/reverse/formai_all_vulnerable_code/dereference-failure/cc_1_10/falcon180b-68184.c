//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the node structure for our linked list
typedef struct Node {
    char data;
    struct Node* next;
} Node;

// Function to create a new node with given data
Node* createNode(char data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Error: Memory could not be allocated.\n");
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to add a node at the end of the list
void addNode(Node** headRef, char data) {
    Node* newNode = createNode(data);
    Node* lastNode = *headRef;
    if (*headRef == NULL) {
        newNode->next = NULL;
        *headRef = newNode;
        return;
    }
    while (lastNode->next!= NULL) {
        lastNode = lastNode->next;
    }
    lastNode->next = newNode;
}

// Function to delete a node with given data
void deleteNode(Node** headRef, char data) {
    Node* tempNode = *headRef;
    Node* prevNode = NULL;
    if (tempNode!= NULL && tempNode->data == data) {
        *headRef = tempNode->next;
        free(tempNode);
        return;
    }
    while (tempNode!= NULL && tempNode->data!= data) {
        prevNode = tempNode;
        tempNode = tempNode->next;
    }
    if (tempNode == NULL) {
        printf("Node not found.\n");
        return;
    }
    prevNode->next = tempNode->next;
    free(tempNode);
}

// Function to display the list
void displayList(Node* head) {
    Node* currentNode = head;
    while (currentNode!= NULL) {
        printf("%c -> ", currentNode->data);
        currentNode = currentNode->next;
    }
    printf("NULL\n");
}

// Main function
int main() {
    Node* head = NULL;
    addNode(&head, 'A');
    addNode(&head, 'B');
    addNode(&head, 'C');
    displayList(head);
    deleteNode(&head, 'B');
    displayList(head);
    deleteNode(&head, 'A');
    displayList(head);
    deleteNode(&head, 'C');
    displayList(head);
    return 0;
}