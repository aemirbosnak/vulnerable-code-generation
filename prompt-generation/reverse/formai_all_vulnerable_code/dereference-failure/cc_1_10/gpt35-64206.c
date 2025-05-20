//FormAI DATASET v1.0 Category: Data structures visualization ; Style: safe
#include <stdio.h>
#include <stdlib.h>

// Structure to hold the node of the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new node at the beginning
void insertAtBeginning(struct Node** headRef, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *headRef;
    *headRef = newNode;
}

// Function to insert a new node at the end
void insertAtEnd(struct Node** headRef, int data) {
    struct Node* newNode = createNode(data);
    if (*headRef == NULL) {
        *headRef = newNode;
        return;
    }
    struct Node* currentNode = *headRef;
    while (currentNode->next != NULL) {
        currentNode = currentNode->next;
    }
    currentNode->next = newNode;
}

// Function to delete the first occurrence of a node
void deleteNode(struct Node** headRef, int data) {
    if (*headRef == NULL) {
        return;
    }
    if ((*headRef)->data == data) {
        *headRef = (*headRef)->next;
        return;
    }
    struct Node* currentNode = *headRef;
    while (currentNode->next != NULL && currentNode->next->data != data) {
        currentNode = currentNode->next;
    }
    if (currentNode->next == NULL) {
        return;
    }
    struct Node* temp = currentNode->next;
    currentNode->next = temp->next;
    free(temp);
}

// Function to print the linked list
void printLinkedList(struct Node* head) {
    struct Node* currentNode = head;
    while (currentNode != NULL) {
        printf("%d ", currentNode->data);
        currentNode = currentNode->next;
    }
    printf("\n");
}

// Main function
int main() {
    struct Node* head = NULL;
    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);
    insertAtBeginning(&head, 5);
    insertAtBeginning(&head, 2);
    printLinkedList(head);
    deleteNode(&head, 20);
    printLinkedList(head);
    deleteNode(&head, 5);
    printLinkedList(head);
    deleteNode(&head, 40);
    printLinkedList(head);
    return 0;
}