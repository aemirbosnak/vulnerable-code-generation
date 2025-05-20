//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>

// Define structure for a node
typedef struct node {
    int data;
    struct node* next;
} Node;

// Function to create a new node with the given data
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory error\n");
        exit(0);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to add a node at the beginning of the list
Node* addNodeAtBeginning(Node* head, int data) {
    Node* newNode = createNode(data);
    newNode->next = head;
    return newNode;
}

// Function to add a node at the end of the list
Node* addNodeAtEnd(Node* head, int data) {
    Node* newNode = createNode(data);
    Node* temp = head;
    if (head == NULL) {
        newNode->next = NULL;
        return newNode;
    }
    while (temp->next!= NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

// Function to add a node at a specific position in the list
Node* addNodeAtPosition(Node* head, int data, int position) {
    Node* newNode = createNode(data);
    Node* temp = head;
    if (position == 1) {
        newNode->next = head;
        return newNode;
    }
    for (int i = 1; i < position - 1 && temp!= NULL; i++) {
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    return head;
}

// Function to delete a node with the given data
Node* deleteNode(Node* head, int data) {
    Node* temp = head;
    Node* prev = NULL;
    if (temp!= NULL && temp->data == data) {
        head = temp->next;
        free(temp);
        return head;
    }
    while (temp!= NULL && temp->data!= data) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        return head;
    }
    prev->next = temp->next;
    free(temp);
    return head;
}

// Function to display the list
void displayList(Node* head) {
    Node* temp = head;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main function
int main() {
    Node* head = NULL;
    head = addNodeAtBeginning(head, 1);
    head = addNodeAtEnd(head, 2);
    head = addNodeAtEnd(head, 3);
    head = addNodeAtBeginning(head, 0);
    displayList(head);
    head = deleteNode(head, 1);
    displayList(head);
    head = addNodeAtPosition(head, 4, 2);
    displayList(head);
    return 0;
}