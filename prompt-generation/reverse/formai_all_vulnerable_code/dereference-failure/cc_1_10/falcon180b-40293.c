//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

// Define a struct for a node in our linked list
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function prototypes
void append(Node** head, int data);
void prepend(Node** head, int data);
void deleteNode(Node** head, int data);
void printList(Node* head);

int main() {
    Node* head = NULL;

    // Append a node with data 5
    append(&head, 5);

    // Prepend a node with data 3
    prepend(&head, 3);

    // Print the list
    printList(head);

    // Delete a node with data 5
    deleteNode(&head, 5);

    // Print the list again
    printList(head);

    return 0;
}

// Function to append a node with data to the end of the list
void append(Node** head, int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    Node* temp = *head;

    while (temp->next!= NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
}

// Function to prepend a node with data to the beginning of the list
void prepend(Node** head, int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = *head;

    *head = newNode;
}

// Function to delete a node with data from the list
void deleteNode(Node** head, int data) {
    Node* temp = *head;

    if (temp!= NULL && temp->data == data) {
        *head = temp->next;
        free(temp);
        return;
    }

    Node* prev = NULL;

    while (temp!= NULL && temp->data!= data) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        return;
    }

    prev->next = temp->next;
    free(temp);
}

// Function to print the list
void printList(Node* head) {
    Node* temp = head;

    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}