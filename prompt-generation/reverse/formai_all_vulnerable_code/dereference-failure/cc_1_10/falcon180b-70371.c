//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

// Node structure for linked list
typedef struct node {
    char data;
    struct node* next;
} Node;

// Function to add a node to the end of the list
void addNode(Node** head, char data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    Node* temp = *head;
    while (temp->next!= NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to print the linked list
void printList(Node* head) {
    Node* temp = head;
    while (temp!= NULL) {
        printf("%c -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to search for a node in the list
Node* searchList(Node* head, char data) {
    Node* temp = head;
    while (temp!= NULL) {
        if (temp->data == data) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

// Function to delete a node from the list
void deleteNode(Node** head, char data) {
    Node* temp = *head;
    Node* prev = NULL;

    if (temp!= NULL && temp->data == data) {
        *head = temp->next;
        free(temp);
        return;
    }

    while (temp!= NULL && temp->data!= data) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        return;
    }

    prev->next = temp->next;
    free(temp);
}

int main() {
    Node* head = NULL;

    // Add nodes to the list
    addNode(&head, 'a');
    addNode(&head, 'b');
    addNode(&head, 'c');
    addNode(&head, 'd');

    // Print the list
    printf("Original list:\n");
    printList(head);

    // Search for a node
    Node* result = searchList(head, 'b');
    if (result!= NULL) {
        printf("Found node with data %c\n", result->data);
    } else {
        printf("Node not found\n");
    }

    // Delete a node
    deleteNode(&head, 'b');

    // Print the updated list
    printf("Updated list:\n");
    printList(head);

    return 0;
}