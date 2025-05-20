//Falcon-180B DATASET v1.0 Category: File system simulation ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node structure definition
struct node {
    int data;
    struct node* next;
};

// Function to create a new node with the given data
struct node* newNode(int data) {
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Function to insert a node at the end of the list
void insertAtEnd(struct node** head, int data) {
    struct node* node = newNode(data);
    struct node* temp = *head;

    if (*head == NULL) {
        node->next = NULL;
        *head = node;
        return;
    }

    while (temp->next!= NULL) {
        temp = temp->next;
    }

    temp->next = node;
    node->next = NULL;
}

// Function to delete a node with the given data
void deleteNode(struct node** head, int data) {
    struct node* temp = *head;
    struct node* prev = NULL;

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

// Function to search for a node with the given data
struct node* searchNode(struct node* head, int data) {
    struct node* temp = head;

    while (temp!= NULL && temp->data!= data) {
        temp = temp->next;
    }

    if (temp == NULL) {
        return NULL;
    }

    return temp;
}

// Function to print the list
void printList(struct node* node) {
    while (node!= NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
}

// Main function
int main() {
    struct node* head = NULL;

    insertAtEnd(&head, 1);
    insertAtEnd(&head, 2);
    insertAtEnd(&head, 3);

    printList(head);

    deleteNode(&head, 2);

    printList(head);

    struct node* foundNode = searchNode(head, 3);
    if (foundNode!= NULL) {
        printf("Found node with data %d\n", foundNode->data);
    } else {
        printf("Node not found\n");
    }

    return 0;
}