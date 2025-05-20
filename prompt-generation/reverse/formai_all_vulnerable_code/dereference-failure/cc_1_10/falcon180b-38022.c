//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

// Node structure definition
struct node {
    char data;
    struct node* next;
};

// Function to create a new node with the given data
struct node* createNode(char data) {
    struct node* newNode = (struct node*) malloc(sizeof(struct node));
    if (!newNode) {
        printf("Memory error\n");
        exit(0);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to add a node at the end of the list
void addNode(struct node** head, char data) {
    struct node* newNode = createNode(data);
    struct node* last = *head;
    if (*head == NULL) {
        newNode->next = NULL;
        *head = newNode;
        return;
    }
    while (last->next!= NULL)
        last = last->next;
    last->next = newNode;
}

// Function to search for a node with the given data
struct node* searchNode(struct node* head, char data) {
    struct node* current = head;
    while (current!= NULL) {
        if (current->data == data)
            return current;
        current = current->next;
    }
    return NULL;
}

// Function to print the list
void printList(struct node* head) {
    struct node* current = head;
    while (current!= NULL) {
        printf("%c -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// Function to reverse the list
void reverseList(struct node** head) {
    struct node* prev = NULL;
    struct node* next = *head;
    while (next!= NULL) {
        struct node* temp = next->next;
        next->next = prev;
        prev = next;
        next = temp;
    }
    *head = prev;
}

int main() {
    struct node* head = NULL;

    // Add nodes to the list
    addNode(&head, 'A');
    addNode(&head, 'B');
    addNode(&head, 'C');
    addNode(&head, 'D');
    addNode(&head, 'E');

    // Print the original list
    printf("Original list:\n");
    printList(head);

    // Reverse the list
    reverseList(&head);

    // Print the reversed list
    printf("Reversed list:\n");
    printList(head);

    // Search for a node with data 'C'
    struct node* result = searchNode(head, 'C');
    if (result!= NULL)
        printf("Node found with data %c\n", result->data);
    else
        printf("Node not found\n");

    return 0;
}