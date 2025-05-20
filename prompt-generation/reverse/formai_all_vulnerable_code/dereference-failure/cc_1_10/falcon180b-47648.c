//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

// Node structure for linked list
typedef struct node {
    char data[MAX_SIZE];
    struct node* next;
} Node;

// Function to create a new node
Node* createNode(char* data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->data, data);
    newNode->next = NULL;
    return newNode;
}

// Function to search for a node in the list
Node* search(Node* head, char* target) {
    Node* currNode = head;
    while (currNode!= NULL) {
        if (strcmp(currNode->data, target) == 0) {
            return currNode;
        }
        currNode = currNode->next;
    }
    return NULL;
}

// Function to print the list
void printList(Node* head) {
    Node* currNode = head;
    while (currNode!= NULL) {
        printf("%s -> ", currNode->data);
        currNode = currNode->next;
    }
    printf("NULL\n");
}

// Main function
int main() {
    // Create a new list
    Node* head = NULL;
    head = createNode("apple");
    head->next = createNode("banana");
    head->next->next = createNode("cherry");
    head->next->next->next = createNode("date");

    // Print the list
    printList(head);

    // Search for a node
    Node* targetNode = search(head, "banana");
    if (targetNode!= NULL) {
        printf("Found node with data: %s\n", targetNode->data);
    } else {
        printf("Node not found.\n");
    }

    return 0;
}