//Falcon2-11B DATASET v1.0 Category: Data structures visualization ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct to represent a node in a linked list
struct Node {
    int data;
    struct Node* next;
};

// Define a function to create a new node with the given data
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Define a function to print the elements of a linked list
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    
    // Create a new node with data 10
    struct Node* newNode10 = createNode(10);
    
    // Create a new node with data 20
    struct Node* newNode20 = createNode(20);
    
    // Create a new node with data 30
    struct Node* newNode30 = createNode(30);
    
    // Link the new nodes together
    newNode10->next = newNode20;
    newNode20->next = newNode30;
    
    // Print the elements of the linked list
    printList(head);
    
    // Free the memory allocated for the linked list
    struct Node* temp = head;
    while (temp!= NULL) {
        struct Node* nextTemp = temp->next;
        free(temp);
        temp = nextTemp;
    }
    
    return 0;
}