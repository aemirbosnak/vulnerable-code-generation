//Falcon2-11B DATASET v1.0 Category: Linked list operations ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node in the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to initialize a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to add a new node at the beginning of the linked list
void addToHead(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

// Function to add a new node at the end of the linked list
void addToTail(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    struct Node* current = *head;
    while (current->next!= NULL) {
        current = current->next;
    }
    current->next = newNode;
}

// Function to delete a node from the linked list
void deleteNode(struct Node** head, int data) {
    struct Node* current = *head;
    struct Node* prev = NULL;

    while (current!= NULL && current->data!= data) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) {
        return;
    }

    if (prev == NULL) {
        *head = current->next;
        free(current);
    } else {
        prev->next = current->next;
        free(current);
    }
}

// Function to search for a node in the linked list
struct Node* searchNode(struct Node* head, int data) {
    struct Node* current = head;

    while (current!= NULL && current->data!= data) {
        current = current->next;
    }

    return current;
}

int main() {
    struct Node* head = NULL;

    // Create a new linked list
    addToHead(&head, 1);
    addToHead(&head, 2);
    addToHead(&head, 3);
    addToHead(&head, 4);

    // Print the contents of the linked list
    struct Node* current = head;
    while (current!= NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");

    // Delete the second node from the list
    deleteNode(&head, 2);

    // Print the contents of the updated linked list
    current = head;
    while (current!= NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");

    return 0;
}