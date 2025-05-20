//FormAI DATASET v1.0 Category: Linked list operations ; Style: high level of detail
#include<stdio.h>
#include<stdlib.h>

// Create a Node structure to represent each element of the Linked List
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new Node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new Node at the beginning of the Linked List
void insertAtBeginning(struct Node** headRef, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = (*headRef);
    (*headRef) = newNode;
}

// Function to insert a new Node at the end of the Linked List
void insertAtEnd(struct Node** headRef, int data) {
    struct Node* newNode = createNode(data);
    struct Node* temp = (*headRef);
    if(temp == NULL) {
        (*headRef) = newNode;
        return;
    }
    while(temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to insert a new Node at a given position in the Linked List
void insertAtPosition(struct Node** headRef, int data, int position) {
    struct Node* newNode = createNode(data);
    if(position == 1) {
        newNode->next = (*headRef);
        (*headRef) = newNode;
        return;
    }
    struct Node* temp = (*headRef);
    for(int i=1;i<position-1;i++) {
        if(temp == NULL) {
            return;
        }
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

// Function to delete a Node from the Linked List
void deleteNode(struct Node** headRef, int key) {
    struct Node* temp = (*headRef);
    struct Node* prev = NULL;
    if(temp != NULL && temp->data == key) {
        (*headRef) = temp->next;
        free(temp);
        return;
    }

    while(temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    if(temp == NULL) {
        return;
    }

    prev->next = temp->next;
    free(temp);
}

// Function to print the Linked List
void printList(struct Node* head) {
    while(head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// Main function to test the Linked List operations
int main() {
    struct Node* head = NULL;
    insertAtEnd(&head, 5);
    insertAtBeginning(&head, 10);
    insertAtEnd(&head, 15);
    insertAtPosition(&head, 20, 2);
    deleteNode(&head, 10);
    printList(head);
    return 0;
}