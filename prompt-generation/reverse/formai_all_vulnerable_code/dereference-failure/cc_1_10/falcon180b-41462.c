//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

// Node structure for linked list
struct Node {
    char data[MAX_SIZE];
    struct Node* next;
};

// Function to create a new node with given data
struct Node* createNode(char* data) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    strcpy(newNode->data, data);
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new node at the end of the list
void insertAtEnd(struct Node** head, char* data) {
    struct Node* newNode = createNode(data);
    struct Node* temp = *head;

    if (*head == NULL) {
        newNode->next = NULL;
        *head = newNode;
        return;
    }

    while (temp->next!= NULL)
        temp = temp->next;

    temp->next = newNode;
    return;
}

// Function to search for a node with given data in the list
struct Node* searchNode(struct Node* head, char* data) {
    struct Node* current = head;

    while (current!= NULL) {
        if (strcmp(current->data, data) == 0)
            return current;
        current = current->next;
    }

    return NULL;
}

// Function to print the list
void printList(struct Node* head) {
    struct Node* temp = head;

    if (head == NULL)
        printf("List is empty\n");
    else {
        printf("List elements are: ");
        while (temp!= NULL) {
            printf("%s ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

// Main function
int main() {
    struct Node* head = NULL;

    // Insert nodes at the end of the list
    insertAtEnd(&head, "apple");
    insertAtEnd(&head, "banana");
    insertAtEnd(&head, "cherry");
    insertAtEnd(&head, "date");

    // Print the list
    printList(head);

    // Search for a node with given data
    struct Node* searchResult = searchNode(head, "banana");

    if (searchResult!= NULL)
        printf("Node found with data: %s\n", searchResult->data);
    else
        printf("Node not found\n");

    return 0;
}