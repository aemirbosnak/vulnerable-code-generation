//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a node structure for a linked list
typedef struct node {
    int data;
    struct node* next;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory error\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
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

// Function to reverse a linked list
Node* reverseList(Node* head) {
    Node* prev = NULL;
    Node* curr = head;
    while (curr!= NULL) {
        Node* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

// Function to sort a linked list
Node* sortList(Node* head) {
    Node* curr = head;
    while (curr!= NULL && curr->next!= NULL) {
        if (curr->data > curr->next->data) {
            int temp = curr->data;
            curr->data = curr->next->data;
            curr->next->data = temp;
        }
        curr = curr->next;
    }
    return head;
}

// Function to search for a value in a linked list
Node* searchList(Node* head, int value) {
    Node* curr = head;
    while (curr!= NULL) {
        if (curr->data == value) {
            return curr;
        }
        curr = curr->next;
    }
    return NULL;
}

int main() {
    // Example usage
    Node* head = createNode(5);
    head->next = createNode(3);
    head->next->next = createNode(7);
    head->next->next->next = createNode(1);
    head->next->next->next->next = createNode(9);

    printf("Original list:\n");
    printList(head);

    Node* reversed = reverseList(head);
    printf("Reversed list:\n");
    printList(reversed);

    Node* sorted = sortList(head);
    printf("Sorted list:\n");
    printList(sorted);

    Node* found = searchList(head, 7);
    if (found!= NULL) {
        printf("Found %d in the list\n", found->data);
    } else {
        printf("Value not found\n");
    }

    return 0;
}