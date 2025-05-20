//Falcon-180B DATASET v1.0 Category: Memory management ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node structure definition
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function to create a new node with given data
Node* createNode(int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));

    if (newNode == NULL) {
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
        return;
    }

    while (temp->next!= NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
}

// Function to delete a node with given data
void deleteNode(Node** head, int data) {
    Node* temp = *head;

    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }

    if (temp->data == data) {
        *head = temp->next;
        free(temp);
        return;
    }

    while (temp->next!= NULL && temp->next->data!= data) {
        temp = temp->next;
    }

    if (temp->next == NULL) {
        printf("Node not found\n");
    } else {
        Node* nodeToDelete = temp->next;
        temp->next = temp->next->next;
        free(nodeToDelete);
    }
}

// Function to print the list
void printList(Node* head) {
    Node* temp = head;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    printf("List: ");
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Driver program to test above functions
int main() {
    Node* head = NULL;

    addNode(&head, 10);
    addNode(&head, 20);
    addNode(&head, 30);
    addNode(&head, 40);

    printList(head);

    deleteNode(&head, 20);

    printList(head);

    deleteNode(&head, 10);

    printList(head);

    deleteNode(&head, 30);

    printList(head);

    deleteNode(&head, 40);

    printList(head);

    return 0;
}