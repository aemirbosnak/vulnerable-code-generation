//Falcon-180B DATASET v1.0 Category: Warehouse Management System ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 1000

// Node structure for linked list
typedef struct node {
    char data[50];
    struct node* next;
} Node;

// Function prototypes
void addNode(Node** head, char* data);
void printList(Node* head);
void searchList(Node* head, char* searchData);
void deleteNode(Node** head, char* data);

int main() {
    Node* head = NULL;

    // Add nodes to the list
    addNode(&head, "Apple");
    addNode(&head, "Banana");
    addNode(&head, "Cherry");
    addNode(&head, "Date");

    // Print the list
    printf("Original List:\n");
    printList(head);

    // Search for a node
    searchList(head, "Banana");

    // Delete a node
    deleteNode(&head, "Date");

    // Print the updated list
    printf("\nUpdated List:\n");
    printList(head);

    return 0;
}

// Function to add a node to the list
void addNode(Node** head, char* data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->data, data);
    newNode->next = *head;
    *head = newNode;
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

// Function to search for a node
void searchList(Node* head, char* searchData) {
    Node* currNode = head;
    while (currNode!= NULL) {
        if (strcmp(currNode->data, searchData) == 0) {
            printf("Node found: %s\n", currNode->data);
            return;
        }
        currNode = currNode->next;
    }
    printf("Node not found.\n");
}

// Function to delete a node
void deleteNode(Node** head, char* data) {
    Node* currNode = *head;
    Node* prevNode = NULL;

    // Find the node to be deleted
    while (currNode!= NULL && strcmp(currNode->data, data)!= 0) {
        prevNode = currNode;
        currNode = currNode->next;
    }

    // If node not found, return
    if (currNode == NULL) {
        return;
    }

    // Unlink the node from the list
    if (prevNode == NULL) {
        *head = currNode->next;
    } else {
        prevNode->next = currNode->next;
    }

    free(currNode);
}