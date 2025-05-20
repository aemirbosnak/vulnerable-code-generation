//Falcon-180B DATASET v1.0 Category: Browser Plugin ; Style: excited
#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node in the linked list
typedef struct node {
    int data;
    struct node* next;
} Node;

// Function to insert a node at the end of the linked list
void insertNode(Node** head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
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

// Function to delete a node with the given data from the linked list
void deleteNode(Node** head, int data) {
    Node* temp = *head;

    if (temp!= NULL && temp->data == data) {
        *head = temp->next;
        free(temp);
        return;
    }

    while (temp!= NULL && temp->data!= data) {
        temp = temp->next;
    }

    if (temp == NULL) {
        return;
    }

    Node* prev = temp->next;
    free(temp);
    temp = prev;
}

// Function to search for a node with the given data in the linked list
Node* searchNode(Node* head, int data) {
    Node* temp = head;

    while (temp!= NULL) {
        if (temp->data == data) {
            return temp;
        }
        temp = temp->next;
    }

    return NULL;
}

// Function to print the linked list
void printList(Node* head) {
    Node* temp = head;

    while (temp!= NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

// Main function
int main() {
    Node* head = NULL;

    // Insert nodes with data 1, 2, 3, 4, 5
    insertNode(&head, 1);
    insertNode(&head, 2);
    insertNode(&head, 3);
    insertNode(&head, 4);
    insertNode(&head, 5);

    // Print the linked list
    printf("Original linked list:\n");
    printList(head);

    // Delete node with data 3
    deleteNode(&head, 3);

    // Print the linked list after deleting node with data 3
    printf("Linked list after deleting node with data 3:\n");
    printList(head);

    // Search for node with data 4
    Node* result = searchNode(head, 4);

    if (result!= NULL) {
        printf("Node found with data %d\n", result->data);
    } else {
        printf("Node not found\n");
    }

    return 0;
}