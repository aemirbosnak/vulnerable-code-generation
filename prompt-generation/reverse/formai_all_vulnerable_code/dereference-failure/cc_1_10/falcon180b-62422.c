//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

// Node structure for linked list
typedef struct node {
    char data[MAX_SIZE];
    struct node* next;
} Node;

// Function to create a new node with given data
Node* newNode(char* data) {
    Node* node = (Node*)malloc(sizeof(Node));
    strcpy(node->data, data);
    node->next = NULL;
    return node;
}

// Function to insert a new node at the end of the list
void insertNode(Node** head, char* data) {
    Node* node = newNode(data);
    Node* temp = *head;

    if (*head == NULL) {
        *head = node;
        return;
    }

    while (temp->next!= NULL) {
        temp = temp->next;
    }

    temp->next = node;
}

// Function to search for a node with given data in the list
Node* searchNode(Node* head, char* data) {
    Node* temp = head;

    while (temp!= NULL) {
        if (strcmp(temp->data, data) == 0) {
            return temp;
        }
        temp = temp->next;
    }

    return NULL;
}

// Function to print the list
void printList(Node* head) {
    Node* temp = head;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    printf("List: ");
    while (temp!= NULL) {
        printf("%s ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Node* head = NULL;

    // Insert nodes into the list
    insertNode(&head, "apple");
    insertNode(&head, "banana");
    insertNode(&head, "cherry");
    insertNode(&head, "date");
    insertNode(&head, "elderberry");

    // Print the list
    printList(head);

    // Search for a node with given data
    Node* result = searchNode(head, "banana");

    if (result!= NULL) {
        printf("Node found: %s\n", result->data);
    } else {
        printf("Node not found\n");
    }

    return 0;
}