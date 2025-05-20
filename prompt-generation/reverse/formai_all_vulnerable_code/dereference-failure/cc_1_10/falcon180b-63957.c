//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

// Define node structure
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function prototypes
void addNode(Node** head, int data);
void deleteNode(Node** head, int data);
void printList(Node* head);

int main() {
    Node* head = NULL;

    // Add nodes to the list
    addNode(&head, 5);
    addNode(&head, 10);
    addNode(&head, 15);

    // Print the list
    printf("Original list:\n");
    printList(head);

    // Delete a node
    deleteNode(&head, 10);

    // Print the updated list
    printf("\nList after deleting node with data 10:\n");
    printList(head);

    return 0;
}

// Function to add a node to the list
void addNode(Node** head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory error\n");
        return;
    }
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

// Function to delete a node from the list
void deleteNode(Node** head, int data) {
    Node* temp = *head;
    Node* prev = NULL;

    // If the head node is the node to be deleted
    if (temp!= NULL && temp->data == data) {
        *head = temp->next;
        free(temp);
        return;
    }

    // Traverse the list to find the node to be deleted
    while (temp!= NULL && temp->data!= data) {
        prev = temp;
        temp = temp->next;
    }

    // If the node is not found
    if (temp == NULL)
        return;

    // Unlink the node from the list
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