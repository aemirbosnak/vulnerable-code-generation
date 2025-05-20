//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the maximum size of the array
#define MAX_SIZE 1000

// Node structure for linked list
typedef struct node {
    int data;
    struct node* next;
} Node;

// Function to create a new node with given data
Node* createNode(int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory error\n");
        exit(0);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to add a node at the end of the list
void addNode(Node** head, int data) {
    Node* newNode = createNode(data);
    Node* temp = *head;
    if (*head == NULL) {
        newNode->next = NULL;
        *head = newNode;
    } else {
        while (temp->next!= NULL)
            temp = temp->next;
        temp->next = newNode;
    }
}

// Function to search for a node with given data
Node* searchNode(Node* head, int data) {
    Node* current = head;
    while (current!= NULL) {
        if (current->data == data)
            return current;
        current = current->next;
    }
    return NULL;
}

// Function to print the linked list
void printList(Node* head) {
    Node* temp = head;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Node* head = NULL;

    // Add nodes to the list
    addNode(&head, 1);
    addNode(&head, 2);
    addNode(&head, 3);
    addNode(&head, 4);
    addNode(&head, 5);

    // Print the initial list
    printf("Initial List:\n");
    printList(head);

    // Search for a node with given data
    Node* result = searchNode(head, 4);
    if (result!= NULL)
        printf("Node found with data %d\n", result->data);
    else
        printf("Node not found\n");

    return 0;
}