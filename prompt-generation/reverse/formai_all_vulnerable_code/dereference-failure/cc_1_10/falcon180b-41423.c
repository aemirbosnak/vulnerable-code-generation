//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

// Node structure for linked list
typedef struct node {
    char data[MAX_SIZE];
    struct node* next;
} Node;

// Function to create a new node
Node* newNode(char data[]) {
    Node* node = (Node*)malloc(sizeof(Node));
    strcpy(node->data, data);
    node->next = NULL;
    return node;
}

// Function to search for a string in a linked list
Node* search(Node* head, char searchString[]) {
    Node* current = head;
    while (current!= NULL) {
        if (strcmp(current->data, searchString) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

// Function to print a linked list
void printList(Node* head) {
    Node* current = head;
    while (current!= NULL) {
        printf("%s -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// Main function
int main() {
    Node* head = NULL;

    // Adding nodes to the linked list
    head = newNode("apple");
    head->next = newNode("banana");
    head->next->next = newNode("cherry");
    head->next->next->next = newNode("date");

    // Searching for a string in the linked list
    Node* searchResult = search(head, "banana");
    if (searchResult!= NULL) {
        printf("Found 'banana'\n");
    } else {
        printf("Not found\n");
    }

    // Printing the linked list
    printf("Linked list:\n");
    printList(head);

    return 0;
}