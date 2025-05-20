//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

// Define the node structure
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

    // Create the first node with data 5
    head = createNode(5);

    // Append nodes with data 10, 15, and 20
    head = appendNode(head, 10);
    head = appendNode(head, 15);
    head = appendNode(head, 20);

    // Print the list
    printList(head);

    // Delete node with data 10
    deleteNode(&head, 10);

    // Print the updated list
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

// Function to append a node with given data to the end of the list
Node* appendNode(Node* head, int data) {
    Node* newNode = createNode(data);

    if (head == NULL) {
        head = newNode;
        return head;
    }

    Node* temp = head;
    while (temp->next!= NULL) {
        temp = temp->next;
    }
    temp->next = newNode;

    return head;
}

// Function to print the list
void printList(Node* head) {
    if (head == NULL) {
        printf("Empty list\n");
        return;
    }

    Node* temp = head;
    while (temp!= NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
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

    if (temp == NULL) {
        return;
    }

    prev->next = temp->next;
    free(temp);
}