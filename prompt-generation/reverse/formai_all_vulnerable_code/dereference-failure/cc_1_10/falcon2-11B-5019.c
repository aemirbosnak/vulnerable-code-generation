//Falcon2-11B DATASET v1.0 Category: Linked list operations ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of a node in the linked list
struct node {
    int data;
    struct node* next;
};

// Function to create a new node with the given data
struct node* createNode(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to print the contents of the linked list
void printList(struct node* head) {
    struct node* temp = head;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Function to insert a new node at the beginning of the linked list
struct node* insertAtBeginning(struct node* head, int data) {
    struct node* newNode = createNode(data);
    newNode->next = head;
    return newNode;
}

// Function to insert a new node at the end of the linked list
struct node* insertAtEnd(struct node* head, int data) {
    struct node* newNode = createNode(data);
    struct node* temp = head;
    while (temp->next!= NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

// Function to delete a node with the given data from the linked list
struct node* deleteNode(struct node* head, int data) {
    struct node* temp = head;
    struct node* prev = NULL;
    while (temp!= NULL && temp->data!= data) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        return head; // data not found
    }
    if (prev == NULL) {
        head = temp->next;
        free(temp);
    } else {
        prev->next = temp->next;
        free(temp);
    }
    return head;
}

int main() {
    struct node* head = NULL;
    struct node* node1 = createNode(1);
    struct node* node2 = createNode(2);
    struct node* node3 = createNode(3);

    head = insertAtBeginning(head, 1);
    head = insertAtEnd(head, 2);
    head = insertAtEnd(head, 3);

    printList(head); // Output: 1 2 3

    head = deleteNode(head, 2);
    printList(head); // Output: 1 3

    return 0;
}