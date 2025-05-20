//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of a node in the linked list
typedef struct node {
    int data;
    struct node* next;
} Node;

// Function prototypes
Node* createNode(int data);
void appendNode(Node** head, int data);
void prependNode(Node** head, int data);
void deleteNode(Node** head, int data);
void printList(Node* head);

// Function to create a new node with the given data
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to append a new node to the end of the list
void appendNode(Node** head, int data) {
    Node* newNode = createNode(data);
    Node* temp = *head;

    // If the list is empty, set the new node as the head
    if (*head == NULL) {
        newNode->next = NULL;
        *head = newNode;
        return;
    }

    // Traverse the list until the last node is reached
    while (temp->next!= NULL) {
        temp = temp->next;
    }

    // Append the new node to the end of the list
    temp->next = newNode;
    newNode->next = NULL;
}

// Function to prepend a new node to the beginning of the list
void prependNode(Node** head, int data) {
    Node* newNode = createNode(data);
    Node* temp = *head;

    // If the list is empty, set the new node as the head
    if (*head == NULL) {
        newNode->next = NULL;
        *head = newNode;
        return;
    }

    // Set the new node as the head
    newNode->next = *head;
    *head = newNode;
}

// Function to delete a node with the given data from the list
void deleteNode(Node** head, int data) {
    Node* temp = *head;
    Node* prev = NULL;

    // If the list is empty, return
    if (*head == NULL) {
        return;
    }

    // If the first node contains the data, delete it and update the head
    if (temp->data == data) {
        *head = temp->next;
        free(temp);
        return;
    }

    // Traverse the list until the node with the given data is found
    while (temp!= NULL) {
        if (temp->data == data) {
            if (prev == NULL) {
                *head = temp->next;
            } else {
                prev->next = temp->next;
            }
            free(temp);
            return;
        }
        prev = temp;
        temp = temp->next;
    }
}

// Function to print the contents of the list
void printList(Node* head) {
    Node* temp = head;
    printf("List: ");
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main function
int main() {
    Node* head = NULL;

    // Test appending nodes to the list
    appendNode(&head, 1);
    appendNode(&head, 2);
    appendNode(&head, 3);
    printList(head);

    // Test prepending nodes to the list
    prependNode(&head, 0);
    prependNode(&head, -1);
    printList(head);

    // Test deleting nodes from the list
    deleteNode(&head, 0);
    deleteNode(&head, 2);
    printList(head);

    return 0;
}