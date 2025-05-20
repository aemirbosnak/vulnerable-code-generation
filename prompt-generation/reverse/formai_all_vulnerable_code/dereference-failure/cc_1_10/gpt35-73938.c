//FormAI DATASET v1.0 Category: Data structures visualization ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

// Define a struct called "Node" to represent a node in our linked list
typedef struct Node {
    int data;           // The data stored in the node
    struct Node* next;  // A pointer to the next node in the list
} Node;

// Define a function that inserts a new node at the beginning of a linked list
void insertAtBeginning(Node** headRef, int data) {
    // Allocate memory for a new node
    Node* newNode = (Node*) malloc(sizeof(Node));
    
    // Set the data of the new node to the given data
    newNode->data = data;
    
    // Set the next pointer of the new node to the current head of the list
    newNode->next = *headRef;
    
    // Set the head of the list to the new node
    *headRef = newNode;
}

// Define a function that prints the contents of a linked list
void printList(Node* head) {
    Node* currentNode = head;
    
    printf("List: ");
    
    while (currentNode != NULL) {
        printf("%d ", currentNode->data);
        currentNode = currentNode->next;
    }
    
    printf("\n");
}

int main() {
    // Declare a variable to represent the head of our linked list
    Node* head = NULL;
    
    // Insert some nodes at the beginning of the list
    insertAtBeginning(&head, 5);
    insertAtBeginning(&head, 10);
    insertAtBeginning(&head, 15);
    
    // Print the contents of the list
    printList(head);
    
    // Exit the program
    return 0;
}