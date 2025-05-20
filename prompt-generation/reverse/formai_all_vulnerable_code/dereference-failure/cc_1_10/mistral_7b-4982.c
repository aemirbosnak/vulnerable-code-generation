//MISTRAL-7B DATASET v1.0 Category: Linked list operations ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the linked list
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Initialize the head pointer to NULL
Node* head = NULL;

// Function to check if the list is empty
int isEmpty() {
    return head == NULL;
}

// Function to insert a new node at the beginning of the list
void insertAtBeginning(int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = head;
    head = newNode;
}

// Function to delete the first node from the list
void deleteAtBeginning() {
    Node* temp = head;
    head = head->next;
    free(temp);
}

// Function to print the elements in the list
void printList() {
    Node* currentNode = head;
    while (currentNode != NULL) {
        printf("%d -> ", currentNode->data);
        currentNode = currentNode->next;
    }
    printf("NULL\n");
}

// Function to reverse the linked list
void reverseList() {
    Node* prevNode = NULL;
    Node* currentNode = head;

    while (currentNode != NULL) {
        Node* nextNode = currentNode->next;
        currentNode->next = prevNode;
        prevNode = currentNode;
        currentNode = nextNode;
    }

    head = prevNode;
}

int main() {
    // Test the functions
    insertAtBeginning(3);
    insertAtBeginning(2);
    insertAtBeginning(1);
    printList(); // Output: 1 -> 2 -> 3 -> NULL

    deleteAtBeginning();
    printList(); // Output: 2 -> 3 -> NULL

    reverseList();
    printList(); // Output: 3 -> 2 -> 1 -> NULL

    deleteAtBeginning();
    printList(); // Output: 2 -> 1 -> NULL

    return 0;
}