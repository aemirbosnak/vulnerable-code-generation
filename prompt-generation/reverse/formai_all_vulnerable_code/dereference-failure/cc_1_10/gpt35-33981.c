//FormAI DATASET v1.0 Category: Memory management ; Style: interoperable
#include <stdlib.h>
#include <stdio.h>

// Define linked list structure
typedef struct node {
    int data;
    struct node *next;
} Node;

// Declare global variables
Node *head = NULL;
Node *tail = NULL;

// Function to add a new node to the end of the linked list
void addNode(int data) {
    Node *newNode = malloc(sizeof(Node)); // Allocate memory for new node
    newNode->data = data;
    newNode->next = NULL;

    // If head is null, set new node as head and tail
    if (head == NULL) {
        head = newNode;
        tail = newNode;
    } 
    // Otherwise, add new node to end of list
    else {
        tail->next = newNode;
        tail = newNode;
    }
}

// Function to remove a node from the linked list
void removeNode(int data) {
    Node *curNode = head;
    Node *prevNode = NULL;

    while (curNode != NULL && curNode->data != data) {
        prevNode = curNode;
        curNode = curNode->next;
    }

    // If node is found, remove it from list
    if (curNode != NULL) {
        if (curNode == head) {
            head = curNode->next;
        } else if (curNode == tail) {
            prevNode->next = NULL;
            tail = prevNode;
        } else {
            prevNode->next = curNode->next;
        }

        free(curNode); // Free memory for removed node
    }
}

// Function to display the linked list
void displayList() {
    Node *curNode = head;

    printf("Linked List: ");

    while (curNode != NULL) {
        printf("%d ", curNode->data);
        curNode = curNode->next;
    }

    printf("\n");
}

int main() {
    // Add some nodes to the list
    addNode(1);
    addNode(2);
    addNode(3);
    addNode(4);
    addNode(5);

    // Display the list
    displayList();

    // Remove some nodes from the list
    removeNode(3);
    removeNode(5);

    // Display the list again
    displayList();
    
    return 0;
}