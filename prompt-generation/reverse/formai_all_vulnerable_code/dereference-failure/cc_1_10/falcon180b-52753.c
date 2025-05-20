//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

// Define the node structure
typedef struct node {
    int data;
    struct node* next;
} Node;

// Function prototypes
void addNode(Node** head, int data);
void printList(Node* head);
void deleteNode(Node** head, int data);
void reverseList(Node** head);

int main() {
    Node* head = NULL;

    // Add nodes to the list
    addNode(&head, 10);
    addNode(&head, 20);
    addNode(&head, 30);
    addNode(&head, 40);

    // Print the list
    printf("Original List:\n");
    printList(head);

    // Delete a node
    deleteNode(&head, 20);

    // Print the updated list
    printf("\nList after deleting node with value 20:\n");
    printList(head);

    // Reverse the list
    reverseList(&head);

    // Print the reversed list
    printf("\nReversed List:\n");
    printList(head);

    return 0;
}

// Function to add a node to the list
void addNode(Node** head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

// Function to print the list
void printList(Node* head) {
    Node* currNode = head;
    while (currNode!= NULL) {
        printf("%d ", currNode->data);
        currNode = currNode->next;
    }
    printf("\n");
}

// Function to delete a node
void deleteNode(Node** head, int data) {
    Node* currNode = *head;
    Node* prevNode = NULL;

    while (currNode!= NULL && currNode->data!= data) {
        prevNode = currNode;
        currNode = currNode->next;
    }

    if (currNode == NULL) {
        printf("Node with value %d not found in the list.\n", data);
        return;
    }

    if (prevNode == NULL) {
        *head = currNode->next;
    } else {
        prevNode->next = currNode->next;
    }

    free(currNode);
}

// Function to reverse the list
void reverseList(Node** head) {
    Node* currNode = *head;
    Node* prevNode = NULL;
    Node* nextNode = NULL;

    while (currNode!= NULL) {
        nextNode = currNode->next;
        currNode->next = prevNode;
        prevNode = currNode;
        currNode = nextNode;
    }

    *head = prevNode;
}