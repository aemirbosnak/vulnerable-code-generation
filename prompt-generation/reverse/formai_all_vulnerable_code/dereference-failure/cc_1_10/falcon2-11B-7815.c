//Falcon2-11B DATASET v1.0 Category: Database simulation ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node structure for the linked list
typedef struct node {
    char data[100];
    struct node *next;
} Node;

// Linked list to simulate the database
Node *head = NULL;

void addNode(char data[]) {
    // Allocate memory for a new node
    Node *newNode = (Node*)malloc(sizeof(Node));
    
    // Copy the data into the node
    strcpy(newNode->data, data);
    
    // Make the new node point to the next node in the list
    newNode->next = NULL;
    
    // Add the new node to the end of the list
    if (head == NULL) {
        head = newNode;
    } else {
        Node *temp = head;
        while (temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void displayList() {
    Node *temp = head;
    while (temp!= NULL) {
        printf("%s\n", temp->data);
        temp = temp->next;
    }
}

int main() {
    // Add some nodes to the database
    addNode("Apple");
    addNode("Banana");
    addNode("Orange");
    addNode("Mango");
    addNode("Grape");
    
    // Display the contents of the database
    displayList();
    
    return 0;
}