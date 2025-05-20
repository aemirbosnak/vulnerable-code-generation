//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Define the structure for each node in the linked list
typedef struct node {
    char data;
    struct node *next;
} Node;

// Function to create a new node in the linked list
Node* createNode(char data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to add a node at the end of the linked list
void appendNode(Node** head, char data) {
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
    return;
}

// Function to add a node at the beginning of the linked list
void prependNode(Node** head, char data) {
    Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
    return;
}

// Function to delete a node from the linked list
void deleteNode(Node** head, char data) {
    Node* temp = *head;
    Node* prev = NULL;
    if (temp->data == data) {
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
    return;
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

// Main function
int main() {
    Node* head = NULL;
    appendNode(&head, 'a');
    appendNode(&head, 'b');
    prependNode(&head, 'z');
    deleteNode(&head, 'a');
    printList(head);
    return 0;
}