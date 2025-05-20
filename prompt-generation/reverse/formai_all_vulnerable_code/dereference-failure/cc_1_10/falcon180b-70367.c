//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define node structure
typedef struct node {
    char data;
    struct node* next;
} Node;

// Function prototypes
Node* createNode(char data);
void addNode(Node** head, char data);
void deleteNode(Node** head, char data);
void printList(Node* node);

int main() {
    // Initialize an empty linked list
    Node* head = NULL;

    // Add nodes to the linked list
    addNode(&head, 'a');
    addNode(&head, 'b');
    addNode(&head, 'c');

    // Print the linked list
    printf("Linked List: ");
    printList(head);

    // Delete a node from the linked list
    deleteNode(&head, 'b');

    // Print the updated linked list
    printf("\nLinked List after deleting 'b': ");
    printList(head);

    return 0;
}

// Function to create a new node
Node* createNode(char data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory error\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to add a node to the linked list
void addNode(Node** head, char data) {
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

// Function to delete a node from the linked list
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

// Function to print the linked list
void printList(Node* node) {
    while (node!= NULL) {
        printf("%c ", node->data);
        node = node->next;
    }
}