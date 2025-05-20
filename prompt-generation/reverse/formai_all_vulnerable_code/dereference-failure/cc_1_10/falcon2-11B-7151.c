//Falcon2-11B DATASET v1.0 Category: Data structures visualization ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct definition
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the beginning of the linked list
void insertAtBeginning(struct Node** headRef, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *headRef;
    *headRef = newNode;
}

// Function to insert a node at the end of the linked list
void insertAtEnd(struct Node** headRef, int data) {
    struct Node* newNode = createNode(data);
    struct Node* current = *headRef;
    while (current->next!= NULL) {
        current = current->next;
    }
    current->next = newNode;
}

// Function to delete a node from the linked list
void deleteNode(struct Node** headRef, int data) {
    struct Node* current = *headRef;
    struct Node* prev = NULL;
    while (current!= NULL && current->data!= data) {
        prev = current;
        current = current->next;
    }
    if (current == NULL) {
        return; // Data not found
    }
    if (prev == NULL) {
        *headRef = current->next;
    } else {
        prev->next = current->next;
    }
    free(current);
}

// Function to display the linked list
void display(struct Node* head) {
    struct Node* current = head;
    while (current!= NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    insertAtBeginning(&head, 1);
    insertAtEnd(&head, 2);
    insertAtEnd(&head, 3);
    insertAtEnd(&head, 4);
    display(head);
    printf("Deleting 3...\n");
    deleteNode(&head, 3);
    display(head);
    printf("Deleting 4...\n");
    deleteNode(&head, 4);
    display(head);
    printf("Deleting 1...\n");
    deleteNode(&head, 1);
    display(head);
    printf("Deleting 2...\n");
    deleteNode(&head, 2);
    display(head);
    return 0;
}