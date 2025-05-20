//Falcon-180B DATASET v1.0 Category: Memory management ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

// Node structure definition
typedef struct node {
    int data;
    struct node* next;
} Node;

// Function to add a node at the end of the list
void addNode(Node** head, int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory error\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    if (*head == NULL) {
        *head = newNode;
    }
    else {
        Node* temp = *head;
        while (temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to delete a node with the given data
void deleteNode(Node** head, int data) {
    Node* temp = *head;
    Node* prev = NULL;
    while (temp!= NULL && temp->data!= data) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Node not found\n");
        return;
    }
    if (prev == NULL) {
        *head = temp->next;
    }
    else {
        prev->next = temp->next;
    }
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

// Main function
int main() {
    Node* head = NULL;

    // Adding nodes
    addNode(&head, 1);
    addNode(&head, 2);
    addNode(&head, 3);
    addNode(&head, 4);

    // Printing the list
    printf("Initial list:\n");
    printList(head);

    // Deleting a node
    deleteNode(&head, 3);

    // Printing the list after deletion
    printf("List after deleting 3:\n");
    printList(head);

    // Adding more nodes
    addNode(&head, 5);
    addNode(&head, 6);

    // Printing the final list
    printf("Final list:\n");
    printList(head);

    return 0;
}