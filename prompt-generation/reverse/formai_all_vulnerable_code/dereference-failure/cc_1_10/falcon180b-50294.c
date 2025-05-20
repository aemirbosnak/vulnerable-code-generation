//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define node structure
typedef struct node {
    int data;
    struct node* next;
} Node;

// Function to create a new node with given data
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory error\n");
        exit(0);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to add a node at the end of the list
void push(Node** head, int data) {
    Node* newNode = createNode(data);
    Node* temp = *head;
    if (temp == NULL) {
        *head = newNode;
        return;
    }
    while (temp->next!= NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to add a node at the beginning of the list
void pushFront(Node** head, int data) {
    Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

// Function to delete a node with given data
void deleteNode(Node** head, int data) {
    Node* temp = *head;
    if (temp!= NULL && temp->data == data) {
        *head = temp->next;
        free(temp);
        return;
    }
    while (temp!= NULL && temp->data!= data) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Node not found\n");
        return;
    }
    Node* prev = temp->next;
    temp->next = NULL;
    free(temp);
    prev->next = temp->next;
}

// Function to print the list
void printList(Node* head) {
    while (head!= NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    Node* head = NULL;
    push(&head, 4);
    push(&head, 2);
    push(&head, 1);
    push(&head, 3);
    pushFront(&head, 0);
    printList(head);
    deleteNode(&head, 1);
    deleteNode(&head, 0);
    printList(head);
    return 0;
}