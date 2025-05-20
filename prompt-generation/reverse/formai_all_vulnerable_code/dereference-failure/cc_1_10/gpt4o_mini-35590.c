//GPT-4o-mini DATASET v1.0 Category: Linked list operations ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int data;
    char name[50];
    struct Node* next;
} Node;

Node* head = NULL;

// Function to create a new node
Node* createNode(int data, const char* name) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    strcpy(newNode->name, name);
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end
void insertEnd(int data, const char* name) {
    Node* newNode = createNode(data, name);
    if (head == NULL) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to insert a node at the beginning
void insertBeginning(int data, const char* name) {
    Node* newNode = createNode(data, name);
    newNode->next = head;
    head = newNode;
}

// Function to display the linked list
void displayList() {
    Node* temp = head;
    while (temp != NULL) {
        printf("Data: %d, Name: %s\n", temp->data, temp->name);
        temp = temp->next;
    }
}

// Function to delete a node by data
void deleteNode(int data) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    Node* temp = head;
    Node* prev = NULL;

    // Check if head needs to be deleted
    if (temp != NULL && temp->data == data) {
        head = temp->next;
        free(temp);
        return;
    }

    // Traverse the list to find the node to delete
    while (temp != NULL && temp->data != data) {
        prev = temp;
        temp = temp->next;
    }

    // If data was not found
    if (temp == NULL) {
        printf("Data %d not found in the list.\n", data);
        return;
    }

    // Unlink the node from the linked list
    prev->next = temp->next;
    free(temp);
}

// Function to free the entire linked list
void freeList() {
    Node* temp = head;
    while (temp != NULL) {
        Node* nextNode = temp->next;
        free(temp);
        temp = nextNode;
    }
    head = NULL;
}

// Function to search for a node by data
void searchNode(int data) {
    Node* temp = head;
    while (temp != NULL) {
        if (temp->data == data) {
            printf("Found Node - Data: %d, Name: %s\n", temp->data, temp->name);
            return;
        }
        temp = temp->next;
    }
    printf("Data %d not found in the list.\n", data);
}

// Main function
int main() {
    insertEnd(1, "NodeOne");
    insertEnd(2, "NodeTwo");
    insertBeginning(0, "NodeZero");
    
    printf("Current Linked List:\n");
    displayList();

    searchNode(1);
    searchNode(3);

    deleteNode(2);
    printf("\nLinked List after deleting Node with data 2:\n");
    displayList();

    freeList();
    printf("\nLinked List after freeing all nodes:\n");
    displayList(); // Should display nothing as the list is freed.

    return 0;
}