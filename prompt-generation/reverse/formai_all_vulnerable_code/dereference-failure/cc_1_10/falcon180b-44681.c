//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define node structure
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function prototypes
void addNode(Node** head, int data);
void deleteNode(Node** head, int data);
void printList(Node* head);
void reverseList(Node** head);

int main() {
    Node* head = NULL;

    // Add nodes to list
    addNode(&head, 1);
    addNode(&head, 2);
    addNode(&head, 3);
    addNode(&head, 4);
    addNode(&head, 5);

    // Print original list
    printf("Original List:\n");
    printList(head);

    // Reverse list
    reverseList(&head);

    // Print reversed list
    printf("\nReversed List:\n");
    printList(head);

    // Delete nodes from list
    deleteNode(&head, 1);
    deleteNode(&head, 3);

    // Print updated list
    printf("\nUpdated List:\n");
    printList(head);

    return 0;
}

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

void printList(Node* head) {
    Node* temp = head;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void reverseList(Node** head) {
    Node* prev = NULL;
    Node* next = NULL;
    Node* curr = *head;

    while (curr!= NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    *head = prev;
}