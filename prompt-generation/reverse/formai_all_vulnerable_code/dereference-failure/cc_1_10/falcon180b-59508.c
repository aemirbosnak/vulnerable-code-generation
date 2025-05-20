//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

// Node structure for linked list
typedef struct node {
    char data;
    struct node *next;
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

// Function to print a linked list
void printList(Node* head) {
    Node* temp = head;
    while (temp!= NULL) {
        printf("%c ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Recursive function to search for a character in a linked list
Node* searchRecursive(Node* head, char target) {
    // Base case: empty list
    if (head == NULL) {
        return NULL;
    }

    // Check if target is found at head
    if (head->data == target) {
        return head;
    }

    // Recursive case: search rest of the list
    Node* result = searchRecursive(head->next, target);
    if (result == NULL) {
        return NULL;
    }
    return result;
}

// Function to search for a character in a linked list
Node* search(Node* head, char target) {
    return searchRecursive(head, target);
}

int main() {
    // Test case
    Node* head = NULL;
    head = createNode('a');
    head->next = createNode('b');
    head->next->next = createNode('c');
    head->next->next->next = createNode('d');
    head->next->next->next->next = createNode('e');
    head->next->next->next->next->next = createNode('f');

    char target = 'c';
    Node* result = search(head, target);

    if (result!= NULL) {
        printf("Found %c at position %d\n", result->data, (result - head) + 1);
    } else {
        printf("Not found\n");
    }

    return 0;
}