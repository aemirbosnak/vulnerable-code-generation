//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

// Node structure for linked list
typedef struct node {
    char data[MAX_SIZE];
    int size;
    struct node *next;
} Node;

// Function to create a new node with given data and size
Node *createNode(char *data, int size) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    strcpy(newNode->data, data);
    newNode->size = size;
    newNode->next = NULL;
    return newNode;
}

// Function to search for a pattern in a linked list of strings
Node *searchPattern(Node *head, char *pattern) {
    Node *currNode = head;
    while (currNode!= NULL) {
        if (strstr(currNode->data, pattern)!= NULL) {
            return currNode;
        }
        currNode = currNode->next;
    }
    return NULL;
}

// Function to print the contents of a linked list
void printList(Node *head) {
    Node *currNode = head;
    while (currNode!= NULL) {
        printf("%s\n", currNode->data);
        currNode = currNode->next;
    }
}

int main() {
    Node *head = NULL;
    char input[MAX_SIZE];

    // Create a linked list of strings
    head = createNode("Hello world", strlen("Hello world"));
    head->next = createNode("Programming is fun", strlen("Programming is fun"));
    head->next->next = createNode("I love coding", strlen("I love coding"));

    // Print the original list
    printf("Original list:\n");
    printList(head);

    // Search for a pattern in the list
    char pattern[MAX_SIZE] = "coding";
    Node *result = searchPattern(head, pattern);

    // Print the result of the search
    if (result!= NULL) {
        printf("Found '%s' in the list:\n", result->data);
        printList(result);
    } else {
        printf("Pattern not found in the list.\n");
    }

    return 0;
}