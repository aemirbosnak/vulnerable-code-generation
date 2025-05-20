//FormAI DATASET v1.0 Category: Linked list operations ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

// defining the structure of a node in the linked list
struct Node {
    int data;
    struct Node* next;
};

// function to insert a new node at the beginning of the linked list
void insertAtBeginning(struct Node** head, int newData) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode -> data = newData;
    newNode -> next = *head;
    *head = newNode;
}

// function to insert a new node at the end of the linked list
void insertAtEnd(struct Node** head, int newData) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode -> data = newData;
    newNode -> next = NULL;
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* lastNode = *head;
    while (lastNode -> next != NULL) {
        lastNode = lastNode -> next;
    }
    lastNode -> next = newNode;
}

// function to delete a node with the given key from the linked list
void deleteNode(struct Node** head, int key) {
    struct Node* temp = *head;
    struct Node* prev = NULL;
    if (temp != NULL && temp -> data == key) {
        *head = temp -> next;
        free(temp);
        return;
    }
    while (temp != NULL && temp -> data != key) {
        prev = temp;
        temp = temp -> next;
    }
    if (temp == NULL) {
        return;
    }
    prev -> next = temp -> next;
    free(temp);
}

// function to display the contents of the linked list
void display(struct Node* head) {
    if (head == NULL) {
        printf("\nThe list is empty!\n");
        return;
    }
    printf("\nThe contents of the linked list are:\n");
    struct Node* currentNode = head;
    while (currentNode != NULL) {
        printf("%d ", currentNode -> data);
        currentNode = currentNode -> next;
    }
    printf("\n");
}

// main function
int main() {
    struct Node* head = NULL;
    printf("**** C Linked List Example Program ****\n\n");
    printf("Inserting nodes at the beginning of the linked list...\n");
    insertAtBeginning(&head, 10);
    insertAtBeginning(&head, 20);
    insertAtBeginning(&head, 30);
    display(head);
    printf("Inserting nodes at the end of the linked list...\n");
    insertAtEnd(&head, 40);
    insertAtEnd(&head, 50);
    insertAtEnd(&head, 60);
    display(head);
    printf("Deleting a node from the linked list...\n");
    deleteNode(&head, 40);
    display(head);
    printf("Deleting a node from the linked list...\n");
    deleteNode(&head, 20);
    display(head);
    printf("Deleting a node from the linked list...\n");
    deleteNode(&head, 10);
    display(head);
    printf("Deleting a node that does not exist in the linked list...\n");
    deleteNode(&head, 80);
    display(head);
    return 0;
}