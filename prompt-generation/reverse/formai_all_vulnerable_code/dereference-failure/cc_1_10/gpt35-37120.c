//FormAI DATASET v1.0 Category: Linked list operations ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>

// Node structure
typedef struct node {
    int data;
    struct node *next;
} Node;

// Function prototypes
Node* createNode(int data);
void insertAtBeginning(Node **head, int data);
void insertAtEnd(Node **head, int data);
void insertAtPos(Node **head, int data, int pos);
void deleteAtBeginning(Node **head);
void deleteAtEnd(Node **head);
void deleteAtPos(Node **head, int pos);
void display(Node *head);

// Main function
int main() {
    Node *head = NULL;

    // Insert elements into the list
    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtBeginning(&head, 30);
    insertAtPos(&head, 40, 2);

    // Display the list
    printf("Linked List: ");
    display(head);

    // Delete elements from the list
    deleteAtPos(&head, 2);
    deleteAtEnd(&head);
    deleteAtBeginning(&head);

    // Display the list
    printf("Linked List after deletion: ");
    display(head);

    return 0;
}

// Function to create a new node
Node* createNode(int data) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the beginning 
void insertAtBeginning(Node **head, int data) {
    Node *newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

// Function to insert a node at the end
void insertAtEnd(Node **head, int data) {
    Node *newNode = createNode(data);
    Node *last = *head;

    if(*head == NULL) {
        *head = newNode;
        return;
    }

    while(last->next != NULL)
        last = last->next;

    last->next = newNode;
}

// Function to insert a node at a given position
void insertAtPos(Node **head, int data, int pos) {
    Node *newNode = createNode(data);
    Node *temp = *head;
    int i;

    if(pos == 1) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    for(i = 1; i < pos - 1 && temp != NULL; i++)
        temp = temp->next;

    if(temp == NULL) {
        printf("Position does not exist.\n");
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

// Function to delete a node at the beginning
void deleteAtBeginning(Node **head) {
    Node *temp = *head;

    if(*head == NULL) {
        printf("List empty.\n");
        return;
    }

    *head = (*head)->next;
    free(temp);
}

// Function to delete a node at the end
void deleteAtEnd(Node **head) {
    Node *temp = *head;

    if(*head == NULL) {
        printf("List empty.\n");
        return;
    }

    if((*head)->next == NULL) {
        *head = NULL;
        free(temp);
        return;
    }

    while(temp->next->next != NULL)
        temp = temp->next;

    free(temp->next);
    temp->next = NULL;
}

// Function to delete a node at a given position
void deleteAtPos(Node **head, int pos) {
    Node *temp = *head, *prev;
    int i;

    if(*head == NULL) {
        printf("List empty.\n");
        return;
    }

    if(pos == 1) {
        *head = (*head)->next;
        free(temp);
        return;
    }

    for(i = 1; i < pos && temp != NULL; i++) {
        prev = temp;
        temp = temp->next;
    }

    if(temp == NULL) {
        printf("Position does not exist.\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
}

// Function to display the list
void display(Node *head) {
    Node *temp = head;

    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}