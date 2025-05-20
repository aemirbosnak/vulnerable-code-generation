//Falcon2-11B DATASET v1.0 Category: Data structures visualization ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>

// Structure definition
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* newNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to print the list
void printList(struct Node* head) {
    struct Node* current = head;
    while (current!= NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Function to reverse a linked list
struct Node* reverseList(struct Node* head) {
    struct Node* prev = NULL;
    struct Node* current = head;
    struct Node* next = NULL;

    while (current!= NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    head = prev;
    return head;
}

// Main function
int main() {
    // Create a new node with data 10
    struct Node* head = newNode(10);

    // Create a new node with data 20
    struct Node* second = newNode(20);

    // Link the second node to the first node
    head->next = second;

    // Create a new node with data 30
    struct Node* third = newNode(30);

    // Link the third node to the second node
    second->next = third;

    // Print the original list
    printf("Original List: ");
    printList(head);

    // Reverse the list
    head = reverseList(head);

    // Print the reversed list
    printf("Reversed List: ");
    printList(head);

    return 0;
}