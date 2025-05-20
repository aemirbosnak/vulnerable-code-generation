//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the structure of a node
struct node {
    int data;
    struct node* next;
};

// Function to create a new node
struct node* createNode(int data) {
    struct node* newNode = (struct node*) malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the beginning of the list
void insertAtBeginning(struct node** head, int data) {
    struct node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

// Function to insert a node at the end of the list
void insertAtEnd(struct node* head, int data) {
    struct node* newNode = createNode(data);
    struct node* temp = head;
    while (temp->next!= NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to insert a node at a specific position in the list
void insertAtPosition(struct node* head, int data, int position) {
    struct node* newNode = createNode(data);
    struct node* temp = head;
    if (position == 1) {
        newNode->next = head;
        head = newNode;
        return;
    }
    int count = 1;
    while (temp!= NULL && count < position - 1) {
        temp = temp->next;
        count++;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

// Function to delete a node from the list
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

// Function to search for a node in the list
struct node* searchNode(struct node* head, int data) {
    struct node* temp = head;
    while (temp!= NULL && temp->data!= data) {
        temp = temp->next;
    }
    return temp;
}

// Function to print the list
void printList(struct node* head) {
    struct node* temp = head;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main function
int main() {
    struct node* head = NULL;
    insertAtBeginning(&head, 10);
    insertAtEnd(head, 20);
    insertAtPosition(head, 15, 2);
    printList(head);
    deleteNode(&head, 10);
    printList(head);
    struct node* foundNode = searchNode(head, 15);
    if (foundNode!= NULL) {
        printf("Found node with data %d\n", foundNode->data);
    } else {
        printf("Node not found\n");
    }
    return 0;
}