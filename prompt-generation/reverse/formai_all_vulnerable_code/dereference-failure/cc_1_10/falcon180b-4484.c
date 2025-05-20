//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

// Node structure for linked list
typedef struct node {
    char data[MAX_SIZE];
    struct node* next;
} Node;

// Function to create a new node
Node* createNode(char* data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->data, data);
    newNode->next = NULL;
    return newNode;
}

// Function to print a linked list
void printList(Node* head) {
    Node* curr = head;
    while (curr!= NULL) {
        printf("%s ", curr->data);
        curr = curr->next;
    }
    printf("\n");
}

// Function to search for a string in a linked list
Node* searchList(Node* head, char* searchStr) {
    Node* curr = head;
    while (curr!= NULL) {
        if (strcmp(curr->data, searchStr) == 0) {
            return curr;
        }
        curr = curr->next;
    }
    return NULL;
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

int main() {
    // Create a linked list
    Node* head = NULL;
    head = createNode("apple");
    head->next = createNode("banana");
    head->next->next = createNode("cherry");
    head->next->next->next = createNode("date");

    // Print the original list
    printf("Original list:\n");
    printList(head);

    // Search for a string
    Node* result = searchList(head, "banana");
    if (result!= NULL) {
        printf("Found '%s' in the list.\n", result->data);
    } else {
        printf("'%s' not found in the list.\n", "banana");
    }

    // Reverse the list
    head = reverseList(head);

    // Print the reversed list
    printf("Reversed list:\n");
    printList(head);

    return 0;
}