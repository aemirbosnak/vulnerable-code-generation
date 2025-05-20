//FormAI DATASET v1.0 Category: Linked list operations ; Style: innovative
// Unique Linked List Operations program using C Programming

#include <stdio.h>
#include <stdlib.h>

// Linked list node
struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;     // Declare head node initially null

// Function to insert data at the beginning of the linked list
void insertAtBeginning(int data) {
    struct node *newNode = (struct node*) malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = head;
    head = newNode;
}

// Function to insert data at the end of the linked list
void insertAtEnd(int data) {
    struct node *newNode = (struct node*) malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    if(head == NULL) {
        head = newNode;
        return;
    }
    struct node *currentNode = head;
    while(currentNode->next != NULL) {
        currentNode = currentNode->next;
    }
    currentNode->next = newNode;
}

// Function to delete data from the beginning of the linked list
void deleteFromBeginning() {
    if(head == NULL) {
        printf("The list is already empty!");
    } else {
        struct node *temp = head;
        head = head->next;
        free(temp);
    }
}

// Function to delete data from the end of the linked list
void deleteFromEnd() {
    if(head == NULL) {
        printf("The list is already empty!");
    } else if(head->next == NULL) {
        head = NULL;
    } else {
        struct node *currentNode = head;
        struct node *nextNode = currentNode->next;
        while(nextNode->next != NULL) {
            currentNode = nextNode;
            nextNode = nextNode->next;
        }
        currentNode->next = NULL;
        free(nextNode);
    }
}

// Function to display the linked list
void displayList() {
    struct node *currentNode = head;
    if(currentNode == NULL) {
        printf("The list is empty!");
    } else {
        printf("The linked list is: ");
        while(currentNode != NULL) {
            printf("%d ", currentNode->data);
            currentNode = currentNode->next;
        }
    }
}

// Main function to test the Linked List Operations
int main() {
    insertAtBeginning(10); // Insert data at the beginning of the linked list
    insertAtEnd(20);      // Insert data at the end of the linked list
    insertAtBeginning(30); // Insert data at the beginning of the linked list
    insertAtEnd(40);      // Insert data at the end of the linked list
    deleteFromBeginning(); // Delete data from the beginning of the linked list
    deleteFromEnd();       // Delete data from the end of the linked list
    displayList();         // Display the linked list
    
    return 0;  // return statement
}