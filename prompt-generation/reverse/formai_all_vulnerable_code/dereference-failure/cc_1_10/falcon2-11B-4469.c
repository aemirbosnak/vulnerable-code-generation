//Falcon2-11B DATASET v1.0 Category: Data structures visualization ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

// Define a struct to hold the data
typedef struct {
    int value;
    struct node *next;
} Node;

// Function to create a new node
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new node at the beginning of the list
void insertNodeAtBeginning(Node** head, int value) {
    Node* newNode = createNode(value);
    *head = newNode;
}

// Function to insert a new node at the end of the list
void insertNodeAtEnd(Node** head, int value) {
    Node* newNode = createNode(value);
    Node* current = *head;
    while (current->next!= NULL) {
        current = current->next;
    }
    current->next = newNode;
}

// Function to print the list
void printList(Node* head) {
    Node* current = head;
    while (current!= NULL) {
        printf("%d ", current->value);
        current = current->next;
    }
    printf("\n");
}

int main() {
    Node* head = NULL;
    
    // Insert a few nodes at the beginning of the list
    insertNodeAtBeginning(&head, 1);
    insertNodeAtBeginning(&head, 2);
    insertNodeAtBeginning(&head, 3);
    insertNodeAtBeginning(&head, 4);
    insertNodeAtBeginning(&head, 5);
    
    // Insert a few nodes at the end of the list
    insertNodeAtEnd(&head, 6);
    insertNodeAtEnd(&head, 7);
    insertNodeAtEnd(&head, 8);
    insertNodeAtEnd(&head, 9);
    insertNodeAtEnd(&head, 10);
    
    // Print the list
    printList(head);
    
    return 0;
}