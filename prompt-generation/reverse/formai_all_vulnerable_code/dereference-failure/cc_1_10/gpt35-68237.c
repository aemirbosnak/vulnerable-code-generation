//FormAI DATASET v1.0 Category: Data structures visualization ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

// Define data structure for singly linked list
typedef struct node {
    int data;
    struct node* next;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the beginning of the list
Node* insertAtBeginning(Node* head, int data) {
    Node* newNode = createNode(data);
    newNode->next = head;
    head = newNode;
    return head;
}

// Function to insert a node at the end of the list
Node* insertAtEnd(Node* head, int data) {
    Node* newNode = createNode(data);
    Node* temp = head;
    if (head == NULL) {
        head = newNode;
    } else {
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    return head;
}

// Function to delete a node with given data from the list
Node* deleteNode(Node* head, int data) {
    Node* temp = head;
    Node* prev = NULL;
    if (temp != NULL && temp->data == data) {
        head = temp->next;
        free(temp);
        return head;
    } else {
        while (temp != NULL && temp->data != data) {
            prev = temp;
            temp = temp->next;
        }
        if (temp == NULL) {
            printf("Data not found\n");
            return head;
        } else {
            prev->next = temp->next;
            free(temp);
            return head;
        }
    }
}

// Function to print the list
void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d --> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Main function
int main() {
    Node* head = NULL;
    head = insertAtEnd(head, 5);
    head = insertAtBeginning(head, 3);
    head = insertAtEnd(head, 7);
    head = insertAtBeginning(head, 1);
    head = insertAtEnd(head, 9);
    printList(head);
    head = deleteNode(head, 3);
    head = deleteNode(head, 7);
    head = deleteNode(head, 10);
    printList(head);
    return 0;
}