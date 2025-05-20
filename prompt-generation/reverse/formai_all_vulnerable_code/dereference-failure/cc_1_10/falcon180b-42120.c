//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>

// Define a structure to hold the data for each element in the list
typedef struct {
    int data;
    struct node* next;
} Node;

// Function to insert a new element into the list
void insert(Node** head, int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    Node* currentNode = *head;
    while (currentNode->next!= NULL) {
        currentNode = currentNode->next;
    }
    currentNode->next = newNode;
}

// Function to search for an element in the list
Node* search(Node* head, int data) {
    Node* currentNode = head;
    while (currentNode!= NULL) {
        if (currentNode->data == data) {
            return currentNode;
        }
        currentNode = currentNode->next;
    }
    return NULL;
}

// Function to print the list
void printList(Node* head) {
    Node* currentNode = head;
    while (currentNode!= NULL) {
        printf("%d ", currentNode->data);
        currentNode = currentNode->next;
    }
    printf("\n");
}

// Main function to test the list operations
int main() {
    Node* head = NULL;

    // Insert elements into the list
    insert(&head, 10);
    insert(&head, 20);
    insert(&head, 30);
    insert(&head, 40);

    // Print the list
    printf("List after insertion:\n");
    printList(head);

    // Search for an element in the list
    Node* searchResult = search(head, 30);
    if (searchResult!= NULL) {
        printf("Element found: %d\n", searchResult->data);
    } else {
        printf("Element not found.\n");
    }

    // Free the list memory
    Node* currentNode = head;
    while (currentNode!= NULL) {
        Node* tempNode = currentNode;
        currentNode = currentNode->next;
        free(tempNode);
    }

    return 0;
}