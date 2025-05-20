//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

// Node structure for the linked list
typedef struct node {
    int data;
    struct node* next;
} Node;

// Function to create a new node with the given data
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory error\n");
        exit(0);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to add a node at the end of the list
void addNode(Node** head, int data) {
    Node* newNode = createNode(data);
    Node* temp = *head;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    while (temp->next!= NULL)
        temp = temp->next;

    temp->next = newNode;
}

// Function to search for an element in the list
Node* searchElement(Node* head, int key) {
    Node* current = head;

    while (current!= NULL) {
        if (current->data == key)
            return current;
        current = current->next;
    }

    return NULL;
}

// Function to delete a node with the given key
void deleteNode(Node** head, int key) {
    Node* temp = *head;
    Node* prev = NULL;

    if (temp!= NULL && temp->data == key) {
        *head = temp->next;
        free(temp);
        return;
    }

    while (temp!= NULL && temp->data!= key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
        return;

    prev->next = temp->next;
    free(temp);
}

// Function to print the list
void printList(Node* head) {
    Node* current = head;

    while (current!= NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Main function
int main() {
    Node* head = NULL;

    // Add elements to the list
    addNode(&head, 10);
    addNode(&head, 20);
    addNode(&head, 30);
    addNode(&head, 40);
    addNode(&head, 50);

    // Print the list
    printf("Original list:\n");
    printList(head);

    // Search for an element in the list
    Node* result = searchElement(head, 30);
    if (result!= NULL)
        printf("Element found!\n");
    else
        printf("Element not found.\n");

    // Delete an element from the list
    deleteNode(&head, 20);

    // Print the updated list
    printf("Updated list:\n");
    printList(head);

    return 0;
}