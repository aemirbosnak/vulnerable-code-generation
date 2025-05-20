//FormAI DATASET v1.0 Category: Linked list operations ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>

// Define the Node data structure
struct Node {
    int data;
    struct Node* next;
};

// Global variable to store the head node of the linked list
struct Node* head;

// Function to insert a node at the beginning of the linked list
void insertAtBeginning(int data) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = head;
    head = newNode;
}

// Function to insert a node at the end of the linked list
void insertAtEnd(int data) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    if (head == NULL) {
        head = newNode;
        return;
    }
    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to insert a node at a specific position in the linked list
void insertAtPosition(int data, int position) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    if (position == 1) {
        newNode->next = head;
        head = newNode;
        return;
    }
    struct Node* temp = head;
    for (int i = 1; i < position - 1; i++) {
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

// Function to delete a node from the linked list
void deleteNode(int data) {
    if (head == NULL) {
        return;
    }
    if (head->data == data) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
        return;
    }
    struct Node* temp = head;
    while (temp->next->data != data) {
        temp = temp->next;
    }
    struct Node* temp2 = temp->next;
    temp->next = temp2->next;
    free(temp2);
}

// Function to print the linked list
void printList() {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main function to test the above functions
int main() {
    head = NULL;
    insertAtBeginning(10);
    insertAtEnd(20);
    insertAtPosition(15, 2);
    deleteNode(20);
    printList();
    return 0;
}