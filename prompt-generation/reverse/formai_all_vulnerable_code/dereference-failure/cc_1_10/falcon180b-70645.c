//Falcon-180B DATASET v1.0 Category: Memory management ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

// Node structure for linked list
typedef struct node {
    char data[MAX_SIZE];
    struct node* next;
} Node;

// Function to create a new node with given data
Node* createNode(char* data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Error: Memory could not be allocated.\n");
        exit(1);
    }
    strcpy(newNode->data, data);
    newNode->next = NULL;
    return newNode;
}

// Function to add a node at the end of the list
void addNode(Node** head, char* data) {
    Node* newNode = createNode(data);
    Node* temp = *head;
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    while (temp->next!= NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to delete a node with given data from the list
void deleteNode(Node** head, char* data) {
    Node* temp = *head;
    Node* prev = NULL;
    while (temp!= NULL && strcmp(temp->data, data)!= 0) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Error: Node not found.\n");
        return;
    }
    if (prev == NULL) {
        *head = temp->next;
    } else {
        prev->next = temp->next;
    }
    free(temp);
}

// Function to print the list
void printList(Node* head) {
    while (head!= NULL) {
        printf("%s ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    Node* head = NULL;

    // Add nodes to the list
    addNode(&head, "apple");
    addNode(&head, "banana");
    addNode(&head, "orange");

    // Print the list
    printList(head);

    // Delete a node from the list
    deleteNode(&head, "banana");

    // Print the updated list
    printList(head);

    return 0;
}