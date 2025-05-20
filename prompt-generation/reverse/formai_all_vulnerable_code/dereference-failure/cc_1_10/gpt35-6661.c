//FormAI DATASET v1.0 Category: Linked list operations ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

// Linked list node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node and initialize its data
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new node at the beginning of the list
void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

// Function to insert a new node at the end of the list
void insertAtEnd(struct Node** head, int data) {
    struct Node* temp = *head;
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to insert a new node at a given position in the list
void insertAtIndex(struct Node** head, int data, int pos) {
    struct Node* newNode = createNode(data);
    struct Node* temp = *head;
    if (pos == 0) {
        newNode->next = *head;
        *head = newNode;
        return;
    }
    for (int i = 0; i < pos - 1 && temp != NULL; i++) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Error: The given position is out of range.\n");
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

// Function to delete the first node in the list
void deleteAtBeginning(struct Node** head) {
    if (*head == NULL) {
        printf("Error: The list is already empty.\n");
        return;
    }
    struct Node* temp = *head;
    *head = (*head)->next;
    free(temp);
}

// Function to delete the last node in the list
void deleteAtEnd(struct Node** head) {
    if (*head == NULL) {
        printf("Error: The list is already empty.\n");
        return;
    }
    struct Node* temp = *head;
    struct Node* prev = NULL;
    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }
    if (prev == NULL) {
        *head = NULL;
    }
    else {
        prev->next = NULL;
    }
    free(temp);
}

// Function to delete a node at a given position in the list
void deleteAtIndex(struct Node** head, int pos) {
    if (*head == NULL) {
        printf("Error: The list is already empty.\n");
        return;
    }
    struct Node* temp = *head;
    struct Node* prev = NULL;
    if (pos == 0) {
        *head = (*head)->next;
        free(temp);
        return;
    }
    for (int i = 0; i < pos && temp != NULL; i++) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Error: The given position is out of range.\n");
        return;
    }
    prev->next = temp->next;
    free(temp);
}

// Function to print the contents of the list
void printList(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main function
int main() {
    struct Node* head = NULL;
    insertAtBeginning(&head, 10);
    insertAtBeginning(&head, 20);
    insertAtEnd(&head, 30);
    insertAtEnd(&head, 40);
    insertAtIndex(&head, 50, 3);
    printf("Linked list: ");
    printList(head);
    printf("Deleting the node at the beginning.\n");
    deleteAtBeginning(&head);
    printf("Linked list: ");
    printList(head);
    printf("Deleting the node at the end.\n");
    deleteAtEnd(&head);
    printf("Linked list: ");
    printList(head);
    printf("Deleting the node at position 2.\n");
    deleteAtIndex(&head, 2);
    printf("Linked list: ");
    printList(head);
    printf("Inserting 60 at position 1.\n");
    insertAtIndex(&head, 60, 1);
    printf("Linked list: ");
    printList(head);
    return 0;
}