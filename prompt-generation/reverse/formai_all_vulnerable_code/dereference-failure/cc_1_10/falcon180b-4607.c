//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: calm
#include <stdio.h>
#include <stdlib.h>

// Define the structure for each node in the linked list
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function to add a new node to the end of the linked list
void addNode(Node** headRef, int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*headRef == NULL) {
        *headRef = newNode;
    } else {
        Node* temp = *headRef;
        while (temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to delete a node with the specified data from the linked list
void deleteNode(Node** headRef, int data) {
    Node* temp = *headRef;
    Node* prev = NULL;

    if (temp!= NULL && temp->data == data) {
        *headRef = temp->next;
        free(temp);
        return;
    }

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

// Function to print the contents of the linked list
void printList(Node* head) {
    Node* temp = head;
    printf("List: ");
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Function to reverse the linked list
void reverseList(Node** headRef) {
    Node* prev = NULL;
    Node* curr = *headRef;

    while (curr!= NULL) {
        Node* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    *headRef = prev;
}

int main() {
    Node* head = NULL;

    // Add some nodes to the list
    addNode(&head, 5);
    addNode(&head, 10);
    addNode(&head, 15);

    // Print the list
    printList(head);

    // Delete a node from the list
    deleteNode(&head, 10);

    // Print the list again
    printList(head);

    // Reverse the list
    reverseList(&head);

    // Print the list again
    printList(head);

    return 0;
}