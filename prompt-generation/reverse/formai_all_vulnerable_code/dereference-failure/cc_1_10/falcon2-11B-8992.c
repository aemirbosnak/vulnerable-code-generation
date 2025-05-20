//Falcon2-11B DATASET v1.0 Category: Memory management ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct to represent a node in a linked list
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Define a function to create a new node with the given data
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Define a function to print the elements of the linked list
void printList(Node* head) {
    Node* current = head;
    while (current!= NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Define a function to reverse the linked list
Node* reverseList(Node* head) {
    Node* prev = NULL;
    Node* current = head;
    Node* next = NULL;

    while (current!= NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    head = prev;

    return head;
}

// Define a function to free the memory allocated for the linked list
void freeList(Node* head) {
    Node* current = head;
    while (current!= NULL) {
        Node* next = current->next;
        free(current);
        current = next;
    }
}

int main() {
    // Create a new linked list
    Node* head = createNode(1);
    Node* second = createNode(2);
    Node* third = createNode(3);

    // Link the nodes together
    head->next = second;
    second->next = third;

    // Print the original linked list
    printf("Original Linked List:\n");
    printList(head);

    // Reverse the linked list
    head = reverseList(head);

    // Print the reversed linked list
    printf("Reversed Linked List:\n");
    printList(head);

    // Free the memory allocated for the linked list
    freeList(head);

    return 0;
}