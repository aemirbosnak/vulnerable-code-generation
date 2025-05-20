//FormAI DATASET v1.0 Category: Data structures visualization ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

// Define a struct, representing a node of a singly linked list
typedef struct node {
    int data;
    struct node* next;
} Node;

// Define a function to create a node
Node* createNode(int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Define a function to insert a new node at the beginning of the list
Node* insertAtBeginning(Node* head, int data) {
    Node* newNode = createNode(data);
    if(head == NULL) {
        head = newNode;
    } else {
        newNode->next = head;
        head = newNode;
    }
    return head;
}

// Define a function to print the linked list
void printList(Node* head) {
    Node* temp = head;
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// The main function
int main() {

    // Create an empty list
    Node* head = NULL;

    // Insert some nodes
    head = insertAtBeginning(head, 4);
    head = insertAtBeginning(head, 3);
    head = insertAtBeginning(head, 2);
    head = insertAtBeginning(head, 1);

    // Print the list
    printList(head);

    return 0;
}