//Falcon-180B DATASET v1.0 Category: Recursive ; Style: immersive
#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function to create a new node
Node* newNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Function to print a linked list
void printList(Node* head) {
    Node* temp = head;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Function to reverse a linked list using recursion
Node* reverseList(Node* head) {
    if (head == NULL || head->next == NULL)
        return head;

    // Reverse the rest of the list
    Node* rest = reverseList(head->next);

    // Swap the head and the rest
    head->next->next = head;
    head->next = NULL;

    return rest;
}

// Main function
int main() {
    // Create a linked list
    Node* head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(3);
    head->next->next->next = newNode(4);

    // Print the original list
    printf("Original list:\n");
    printList(head);

    // Reverse the list
    Node* reversed = reverseList(head);

    // Print the reversed list
    printf("Reversed list:\n");
    printList(reversed);

    return 0;
}