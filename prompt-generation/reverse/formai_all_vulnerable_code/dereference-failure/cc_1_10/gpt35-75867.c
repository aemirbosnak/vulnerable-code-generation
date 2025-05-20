//FormAI DATASET v1.0 Category: Linked list operations ; Style: happy
#include <stdio.h>
#include <stdlib.h>

// Define the structure for the linked list nodes
struct Node {
    int data;
    struct Node* next;
};

// Create an empty linked list
struct Node* head = NULL;

// Function to insert a node at the beginning of the linked list
void insertAtBeginning(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = head;
    head = newNode;
    printf("Woohoo! Successfully inserted a node at the beginning :)\n");
}

// Function to insert a node at the end of the linked list
void insertAtEnd(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    if (head == NULL) {
        head = newNode;
    } else {
        struct Node* currentNode = head;
        while (currentNode->next != NULL) {
            currentNode = currentNode->next;
        }
        currentNode->next = newNode;
    }
    printf("Yay! Successfully inserted a node at the end :)\n");
}

// Function to delete a node from the beginning of the linked list
void deleteFromBeginning() {
    if (head == NULL) {
        printf("Oops! Linked list is already empty :(\n");
    } else {
        struct Node* tempNode = head;
        head = head->next;
        free(tempNode);
        printf("Woohoo! Successfully deleted a node from the beginning :)\n");
    }
}

// Function to delete a node from the end of the linked list
void deleteFromEnd() {
    if (head == NULL) {
        printf("Oops! Linked list is already empty :(\n");
    } else if (head->next == NULL) {
        struct Node* tempNode = head;
        head = NULL;
        free(tempNode);
        printf("Yay! Successfully deleted a node from the end :)\n");
    } else {
        struct Node* currentNode = head;
        while (currentNode->next->next != NULL) {
            currentNode = currentNode->next;
        }
        struct Node* tempNode = currentNode->next;
        currentNode->next = NULL;
        free(tempNode);
        printf("Woohoo! Successfully deleted a node from the end :)\n");
    }
}

// Function to display the linked list
void displayList() {
    if (head == NULL) {
        printf("Oops! Linked list is empty :(\n");
    } else {
        struct Node* currentNode = head;
        while (currentNode != NULL) {
            printf("%d ", currentNode->data);
            currentNode = currentNode->next;
        }
        printf("\n");
    }
}

int main() {
    // Let's insert some nodes at the beginning and end of the linked list
    printf("Let's insert some nodes at the beginning and end of the linked list...\n");
    insertAtBeginning(1);
    insertAtBeginning(2);
    insertAtEnd(3);
    insertAtEnd(4);
    displayList();

    // Let's delete a node from the beginning and end of the linked list
    printf("Let's delete a node from the beginning and end of the linked list...\n");
    deleteFromBeginning();
    deleteFromEnd();
    displayList();

    // Let's try to delete a node from an empty linked list and insert a node at the beginning of an empty linked list
    printf("Let's try to delete a node from an empty linked list and insert a node at the beginning of an empty linked list...\n");
    deleteFromBeginning();
    insertAtBeginning(5);
    displayList();

    return 0;
}