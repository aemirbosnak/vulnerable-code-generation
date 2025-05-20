//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node in the linked list
typedef struct node {
    int data;
    struct node* next;
} Node;

// Function to create a new node with given data
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory error\n");
        exit(0);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new node at the beginning of the list
void insertAtBeginning(Node** headRef, int data) {
    Node* newNode = createNode(data);
    newNode->next = *headRef;
    *headRef = newNode;
}

// Function to insert a new node at the end of the list
void insertAtEnd(Node** headRef, int data) {
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

// Function to insert a new node at a given position in the list
void insertAtPosition(Node** headRef, int data, int position) {
    Node* newNode = createNode(data);
    Node* tempNode = *headRef;
    int currentPosition = 1;
    if (position == 1) {
        newNode->next = tempNode;
        *headRef = newNode;
        return;
    }
    while (tempNode!= NULL && currentPosition < position - 1) {
        tempNode = tempNode->next;
        currentPosition++;
    }
    newNode->next = tempNode->next;
    tempNode->next = newNode;
}

// Function to delete a node with given data from the list
void deleteNode(Node** headRef, int data) {
    Node* tempNode = *headRef;
    Node* prevNode = NULL;
    if (*headRef!= NULL && (*headRef)->data == data) {
        *headRef = (*headRef)->next;
        free(tempNode);
        return;
    }
    while (tempNode!= NULL && tempNode->data!= data) {
        prevNode = tempNode;
        tempNode = tempNode->next;
    }
    if (tempNode == NULL) {
        return;
    }
    prevNode->next = tempNode->next;
    free(tempNode);
}

// Function to print the list
void printList(Node* head) {
    while (head!= NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// Main function
int main() {
    Node* head = NULL;
    insertAtBeginning(&head, 10);
    insertAtBeginning(&head, 20);
    insertAtEnd(&head, 30);
    insertAtPosition(&head, 15, 2);
    printList(head);
    deleteNode(&head, 10);
    deleteNode(&head, 30);
    printList(head);
    return 0;
}