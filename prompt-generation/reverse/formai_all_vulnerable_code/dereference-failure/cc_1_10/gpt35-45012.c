//FormAI DATASET v1.0 Category: Linked list operations ; Style: secure
#include <stdio.h>
#include <stdlib.h>

// Define the linked list structure
typedef struct node {
    int data;
    struct node* next;
} Node;

Node* head = NULL;

// Function to insert a new node at the beginning of the linked list
void insertAtBeginning(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = head;
    head = newNode;
}

// Function to insert a new node at the end of the linked list
void insertAtEnd(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    if (head == NULL) {
        head = newNode;
        return;
    }
    Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
}

// Function to delete a node from the linked list by value
void deleteNode(int data) {
    Node* current = head;
    Node* prev = NULL;
    if (current != NULL && current->data == data) {
        head = current->next;
        free(current);
        return;
    }
    while (current != NULL && current->data != data) {
        prev = current;
        current = current->next;
    }
    if (current == NULL) {
        printf("Value not found in the linked list!\n");
        return;
    }
    prev->next = current->next;
    free(current);
}

// Function to print the linked list
void printLinkedList() {
    printf("Linked List: ");
    Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    // Insert nodes at the beginning of the list
    insertAtBeginning(2);
    insertAtBeginning(1);
    printLinkedList();

    // Insert nodes at the end of the list
    insertAtEnd(3);
    insertAtEnd(4);
    printLinkedList();

    // Delete a node from the list
    deleteNode(3);
    printLinkedList();

    return 0;
}