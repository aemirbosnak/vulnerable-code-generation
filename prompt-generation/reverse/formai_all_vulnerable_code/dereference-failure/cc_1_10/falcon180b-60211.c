//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>

// Node structure definition for the linked list
typedef struct Node {
    int data;
    struct Node *next;
} Node;

// Function to create a new node with given data
Node* newNode(int data) {
    Node* node = (Node*) malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Function to add a node at the beginning of the list
void push(Node** head, int data) {
    Node* node = newNode(data);
    node->next = *head;
    *head = node;
}

// Function to add a node at the end of the list
void append(Node** head, int data) {
    Node* node = newNode(data);
    Node* last = *head;
    if (*head == NULL) {
        push(head, data);
        return;
    }
    while (last->next!= NULL)
        last = last->next;
    last->next = node;
}

// Function to add a node at a specific position in the list
void addAtPosition(Node** head, int data, int pos) {
    Node* node = newNode(data);
    Node* temp = *head;
    if (pos == 0) {
        push(head, data);
        return;
    }
    for (int i = 0; i < pos - 1 && temp!= NULL; i++)
        temp = temp->next;
    if (temp == NULL) {
        printf("Invalid position\n");
        return;
    }
    node->next = temp->next;
    temp->next = node;
}

// Function to delete a node with given data from the list
void deleteNode(Node** head, int data) {
    Node* temp = *head;
    Node* prev = NULL;
    if (temp!= NULL && temp->data == data) {
        *head = temp->next;
        free(temp);
        return;
    }
    while (temp!= NULL && temp->data!= data) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL)
        return;
    prev->next = temp->next;
    free(temp);
}

// Function to print the list
void printList(Node* node) {
    while (node!= NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

int main() {
    Node* head = NULL;

    // Adding nodes to the list
    push(&head, 1);
    push(&head, 2);
    push(&head, 3);
    append(&head, 4);
    addAtPosition(&head, 5, 2);

    // Printing the list
    printList(head);

    // Deleting a node
    deleteNode(&head, 2);

    // Printing the list after deletion
    printList(head);

    return 0;
}