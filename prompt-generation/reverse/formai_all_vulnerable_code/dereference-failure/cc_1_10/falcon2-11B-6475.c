//Falcon2-11B DATASET v1.0 Category: Data structures visualization ; Style: safe
#include <stdio.h>
#include <stdlib.h>

// Struct definition for a node in a linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node and insert it at the front of the linked list
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to add a node to the front of the linked list
void addToFront(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

// Function to print the elements of the linked list
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main function
int main() {
    // Create a new linked list
    struct Node* head = NULL;

    // Add some nodes to the front of the linked list
    addToFront(&head, 10);
    addToFront(&head, 20);
    addToFront(&head, 30);
    addToFront(&head, 40);
    addToFront(&head, 50);

    // Print the elements of the linked list
    printf("Linked list: ");
    printList(head);

    return 0;
}