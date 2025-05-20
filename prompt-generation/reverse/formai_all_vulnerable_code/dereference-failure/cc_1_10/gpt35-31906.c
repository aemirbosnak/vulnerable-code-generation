//FormAI DATASET v1.0 Category: Linked list operations ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

// Define the structure of a single linked list node
struct node {
    int data;
    struct node *next;
};

// Initialize an empty linked list
struct node *head = NULL;

// Function to print the linked list
void printList() {
    struct node *temp = head;
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to insert a node at the beginning of the linked list
void insertAtBegin(int data) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = head;
    head = newNode;
    printf("%d inserted at the beginning of the linked list\n", data);
}

// Function to insert a node at the end of the linked list
void insertAtEnd(int data) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    if (head == NULL) {
        head = newNode;
        printf("%d inserted at the end of the linked list\n", data);
        return;
    }
    struct node *temp = head;
    while (temp->next != NULL) temp = temp->next;
    temp->next = newNode;
    printf("%d inserted at the end of the linked list\n", data);
}

// Function to insert a node at a specific position in the linked list
void insertAtPos(int data, int pos) {
    if (pos <= 0) {
        printf("Invalid position\n");
        return;
    }
    if (pos == 1) {
        insertAtBegin(data);
        return;
    }
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    struct node *temp = head;
    int i = 1;
    while (i < pos - 1 && temp != NULL) {
        temp = temp->next;
        i++;
    }
    if (temp == NULL) {
        printf("Invalid position\n");
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    printf("%d inserted at position %d of the linked list\n", data, pos);
}

// Function to delete a node from the beginning of the linked list
void deleteFromBegin() {
    if (head == NULL) {
        printf("Linked list is empty\n");
        return;
    }
    struct node *temp = head;
    head = head->next;
    printf("%d deleted from the beginning of the linked list\n", temp->data);
    free(temp);
}

// Function to delete a node from the end of the linked list
void deleteFromEnd() {
    if (head == NULL) {
        printf("Linked list is empty\n");
        return;
    }
    if (head->next == NULL) {
        printf("%d deleted from the end of the linked list\n", head->data);
        free(head);
        head = NULL;
        return;
    }
    struct node *temp1 = head, *temp2 = NULL;
    while (temp1->next != NULL) {
        temp2 = temp1;
        temp1 = temp1->next;
    }
    printf("%d deleted from the end of the linked list\n", temp1->data);
    free(temp1);
    temp2->next = NULL;
}

// Function to delete a node from a specific position in the linked list
void deleteFromPos(int pos) {
    if (head == NULL) {
        printf("Linked list is empty\n");
        return;
    }
    if (pos <= 0) {
        printf("Invalid position\n");
        return;
    }
    if (pos == 1) {
        deleteFromBegin();
        return;
    }
    struct node *temp1 = head, *temp2 = NULL;
    int i = 1;
    while (i < pos && temp1 != NULL) {
        temp2 = temp1;
        temp1 = temp1->next;
        i++;
    }
    if (temp1 == NULL) {
        printf("Invalid position\n");
        return;
    }
    temp2->next = temp1->next;
    printf("%d deleted from position %d of the linked list\n", temp1->data, pos);
    free(temp1);
}

int main() {
    insertAtBegin(10);
    insertAtBegin(20);
    insertAtEnd(30);
    insertAtEnd(40);
    insertAtPos(50, 2);
    printList();
    deleteFromBegin();
    deleteFromEnd();
    deleteFromPos(2);
    printList();
    return 0;
}