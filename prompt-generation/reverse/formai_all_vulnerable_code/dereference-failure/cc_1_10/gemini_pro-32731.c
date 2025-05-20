//GEMINI-pro DATASET v1.0 Category: Performance-Critical Component ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node in the linked list
struct Node {
    int data;
    struct Node *next;
};

// Function to create a new node with the given data
struct Node* createNode(int data) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new node at the beginning of the linked list
void insertAtBeginning(struct Node **head, int data) {
    struct Node *newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

// Function to insert a new node at the end of the linked list
void insertAtEnd(struct Node **head, int data) {
    struct Node *newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node *temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to delete a node from the linked list
void deleteNode(struct Node **head, int data) {
    if (*head == NULL) {
        return;
    }
    if ((*head)->data == data) {
        *head = (*head)->next;
        return;
    }
    struct Node *temp = *head;
    while (temp->next != NULL && temp->next->data != data) {
        temp = temp->next;
    }
    if (temp->next == NULL) {
        return;
    }
    temp->next = temp->next->next;
}

// Function to print the linked list
void printLinkedList(struct Node *head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    struct Node *head = NULL;
    insertAtBeginning(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);
    printLinkedList(head); // Output: 10 20 30
    deleteNode(&head, 20);
    printLinkedList(head); // Output: 10 30
    insertAtBeginning(&head, 5);
    printLinkedList(head); // Output: 5 10 30
    return 0;
}