//Falcon-180B DATASET v1.0 Category: Warehouse Management System ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

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

// Function to add a node to the end of the list
void addNode(Node** head, char* data) {
    Node* newNode = createNode(data);
    Node* temp = *head;

    if (*head == NULL) {
        newNode->next = NULL;
        *head = newNode;
        return;
    }

    while (temp->next!= NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
}

// Function to search for a node with the given data
Node* searchNode(Node* head, char* data) {
    Node* temp = head;

    while (temp!= NULL) {
        if (strcmp(temp->data, data) == 0) {
            return temp;
        }
        temp = temp->next;
    }

    return NULL;
}

// Function to delete a node with the given data
void deleteNode(Node** head, char* data) {
    Node* temp = *head;
    Node* prev = NULL;

    if (temp!= NULL && strcmp(temp->data, data) == 0) {
        *head = temp->next;
        free(temp);
        return;
    }

    while (temp!= NULL && strcmp(temp->data, data)!= 0) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        return;
    }

    prev->next = temp->next;
    free(temp);
}

// Function to print the list
void printList(Node* head) {
    Node* temp = head;

    while (temp!= NULL) {
        printf("%s -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

int main() {
    Node* head = NULL;

    // Add nodes to the list
    addNode(&head, "Apple");
    addNode(&head, "Banana");
    addNode(&head, "Cherry");

    // Print the list
    printList(head);

    // Search for a node
    Node* foundNode = searchNode(head, "Banana");
    if (foundNode!= NULL) {
        printf("Found node: %s\n", foundNode->data);
    } else {
        printf("Node not found.\n");
    }

    // Delete a node
    deleteNode(&head, "Banana");

    // Print the updated list
    printList(head);

    return 0;
}