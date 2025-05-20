//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a node structure for the linked list
typedef struct node {
    char *data;
    struct node *next;
} Node;

// Function to create a new node with given data
Node* createNode(char *data) {
    Node *newNode = (Node*) malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory error\n");
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to add a node at the end of the list
void appendNode(Node** head, char *data) {
    Node* newNode = createNode(data);
    Node* temp = *head;
    if (*head == NULL) {
        newNode->next = NULL;
        *head = newNode;
        return;
    }
    while (temp->next!= NULL)
        temp = temp->next;
    temp->next = newNode;
}

// Function to add a node at the beginning of the list
void prependNode(Node** head, char *data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        newNode->next = NULL;
        *head = newNode;
        return;
    }
    newNode->next = *head;
    *head = newNode;
}

// Function to add a node at a specific position in the list
void insertNode(Node** head, int pos, char *data) {
    Node* newNode = createNode(data);
    Node* temp = *head;
    if (pos == 0) {
        newNode->next = temp;
        *head = newNode;
        return;
    }
    for (int i = 0; i < pos - 1; i++) {
        if (temp == NULL) {
            printf("Position out of range\n");
            free(newNode);
            return;
        }
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

// Function to delete a node with given data from the list
void deleteNode(Node** head, char *data) {
    Node* temp = *head;
    if (temp!= NULL && strcmp(temp->data, data) == 0) {
        *head = temp->next;
        free(temp);
        return;
    }
    while (temp!= NULL && strcmp(temp->data, data)!= 0) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Node not found\n");
        return;
    }
    Node* delNode = temp->next;
    temp->next = delNode->next;
    free(delNode);
}

// Function to print the list
void printList(Node* head) {
    while (head!= NULL) {
        printf("%s ", head->data);
        head = head->next;
    }
    printf("\n");
}

// Main function
int main() {
    Node* head = NULL;

    // Add nodes to the list
    appendNode(&head, "apple");
    prependNode(&head, "orange");
    insertNode(&head, 2, "banana");

    // Print the list
    printList(head);

    // Delete a node
    deleteNode(&head, "orange");

    // Print the list again
    printList(head);

    return 0;
}