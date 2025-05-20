//Falcon-180B DATASET v1.0 Category: Recursive ; Style: active
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} Node;

// Function to create a new node with the given data
Node* newNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Function to print the linked list
void printList(Node* head) {
    Node* temp = head;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Function to reverse the linked list recursively
Node* reverseList(Node* head) {
    if (head == NULL || head->next == NULL)
        return head;

    Node* rest = reverseList(head->next);
    head->next->next = head;
    head->next = NULL;

    return rest;
}

int main() {
    Node* head = NULL;

    // Create a linked list with 5 nodes
    head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(3);
    head->next->next->next = newNode(4);
    head->next->next->next->next = newNode(5);

    // Print the original linked list
    printf("Original linked list:\n");
    printList(head);

    // Reverse the linked list recursively
    head = reverseList(head);

    // Print the reversed linked list
    printf("Reversed linked list:\n");
    printList(head);

    return 0;
}