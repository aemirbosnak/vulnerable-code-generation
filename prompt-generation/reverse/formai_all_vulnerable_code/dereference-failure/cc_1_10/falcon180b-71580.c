//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define node structure
typedef struct node {
    int data;
    struct node* next;
} Node;

// Function prototypes
Node* createNode(int data);
Node* appendNode(Node* head, int data);
void printList(Node* head);
void deleteNode(Node** head, int data);

int main() {
    Node* head = NULL;

    // Create some nodes
    head = appendNode(head, 1);
    head = appendNode(head, 2);
    head = appendNode(head, 3);

    // Print the list
    printList(head);

    // Delete a node
    deleteNode(&head, 2);

    // Print the list again
    printList(head);

    return 0;
}

// Function to create a new node with given data
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to append a new node at the end of the list
Node* appendNode(Node* head, int data) {
    Node* newNode = createNode(data);
    Node* temp = head;

    // If the list is empty, set the new node as the head
    if (head == NULL) {
        head = newNode;
        return head;
    }

    // Traverse to the end of the list
    while (temp->next!= NULL) {
        temp = temp->next;
    }

    // Append the new node at the end
    temp->next = newNode;

    return head;
}

// Function to print the list
void printList(Node* head) {
    Node* temp = head;
    printf("List: ");
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Function to delete a node with given data
void deleteNode(Node** head, int data) {
    Node* temp = *head;
    Node* prev = NULL;

    // If the head node itself needs to be deleted
    if (temp!= NULL && temp->data == data) {
        *head = temp->next;
        free(temp);
        return;
    }

    // Traverse through the list
    while (temp!= NULL && temp->data!= data) {
        prev = temp;
        temp = temp->next;
    }

    // If the node is not found
    if (temp == NULL) {
        return;
    }

    // Unlink the node
    prev->next = temp->next;
    free(temp);
}