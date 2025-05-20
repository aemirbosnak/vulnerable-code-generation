//Falcon-180B DATASET v1.0 Category: Memory management ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

// Node structure for linked list
typedef struct node {
    char data[MAX_SIZE];
    struct node* next;
} Node;

// Function to create a new node
Node* createNode(char* data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    strcpy(newNode->data, data);
    newNode->next = NULL;
    return newNode;
}

// Function to add a node to the end of the list
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

// Function to print the list
void printList(Node* head) {
    Node* temp = head;
    while (temp!= NULL) {
        printf("%s -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Main function
int main() {
    Node* head = NULL;

    // Add nodes to the list
    addNode(&head, "Hello");
    addNode(&head, "World");

    // Print the list
    printf("List before deletion:\n");
    printList(head);

    // Delete a node
    Node* temp = head;
    while (temp!= NULL && strcmp(temp->data, "World")!= 0) {
        temp = temp->next;
    }
    if (temp!= NULL) {
        Node* prev = head;
        while (prev->next!= temp) {
            prev = prev->next;
        }
        prev->next = temp->next;
        free(temp);
        temp = NULL;
    }

    // Print the list after deletion
    printf("List after deletion:\n");
    printList(head);

    return 0;
}