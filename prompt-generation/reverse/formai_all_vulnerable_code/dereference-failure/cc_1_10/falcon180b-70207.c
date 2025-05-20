//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: shocked
#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the linked list
typedef struct node {
    int data;
    struct node* next;
} Node;

// Function to initialize an empty linked list
void init(Node** head) {
    *head = NULL;
}

// Function to add a node to the end of the linked list
void addNode(Node** head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* temp = *head;
        while (temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to delete a node from the linked list
void deleteNode(Node** head, int data) {
    Node* current = *head;
    Node* prev = NULL;
    while (current!= NULL && current->data!= data) {
        prev = current;
        current = current->next;
    }
    if (current == NULL) {
        printf("Node not found\n");
    } else if (prev == NULL) {
        *head = current->next;
        free(current);
    } else {
        prev->next = current->next;
        free(current);
    }
}

// Function to print the linked list
void printList(Node* head) {
    Node* current = head;
    while (current!= NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Main function to demonstrate the linked list operations
int main() {
    Node* head = NULL;
    init(&head);
    addNode(&head, 5);
    addNode(&head, 10);
    addNode(&head, 15);
    printList(head);
    deleteNode(&head, 10);
    printList(head);
    return 0;
}