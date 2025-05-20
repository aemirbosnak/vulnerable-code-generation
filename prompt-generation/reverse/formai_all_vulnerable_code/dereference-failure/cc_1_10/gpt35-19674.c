//FormAI DATASET v1.0 Category: Linked list operations ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>

// Define a struct for the linked list node
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

// Function to insert a node at the beginning of the list
void insertAtBeginning(struct Node** headRef, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *headRef;
    *headRef = newNode;
}

// Function to insert a node at the end of the list
void insertAtEnd(struct Node** headRef, int data) {
    struct Node* newNode = createNode(data);
    if (*headRef == NULL) {
        *headRef = newNode;
        return;
    }
    struct Node* temp = *headRef;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to display the list
void displayList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

// Function to delete a node from the list
void deleteNode(struct Node** headRef, int data) {
    struct Node* temp = *headRef;
    struct Node* prev;
    if (temp != NULL && temp->data == data) {
        *headRef = temp->next;
        free(temp);
        return;
    }
    while (temp != NULL && temp->data != data) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        return;
    }
    prev->next = temp->next;
    free(temp);
}

// Function to reverse the list
void reverseList(struct Node** headRef) {
    struct Node* prev = NULL;
    struct Node* current = *headRef;
    struct Node* next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *headRef = prev;
}

int main() {
    struct Node* head = NULL;

    // Inserting nodes at the beginning of the list
    insertAtBeginning(&head, 5);
    insertAtBeginning(&head, 4);
    insertAtBeginning(&head, 3);
    insertAtBeginning(&head, 2);
    insertAtBeginning(&head, 1);
    printf("List after inserting nodes at the beginning: ");
    displayList(head);
    printf("\n");

    // Inserting nodes at the end of the list
    insertAtEnd(&head, 6);
    insertAtEnd(&head, 7);
    insertAtEnd(&head, 8);
    insertAtEnd(&head, 9);
    insertAtEnd(&head, 10);
    printf("List after inserting nodes at the end: ");
    displayList(head);
    printf("\n");

    // Deleting a node from the list
    deleteNode(&head, 5);
    printf("List after deleting a node: ");
    displayList(head);
    printf("\n");

    // Reversing the list
    reverseList(&head);
    printf("List after reversing: ");
    displayList(head);
    printf("\n");

    return 0;
}