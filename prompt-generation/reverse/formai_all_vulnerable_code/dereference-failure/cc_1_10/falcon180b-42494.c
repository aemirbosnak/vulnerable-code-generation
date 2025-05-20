//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: complete
#include <stdio.h>
#include <stdlib.h>

// Define node structure
typedef struct node {
    int data;
    struct node* next;
} Node;

// Function prototypes
void addNode(Node** head, int data);
void deleteNode(Node** head, int data);
void printList(Node* head);

int main() {
    Node* head = NULL;

    // Add nodes to the list
    addNode(&head, 1);
    addNode(&head, 2);
    addNode(&head, 3);
    addNode(&head, 4);
    addNode(&head, 5);

    // Print the list
    printList(head);

    // Delete a node from the list
    deleteNode(&head, 3);

    // Print the list again
    printList(head);

    return 0;
}

// Function to add a node to the list
void addNode(Node** head, int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

// Function to delete a node from the list
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

    if (temp == NULL) {
        return;
    }

    prev->next = temp->next;
    free(temp);
}

// Function to print the list
void printList(Node* head) {
    while (head!= NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}