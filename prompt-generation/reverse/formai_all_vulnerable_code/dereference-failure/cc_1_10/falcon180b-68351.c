//Falcon-180B DATASET v1.0 Category: Recursive ; Style: artistic
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function to create a new node with given data
Node* newNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Function to add a node at the end of the list
void addNode(Node** head, int data) {
    Node* node = newNode(data);
    Node* temp = *head;
    if (*head == NULL) {
        node->next = NULL;
        *head = node;
        return;
    }
    while (temp->next!= NULL) {
        temp = temp->next;
    }
    temp->next = node;
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

// Function to reverse the list using recursion
Node* reverseList(Node* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    Node* rest = reverseList(head->next);
    head->next->next = head;
    head->next = NULL;
    return rest;
}

int main() {
    Node* head = NULL;
    addNode(&head, 1);
    addNode(&head, 2);
    addNode(&head, 3);
    addNode(&head, 4);
    addNode(&head, 5);

    printf("Original list:\n");
    printList(head);

    head = reverseList(head);

    printf("Reversed list:\n");
    printList(head);

    return 0;
}