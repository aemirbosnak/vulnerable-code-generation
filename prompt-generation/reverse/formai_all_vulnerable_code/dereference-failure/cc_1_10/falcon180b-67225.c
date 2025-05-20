//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Structure for node in linked list
typedef struct node {
    char data;
    struct node* next;
} Node;

// Function to create a new node with given data
Node* createNode(char data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory error\n");
        exit(0);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to add a node at the end of linked list
void addNode(Node** head, char data) {
    Node* newNode = createNode(data);
    Node* temp = *head;
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    while (temp->next!= NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to print linked list
void printList(Node* head) {
    if (head == NULL) {
        printf("Empty list\n");
        return;
    }
    Node* temp = head;
    while (temp!= NULL) {
        printf("%c ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Function to reverse a linked list
void reverseList(Node** head) {
    Node* prev = NULL;
    Node* curr = *head;
    while (curr!= NULL) {
        Node* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    *head = prev;
}

// Function to sort a linked list in ascending order
void sortList(Node** head) {
    Node* temp = *head;
    while (temp!= NULL && temp->next!= NULL) {
        if (tolower(temp->data) > tolower(temp->next->data)) {
            char tempData = temp->data;
            temp->data = temp->next->data;
            temp->next->data = tempData;
        }
        temp = temp->next;
    }
}

int main() {
    // Create linked list with some data
    Node* head = NULL;
    addNode(&head, 'a');
    addNode(&head, 'b');
    addNode(&head, 'c');
    addNode(&head, 'd');
    addNode(&head, 'e');

    // Print original linked list
    printf("Original list:\n");
    printList(head);

    // Reverse linked list
    reverseList(&head);

    // Print reversed linked list
    printf("Reversed list:\n");
    printList(head);

    // Sort linked list in ascending order
    sortList(&head);

    // Print sorted linked list
    printf("Sorted list:\n");
    printList(head);

    return 0;
}